#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

int CheckBuy(int &buy) {
    while (buy % 11 != 0) {
        buy--;
    }
}

int Random(int &face1, int &face2) {
    srand(time(NULL));
    face1 = 1 + rand() % 6;
    face2 = 1 + rand() % 6;
    int sum = face1 + face2;
    return sum;
}

void Clear() {
    while (getchar() != '\n');
}

int clean_stdin() 
{
    while (getchar() != '\n') 
	{
    }
    return 1;
}
 
int CheckInt(char message[50], int &input) 
{
    input = 0;
    char c;
    bool check = true;
    do {
        if(!check) {
            printf("It is not is number!\n");
        }
        printf(message);
        check = false;
    } while (((scanf("%d%c", &input, &c) != 2 || c != '\n') && clean_stdin()));
    
    return input;
}


void Menu() {
    printf("Welcome to the Casino. Here are your choices:\n");
    printf("1) Buy chips\n");
    printf("2) Sell chips\n");
    printf("3) Play Craps\n");
    printf("4) Play Arup's Game of Dice\n");
    printf("5) Status report\n");
    printf("6) Quit\n");
}

void BuyChip(int &money, int &chip, int &buy) {
    CheckInt("How much cash do you want to spend for chips?\n", buy);
    if (buy > money || buy < 11) {
        printf("Sorry, You do not have that much money. No chips bought.\n");
    } else {
        CheckBuy(buy);
        chip += buy / 11;
        money -= buy;
    }
}

void SellChip(int &money, int &chip, int &sell) {
    CheckInt("How much chips do you want to sell?\n", sell);
    if (sell > chip) {
        printf("Sorry, You do not have that many chips. No chips sold.\n");
    } else {
        chip -= sell;
        money += sell * 10;
    }
}

void PlayCraps(int &chip) {
    int bet;
    CheckInt("How many chips would you like to bet?\n", bet);
    if (bet > chip) {
        printf("Sorry, that is not allowed. No game player.\n");
    } else {
        chip -= bet;
        char r;
        printf("Press 'r' and hit enter for your first roll.\n");
        //Clear();
        scanf("%c", &r);
        
        if (r == 'r') {
            int face1, face2, sum;
            sum = Random(face1, face2);
            printf("You rolled a %d\n", sum);
            if (sum == 7 || sum == 11) {
                printf("You win!\n");
                chip += bet * 2;
            } else if (sum == 2 || sum == 3 || sum == 12) printf("Sorry, you have lost.\n");
            else {
                int k = sum;
                sum = 0;
                while (sum != k && sum != 7) {
                    printf("Press 'r' and hit enter for your next roll.\n");
                    Clear();
                    scanf("%c", &r);
                    sum = Random(face1, face2);
                    printf("You rolled a %d\n", sum);
                }
                if (sum == k) {
                    chip += bet * 2;
                    printf("You win!\n");
                } else printf("Sorry, you have lost.\n");
            }
        } else {
            chip += bet;
        }
    }
}

void PlayArupGameOfDice(int &chip) {
    int bet;
    CheckInt("How many chips would you like to bet?\n", bet);
    if (bet > chip) {
        printf("Sorry, that is not allowed. No game player.\n");
    } else {
        chip -= bet;
        char r;
        printf("Press 'r' and hit enter for your first roll.\n");
        //Clear();
        scanf("%c", &r);
        if (r == 'r') {
            int face1, face2, sum;
            sum = Random(face1, face2);
            printf("You rolled a %d\n", sum);
            if (sum == 12 || sum == 11) {
                printf("You Win!\n");
                chip += bet * 2;
            } else if (sum == 2) printf("Sorry, you have lost.\n");
            else {
                int k = sum;
                sum = 0;
                printf("Press 'r' and hit enter for your next roll.\n");
                Clear();
                scanf("%c", &r);
                sum = Random(face1, face2);
                printf("You rolled a %d\n", sum);
                if (sum > k) {
                    printf("You win!\n");
                    chip += bet * 2;
                } else printf("Sorry, you have lost.\n");
            }
        } else {
            chip += bet;
        }
    }
}

void StatusReport(int money, int chip) {
    printf("you currently have $%d left and %d chips.\n", money, chip);
}

int main(int argc, char** argv) {
    int choice;
    int money = 1000, chip = 0, buy, sell;
    bool check = true;
    while (check == true) {
        Menu();
        CheckInt("", choice);
        switch (choice) {
            case 1:
            {
                BuyChip(money, chip, buy);
                break;
            }
            case 2:
            {
                SellChip(money, chip, sell);
                break;
            }
            case 3:
            {
                PlayCraps(chip);
                break;
            }
            case 4:
            {
                PlayArupGameOfDice(chip);
                break;
            }
            case 5:
            {
                StatusReport(money, chip);
                break;
            }
            case 6:
            {
                money += chip * 10;
                printf("After selling your chips, have &%d. Thanks for playing!", money);
                check = false;
                break;
            }
            default:
            {
                printf("Sorry, choice number from 1 to 6\n");
            }
        }
    }
    return 0;
}

