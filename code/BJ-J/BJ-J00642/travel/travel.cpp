#include <bits/stdc++.h>
using namespace std;
int c1, c2, s1, s2, x1, x2;
string S01, S02;
int change(char x) {
    if (x == 'A') return 1;
    if (x == 'B') return 2;
    if (x == 'C') return 3;
    if (x == 'D') return 11;
    return 12;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> S01 >> c2 >> S02;
    s1 = (S01[0] - '0') * 10 + (S01[1] - '0'), s2 = (S02[0] - '0') * 10 + (S02[1] - '0');
    x1 = change(S01[2]), x2 = change(S02[2]);
    if (c1 != c2) cout << "0000";
    else if (s1 != s2) cout << "1000";
    else if (x1 < 10 && x2 > 10 || x1 > 10 && x2 < 10) cout << "1100";
    else if (abs(x1 - x2) > 1) cout << "1110";
    else cout << "1111";
    return 0;
}
