#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int num1 = 0, num2 = 0;
    for (int i = 0; i < s1.size() - 1; ++i) {
        num1 = num1 * 10 + (s1[i] - '0');
    }
    for (int i = 0; i < s2.size() - 1; ++i) {
        num2 = num2 * 10 + (s2[i] - '0');
    }
    if (c1 == c2) {
        cout << 1;
        if (num1 == num2) {
            cout << 1;
            char ch1 = s1[s1.size() - 1], ch2 = s2[s2.size() - 1];
            if ((ch1 >= 'A' && ch1 <= 'C' && ch2 >= 'A' && ch2 <= 'C') || ((ch1 == 'D' || ch1 == 'F') && (ch2 == 'D' || ch2 == 'F'))) {
                cout << 1;
                if ((ch1 == 'A' && ch2 == 'C') || (ch1 == 'C' && ch2 == 'A')) {
                    cout << 0;
                } else {
                    cout << 1;
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
