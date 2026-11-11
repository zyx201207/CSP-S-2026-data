#include <bits/stdc++.h>
#define int long long
#define fo(i, a, b) for (int i(a); i <= (b); ++i)
#define dfo(i, a, b) for (int i(a); i >= (b); --i)
#define mod 998244353
#define M 200005
#define N 200005
using namespace std;
inline int qpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
string c1, s1, c2, s2;
map<char, int> mp;
inline void solve()
{
    mp['A'] = 1, mp['B'] = 2, mp['C'] = 3, mp['D'] = 4, mp['F'] = 5;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1[0] != c2[0] || c1[1] != c2[1])
        cout << "0000\n";
    else
    {
        cout << 1;
        if (s1[1] != s2[1] || s1[0] != s2[0])
            cout << "000\n";
        else
        {
            cout << 1;
            if ((s1[2] == 'D') + (s2[2] == 'F') + (s1[2] == 'F') + (s2[2] == 'D') == 1)
            {
                cout << "00\n";
            }
            else
            {
                cout << 1;
                if (abs(mp[s1[2]] - mp[s2[2]]) == 1)
                    cout << 1;
                else
                    cout << 0;
            }
        }
    }
}
signed main()
{
    freopen("travel.in", "r", stdin), freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
        solve();
    return 0;
}
