#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4, s5 = "";
bool flag1 = false;
bool flag2 = false;
bool flag3 = false;
bool flag4 = false;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s1 >> s2 >> s3 >> s4;
    if (s1 == s3) {
        s5 += "1";
        if (s2[0] == s4[0] && s2[1] == s4[1]) {
            s5 += "1";
            if ((s2[2] != 'D' && s2[2] != 'F' && s4[2] != 'D' && s4[2] != 'F') || (s2[2] != 'A' && s2[2] != 'B' && s2[2] != 'C' && s4[2] != 'A' && s4[2] != 'B' && s4[2] != 'C')) {
                s5 += "1";
                if ((int)s2[2] == (int)s4[2] + 1 || (int)s2[2] == (int)s4[2] - 1) {
                    s5 += "1";
                } else {
                    flag4 = true;
                }
            } else {
                flag3 = true;
            }
        } else {
            flag2 = true;
        }
    } else {
        flag1 = true;
    }
    cout << s5;
    while (s5.size() != 4) {
        cout << '0';
        s5 += '0';
    }
    return 0;
}
