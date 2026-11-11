#include <bits/stdc++.h>
using namespace std;

int x, y;
string s1, s2;
bool f1, f2, f3, f4;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> x >> s1 >> y >> s2;
    if (x == y) f1 = 1;
    if (f1 && s1[0] == s2[0] && s1[1] == s2[1]) f2 = 1;
    int m = int(s1[2] - 'A') + 1, n = int(s2[2] - 'A') + 1;
    if (f1 && f2 && ((m <= 3 && n <= 3) || (m >= 4 && n >= 4))) f3 = 1;
    if (f1 && f2 && f3 && abs(m - n) == 1) f4 = 1;
    cout << f1 << f2 << f3 << f4 << '\n';
    return 0;
}