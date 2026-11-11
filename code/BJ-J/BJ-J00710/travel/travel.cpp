#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2, r1, r2;
char seat1, seat2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << 1;
        r1 = "  ", r2 = "  ";
        r1[0] = s1[0], r1[1] = s1[1];
        r2[0] = s2[0], r2[1] = s2[1];
        if (r1 == r2) {
            cout << 1;
            seat1 += s1[2];
            seat2 += s2[2];
            if (seat1 <= 'C' && seat2 <= 'C') {
                cout << 1;
                if (seat1 + 1 == seat2 || seat2 + 1 == seat1) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            } else if (seat1 >= 'D' && seat2 >= 'D') {
                cout << 11;
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
    return 0;
}
