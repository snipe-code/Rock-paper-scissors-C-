#include <iostream>
#include <cstdlib>
#include <ctime>

char getcChoice(char cChoice);
char getpChoice(char pChoice);
void displayChoices(char pChoice, char cChoice);
void getResult(char pChoice, char cChoice, int streak);
bool askPlayAgain(bool playing);

using std::cout;
using std::cin;
int main() {

    bool playing = true;
    int streak = 0;

    while (playing){
        char pChoice = pChoice = getpChoice(pChoice);
        char cChoice = getcChoice(cChoice);

        displayChoices(pChoice, cChoice);

        getResult(pChoice, cChoice, streak);

        playing = askPlayAgain(playing);
    }

    return 0;
}

char getcChoice(char cChoice) {
    srand(time(0));
    int randomNum = rand() % 3 + 1;
    switch (randomNum) {
        case 1:
            cChoice = 'R';
            break;
        case 2:
            cChoice = 'P';
            break;
        case 3:
            cChoice = 'S';
            break;
    }
    return cChoice;
}

char getpChoice(char pChoice) {
    do{
        using std::cout;
        using std::cin;
        cout << "ROCK PAPER SCISSORS\n\n";
        cout << "ROCK = R\n";
        cout << "PAPER = P\n";
        cout << "SCISSORS = S\n\n";
        cout << "Enter your choice: ";
        cin >> pChoice;
        cout << "\n";
    }while(pChoice != 'r' && pChoice != 'R' && pChoice != 'P' && pChoice != 'p' && pChoice != 'S' && pChoice != 's');

    pChoice = toupper(pChoice);

    return pChoice;
}

void displayChoices(char pChoice, char cChoice) {
    cout << "Your choice: " << pChoice << '\n';
    cout << "Computer\'s choice: " << cChoice;
}

void getResult(char pChoice, char cChoice, int streak) {
    if (pChoice == cChoice) {cout << "\n\nIT'S A TIE!\nStreak: " << streak << "\n\n";}
    else if (pChoice == 'R' && cChoice == 'S' ||
             pChoice == 'P' && cChoice == 'R' || 
             pChoice == 'S' && cChoice == 'P') 
             {
                streak++;
                cout << "\n\nYOU WIN!\nStreak: " << streak << "\n\n";
             }

    else {
            streak = 0;
            cout << "\n\nYOU LOSE!\nStreak: " << streak << "\n\n";
         }
    
}

bool askPlayAgain(bool playing) {
    char playAgain;
    cout << "Play again? (Y/N): ";
    cin >> playAgain;
    if(playAgain == 'Y' || playAgain == 'y') {playing = true;}
    else {playing = false;}

    return playing;
};