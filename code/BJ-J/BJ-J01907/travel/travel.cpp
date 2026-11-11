#include <bits/stdc++.h>
using namespace std;
int main() {

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char a='0', b='0', c='0', d='0';
    if (c1 == c2) {
        a = '1';
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            b = '1';
            if (s1[2] == 'A') {
                if (s2[2] == 'B') {
                    c = '1';
                    d = '1';
                } else if (s2[2] == 'C') {
                    c = '1';
                }
            } else if (s1[2] == 'B') {
                if (s2[2] == 'A' || s2[2] == 'C') {
                    c = '1';
                    d = '1';
                }
            } else if (s1[2] == 'C') {
                if (s2[2] == 'B') {
                    c = '1';
                    d = '1';
                } else if (s2[2] == 'A') {
                    c = '1';
                }
            } else if (s1[2] == 'D') {
                if (s2[2] == 'F') {
                    c = '1';
                    d = '1';
                }
            } else {
                if (s2[2] == 'D') {
                    c = '1';
                    d = '1';
                }
            }
        }
    }
    cout << a << b << c << d << endl;
    return 0;
}
