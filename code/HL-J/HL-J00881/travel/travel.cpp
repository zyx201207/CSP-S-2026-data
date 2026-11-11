#include <iostream>
#include <string>
using namespace std;
int c1, c2, row1, row2;
char seat1, seat2;

void solve() {
    if (c1 == c2) cout << "1";
    else {
        cout << "0000";
        return ;
    }

    if (row1 == row2) cout << "1";
    else {
        cout << "000";
        return ;
    }

    if ( (seat1 == 'A' && seat2 == 'B') || (seat1 == 'B' && seat2 == 'A') ||
        (seat1 == 'B' && seat2 == 'C') || (seat1 == 'C' && seat2 == 'B') ||
        (seat1 == 'A' && seat2 == 'C') || (seat1 == 'C' && seat2 == 'A') ||
        (seat1 == 'D' && seat2 == 'F') || (seat1 == 'F' && seat2 == 'D') ) cout << "1";
    else {
        cout << "00";
        return ;
    }

    if ( (seat1 == 'A' && seat2 == 'B') || (seat1 == 'B' && seat2 == 'A') ||
        (seat1 == 'B' && seat2 == 'C') || (seat1 == 'C' && seat2 == 'B') ||
        (seat1 == 'D' && seat2 == 'F') || (seat1 == 'F' && seat2 == 'D') ) cout << "1";
    else {
        cout << "0";
        return ;
    }

    return ;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);


    cin >> c1 >> row1 >> seat1;
    cin >> c2 >> row2 >> seat2;

    solve();


    fclose(stdin);
    fclose(stdout);
    return 0;
}
