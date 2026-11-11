#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 1e9, f[105], l[105][105], fa[105][20], dep[105];
vector<int> g[105];

void dfs(int u, int ft)
{
    fa[u][0] = ft, dep[u] = dep[ft] + 1;
    for (auto v : g[u])
        if (v != ft) dfs(v, u);
}

int lca(int x, int y)
{
    if (dep[x] < dep[y]) swap(x, y);
    for (int k = log2(n); k >= 0; k--)
        if (dep[x] - (1 << k) >= dep[y]) x = fa[x][k];
    if (x == y) return x;
    for (int k = log2(n); k >= 0; k--)
        if (fa[x][k] != fa[y][k]) x = fa[x][k], y = fa[y][k];
    return fa[x][0];
}

void dfs2(int x, int y)
{
    if (y > n || x >= k)
    {
        if (x >= k)
        {
            int mx = 0;
            for (int i = 1; i <= n; i++)
            {
                if (f[i]) continue;
                int mn = 1e9;
                for (int j = 1; j <= n; j++)
                {
                    if (!f[j]) continue;
                    mn = min(mn, dep[i] + dep[j] - 2 * dep[l[i][j]]);
                }
                mx = max(mx, mn);
            }
            ans = min(ans, mx);
        }
        return ;
    }
    for (int i = y; i <= n; i++)
    {
        dfs2(x, y + 1);
        f[i] = 1;
        dfs2(x + 1, y + 1);
        f[i] = 0;
    }
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        memset(dep, 0, sizeof(dep));
        memset(fa, 0, sizeof(fa));
        for (int i = 1; i <= n; i++) g[i].clear();
        ans = 1e9;
        cin >> n >> k;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v), g[v].push_back(u);
        }
        dfs(1, 0);
        for (int k = 1; k <= log2(n); k++)
            for (int i = 1; i <= n; i++) fa[i][k] = fa[fa[i][k - 1]][k - 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) l[i][j] = lca(i, j);
        dfs2(0, 1);
        cout << ans << '\n';
    }
}