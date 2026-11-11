#include <bits/stdc++.h>
using namespace std;

int c1, s1n, c2, s2n;
char s1c, s2c;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin >> c1 >> s1n >> s1c >> c2 >> s2n >> s2c;

    if (c1 == c2)
        cout << 1;
    else
        cout << 0;

    if (s1n == s2n && c1 == c2)
        cout << 1;
    else
        cout << 0;

    if (s1n == s2n && c1 == c2 && (s1c >= 'D' && s2c >= 'D' || s1c < 'D' && s2c < 'D'))
        cout << 1;
    else
        cout << 0;

    if (s1n == s2n && c1 == c2 && (s1c >= 'D' && s2c >= 'D' || s1c < 'D' && s2c < 'D') && max(s1c, s2c) - 1 == min(s1c, s2c))
        cout << 1;
    else
        cout << 0;
    return 0;
}