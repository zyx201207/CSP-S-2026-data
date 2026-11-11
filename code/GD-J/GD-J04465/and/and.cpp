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
int n, m, ans, a[N];
inline void solve()
{
    cin >> n >> m;
    fo(i, 1, n) cin >> a[i];
    vector<int> gg;
    fo(i, 1, n) gg.push_back(i);
    dfo(i, 30, 0)
    {
        int num = 0;
        for (auto v : gg)
        {
            if ((a[v] >> i) & 1)
            {
                ++num;
            }
        }
        if (num < m)
            continue;
        vector<int> nw;
        for (auto v : gg)
        {
            if ((a[v] >> i) & 1)
            {
                nw.push_back(v);
            }
        }
        gg = nw;
        vector<int>().swap(nw);
        ans += (1ll << i);
    }
    cout << ans << '\n';
}
signed main()
{
    freopen("and.in", "r", stdin), freopen("and.out", "w", stdout);
    // freopen("and5.in", "r", stdin), freopen("and5.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--)
        solve();
    return 0;
}