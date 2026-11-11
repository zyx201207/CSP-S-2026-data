#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
string c1, s1, c2, s2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) cout << "0000\n";
    else if (s1[0] * 10 + s1[1] != s2[0] * 10 + s2[1]) cout << "1000\n";
    else if ((s1[2] <= 'C' && s2[2] >= 'D') || (s2[2] <= 'C' && s1[2] >= 'D')) cout << "1100\n";
    else if (s1[2] == 'A' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'A') cout << "1110\n";
    else cout << "1111\n";
    return 0;
}
