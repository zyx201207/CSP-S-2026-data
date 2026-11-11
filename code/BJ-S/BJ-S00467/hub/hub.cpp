#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, k;
vector<int> g[1000001];
long long cpt, cnt;
bool vis[1000001];
void dfs(int x, int fa)
{
    cnt++;
    vis[x] = true;
    for (auto y: g[x])
    {
        if (y == fa) continue;
        if (cpt & (1 << (y-1)))
            dfs(y, x);
    }
}
int dep[1000001];
int f[25][100001];
void init(int x, int fa)
{
    f[0][x] = fa;
    for (auto y: g[x])
    {
        if (y == fa) continue;
        dep[y] = dep[x] + 1;
        init(y, x);
    }
}
int LCA(int x, int y)
{
    if (dep[y] > dep[x]) swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (dep[f[i][x]] > dep[y])
            x = f[i][x];
    if (x == y) return x;
    for (int i = 20; i >= 0; i--)
        if (f[i][x] != f[i][y])
            x = f[i][x],
            y = f[i][x];
    return f[0][x];
}
int d[1000001];
int dis[1000001];

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int _c, _t;
    cin >> _c >> _t;
    while (_t--)
    {
        cin >> n >> k;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dep[1] = 1;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (auto j: g[i])
        //         cout << j << " ";
        //     cout << endl;
        // }
        // return 0;
        init(1, 0);
        for (int i = 1; i <= 20; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = f[i-1][f[i-1][j]];


        int minn = 0;
        for (cpt = 1; cpt <= 1<<n; cpt++)
        {
            memset(vis, 0, sizeof(vis));
            int tmp = 0;
            for (int i = 1; i <= n && tmp < 2; i++)
            {
                if (cpt & (1 << (i-1)) && !vis[i])
                {
                    dfs(i, 0);
                    tmp++;
                }
            }
            long long t = cpt;
            int c = 0;
            while (t)
            {
                c += t&1;
                t >>= 1;
            }
            if (c == cnt && tmp <= 2)
            {
                for (int i = 1; i <= n; i++)
                {
                    if (cpt & (1<<(i-1)))
                    {
                        d[i] = 0;
                        for (int j = 1; j <= n; j++)
                        {
                            if (i == j) continue;
                            int lca = LCA(i, j);
                            d[j] = min(d[j], dep[i] + dep[j] - 2 * dep[lca]);
                        }
                    }
                }
                int maxn = 0;
                for (int i = 1; i <= n; i++)
                    maxn = max(maxn, d[i]);
                minn = min(minn, maxn);
            }
        }
        cout << minn << endl;
        for (int i = 1; i <= n; i++)
            g[i].clear();
    }
    return 0;
}