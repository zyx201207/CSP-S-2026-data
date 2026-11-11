#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
string a_1, a_2, b_1, b_2;
bool check (char a, char b) {
    if ((a >= 'A' && a <= 'C') && (b >= 'A' && b <= 'C')) return true;
    if ((a >= 'D' && a <= 'E') && (b >= 'D' && b <= 'E')) return true;
    return false;
}
bool solve (char a, char b) {
    int numbera = a - 'A';
    int numberb = b - 'A';
    return abs (numbera - numberb) == 1;
}
int main () {
    freopen ("travel.in", "r", stdin);
    freopen ("travel.out", "w", stdout);
    ios :: sync_with_stdio (false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> a_1 >> a_2 >> b_1 >> b_2;
    if (a_1 == b_1) cout << 1;
    else cout << 0;
    if ((a_1 == b_1) && (a_2[0] == b_2[0] && a_2[1] == b_2[1])) cout << 1;
    else cout << 0;
    if ((a_1 == b_1) && (a_2[0] == b_2[0] && a_2[1] == b_2[1]) &&
        check (a_2[2], b_2[2]) == true) cout << 1;
    else cout << 0;
    if ((a_1 == b_1) && (a_2[0] == b_2[0] && a_2[1] == b_2[1]) &&
        check (a_2[2], b_2[2]) == true && solve (a_2[2], b_2[2]) == true)
        cout << 1;
    else cout << 0;
    return 0;
}