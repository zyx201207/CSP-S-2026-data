#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << '1';
        int _s1 = (s1[0] - '0') * 10 + s1[1] - '0', _s2 = (s2[0] - '0') * 10 + s2[1] - '0';
        char __s1 = s1[2], __s2 = s2[2];
        if (_s1 == _s2) {
            cout << '1';
            if ((__s1 <= 'C' && __s2 <= 'C') || (__s1 > 'C' && __s2 > 'C')) {
                cout << '1';
                if (abs((int)(__s1 - __s2)) == 1) {
                    cout << '1';
                } else {
                    cout << '0';
                }
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
//02 01C 02 01D
//1100
