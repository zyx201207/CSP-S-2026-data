#include <bits/stdc++.h>
#define int long long
#define rep(i, s, t) for (int i = s; i <= t; i++)
#define pre(i, s, t) for (int i = s; i >= t; i--)
using namespace std;
signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s[4], str = "ABCDF";
    rep(i, 0, 3) cin >> s[i];
    if (s[0] == s[2]) cout << 1;
    else return cout << "0000", 0;
    if (s[1][0] == s[3][0] && s[1][1] == s[3][1]) cout << 1;
    else return cout << "000", 0;
    char A = s[1][2], B = s[3][2];
    if ((A <= 'C' && B <= 'C') || (A > 'C' && B > 'C')) cout << 1;
    else return cout << "00", 0;
    int pa = str.find(A), pb = str.find(B);
    cout << (pa == pb + 1 || pb == pa + 1);
    return 0;
}
/*
D:\GD-J04790\travel.exe
*/