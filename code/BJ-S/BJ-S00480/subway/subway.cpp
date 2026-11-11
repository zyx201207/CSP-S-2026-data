#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
struct Node
{
    ll id, t;
};
int C, n, m, D, q, x, y;
ll e[505][505], w[500005];
vector<Node> v[500005];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> C >> n >> m >> D >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k, a, t;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> a >> t;
            v[a].push_back({i, t});
        }
    }
    memset(e, 0x3f, sizeof(e));
    for (int i = 1; i <= n; i++) e[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (auto j: v[i])
        {
            for (auto k: v[i])
            {
                if (j.id == k.id) continue;
                e[j.id][k.id] = min(e[j.id][k.id], j.t + k.t);
                e[k.id][j.id] = min(e[k.id][j.id], j.t + k.t);
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
    while (q--)
    {
        cin >> x >> y;
        ll ans = 1e18;
        for (auto i: v[x])
        {
            for (auto j: v[y])
            {
                ans = min(ans, w[x] + w[y] + i.t + j.t + e[i.id][j.id]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
