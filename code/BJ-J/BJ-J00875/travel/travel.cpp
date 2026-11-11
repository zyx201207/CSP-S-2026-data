#include <bits/stdc++.h>
using namespace std;
string c1, c2;
string s1, s2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    int a1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    int a2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    if (c1 == c2) {
        cout << 1;
        if (a1 == a2) {
            cout << 1;
            if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
                cout << 1;
                if (s1[2] <= 'C') {
                    if (abs(s1[2] - s2[2]) == 1)
                        cout << 1;
                    else
                        cout << 0;
                }
                else {
                    cout << 1;
                }
            }
            else
                cout << "00";
        }
        else
            cout << "000";
    }
    else
        cout << "0000";
    return 0;
}
