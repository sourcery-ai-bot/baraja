#include <string.h>
// Equivalent of baraja.py implementation of classes Naipe, Baraja
// shuffle algorithm: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
// compiles with: g++ juego_en.cpp
// checkout https://www.boost.org/doc/libs/1_72_0/libs/multi_index/example/rearrange.cpp


const int DECK_SIZE = 52;

class Naipe {
    private:
// Internally implemented as just an int value 
// 0 <= naipe <= 51 
// 0 = AS, 13 = AH, 26 = AC, 39 = AD, 51 = KD 
        int naipe;
    public:
        Naipe(int N) { naipe = N; }; //TODO add an assert 0<=N<=51
        int numero() { return (naipe)%13 + 1; };
        int palo() { return naipe/13; };

        std::string numero_char();
        std::string palo_char(); 
        std::string repr() { return (this->numero_char()).append(this->palo_char()); };
};

std::string Naipe::numero_char() {
    switch (int val = this->numero()) {
        case 1:
            return "A";
        case 11:
            return "J";
        case 12:
            return "Q";
        case 13:
            return "K";
        default: 
            return std::to_string(val);
    }};

std::string Naipe::palo_char() {
    switch (int val = this->palo()) {
        case 0:
            return "S"; // Spades
        case 1:
            return "H"; // Hearts
        case 2:
            return "C"; // Clovers
        case 3:
            return "D"; // Diamonds
        default: 
            return std::to_string(val); // this should not be reached TODO: raise error
    }};
