#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool flag1, flag2, flag3, flag4;
int main(void) {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;

    if (c1 == c2) {
        flag1 = true;
    }

    string t1 = s1.substr(0, 2), t2 = s2.substr(0, 2);
    if (flag1 && (t1 == t2)) {
        flag2 = true;
    }

    bool t3 = (s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C');
    bool t4 = (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F');
    if (flag1 && flag2 && (t3 || t4)) {
        flag3 = true;
    }

    if (!(flag1 && flag2 && flag3)) flag4 = 0;
    else if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C')) {
        flag4 = 0;
    }
    else if (abs(int(s1[2]) - int(s2[2])) > 1) flag4 = 0;
    else flag4 = true;

    cout << flag1 << flag2 << flag3 << flag4;
    return 0;
}
