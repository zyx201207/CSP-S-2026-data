#include <bits/stdc++.h>
#define int long long
#define fo(i, a, b) for (int i(a); i <= (b); ++i)
#define dfo(i, a, b) for (int i(a); i >= (b); --i)
#define mod 998244353
#define M 500005
#define N 500005
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
int n, m, a[N], mx[N], ans[N], bj = 1;
inline void solve()
{
    cin >> n >> m;
    fo(i, 1, n)
    {
        cin >> a[i];
        if (i > 1 && a[i] < a[i - 1])
        {
            bj = 0;
        }
        mx[a[i]] = max(mx[a[i]], i);
    }
    if (bj)
    {
        fo(i, 1, m)
        {
            cout << mx[i] << ' ';
        }
        cout << '\n';
        return;
    }
    fo(i, 1, n)
    {
        vector<int> ha;
        int pos = i;
        while (pos <= n)
        {
            pos = mx[a[pos]];
            ha.push_back(a[pos]);
            ++pos;
        }
        for (auto v : ha)
        {
            ans[v]++;
        }
    }
    fo(i, 1, m)
    {
        cout << ans[i] << ' ';
    }
}
signed main()
{
    freopen("card.in", "r", stdin), freopen("card.out", "w", stdout);
    // freopen("card5.in", "r", stdin), freopen("card5.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
        solve();
    return 0;
}