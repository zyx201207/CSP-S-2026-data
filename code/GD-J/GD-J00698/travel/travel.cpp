#include <bits/stdc++.h>

using namespace std;

const int M = 2e0;
string c[M], s[M];

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0; i <= M - 1; i++) cin >> c[i] >> s[i];
    if (c[0] != c[1]) return cout << "0" << "0" << "0" << "0", 0;
    cout << "1";
    if (s[0][0] != s[1][0] || s[0][1] != s[1][1]) return cout << "0" << "0" << "0", 0;
    cout << "1";
    if ((s[0][2] <= 'C') != (s[1][2] <= 'C')) return cout << "0" << "0", 0;
    return cout << "1" << (abs(s[0][2] - s[1][2]) <= 1 ? "1" : "0"), 0;
}