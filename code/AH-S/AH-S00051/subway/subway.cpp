#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace usr
{
    const ll N = 5e2 + 5, M = 5e5 + 5;
    vector<array<ll, 2> > g[M];
    ll f[N][N];
    ll w[M];
    ll n, m, d, q;
    void solve(ll cas)
    {
        cin >> n >> m >> d >> q;
        for (int i = 1; i <= m; i++) cin >> w[i];
        memset(f, 0x3f, sizeof f);
        for (int i = 1; i <= n; i++)
        {
            f[i][i] = 0;
            ll k;
            cin >> k;
            while (k--)
            {
                ll v, w;
                cin >> v >> w;
                g[v].push_back({i, w});
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (auto &[u, w1] : g[i])
            {
                for (auto &[v, w2] : g[i])
                {
                    f[u][v] = f[v][u] = min(f[u][v], w1 + w2);
                }
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        while (q--)
        {
            ll x, y;
            cin >> x >> y;
            ll ans = 1e18;
            for (auto &[u, w1] : g[x])
            {
                for (auto &[v, w2] : g[y])
                {
                    ans = min(ans, f[u][v] + w1 + w2);
                }
            }
            cout << ans + w[x] + w[y] << '\n';
        }
    }
    void main()
    {
        freopen("subway.in", "r", stdin);
        freopen("subway.out", "w", stdout);
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        // -Wall -Wextra -fsanitize=address,undefined
        ll T = 1, cas = 0;
        // cin >> T;
        cin >> cas;
        while (T--) solve(cas);
    }
};
int main()
{
    usr::main();
    return 0;
}
/*
直接对每个边枚举d
*/