#include <iostream>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, s1n, c2, s2n;
    char s1c, s2c;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    s1n = (s1[0] - '0') * 10 + (s1[1] - '0');
    s1c = s1[2];
    s2n = (s2[0] - '0') * 10 + (s2[1] - '0');
    s2c = s2[2];
    char flag[4] = {'0', '0', '0', '0'};
    if (c1 == c2) {
        flag[0] = '1';
        if (s1n == s2n) {
            flag[1] = '1';
            if ((s1c <= 'C' && s2c <= 'C') || (s1c >= 'D' && s2c >= 'D')) {
                flag[2] = '1';
                if (
                    ((s1c <= 'C' && s2c <= 'C') && abs((int) s1c - (int) s2c) == 1) ||
                    (s1c == 'D' && s2c == 'F') ||
                    (s1c == 'F' && s2c == 'D')
                ) {
                    flag[3] = '1';
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << flag[i];
    }
    return 0;
}
