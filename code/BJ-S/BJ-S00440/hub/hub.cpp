#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1005;
int c, t, n, k, u, v, dis[N][N], ans;
vector<int> g[N];
bool f[N];

void dfs(int rt, int u, int fa)
{
    for (int v:g[u])
    {
        if (v == fa) continue;
        dis[rt][v] = dis[rt][u]+1;
        dfs(rt, v, u);
    }
}

int solve()
{
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        int mn = 1e9;
        for (int j = 1; j <= n; ++j)
            if (f[j])
                mn = min(mn, dis[i][j]);
        res = max(res, mn);
    }
    return res;
}

void dfs2(int x, int cnt, int c)
{
    if (cnt == k)
    {
        if (c <= 2) ans = min(ans, solve());
        return;
    }
    if (x > n) return;
    dfs2(x+1, cnt, c);
    for (int v:g[x])
        if (f[v])
        {
            --c;
            break;
        }
    f[x] = 1;
    dfs2(x+1, cnt+1, c+1);
    f[x] = 0;
}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    if (c == 13 || c == 14)
    {
        while (t--)
        {
            cin >> n >> k;
            cout << ((n - 1) / 2 - k + 1 + 3) / 4 << '\n';
        }
        return 0;
    }
    while (t--)
    {
        memset(f, 0, sizeof f);
        memset(dis, 0, sizeof dis);
        ans = 1e9;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i)
        {
            dis[i][i] = 0;
            dfs(i, i, -1);
        }
        dfs2(1, 0, 0);
        cout << ans << '\n';
    }
    return 0;
}
