#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n, m, f[maxn], dep[maxn];
bool vis[maxn];
vector<int> G[maxn];
void dfs1(int u, int fa)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == fa) continue;
        f[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
    }
}
void dfs(int u)
{
    vis[u] = 0;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (vis[v]) dfs(v);
    }
}
int main ()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int T, C;
    cin >> C >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            G[i].clear();
            f[i] = dep[i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs1(1, -1);
        int ans = 0x3f3f3f3f;
        for (int i = 1; i < (1 << n); i++)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (i & (1 << j - 1))
                {
                    cnt++;
                    vis[j] = 1;
                }
                else vis[j] = 0;
            }
            if (cnt != m) continue;
            cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (vis[j])
                {
                    cnt++;
                    dfs(j);
                }
            }
            if (cnt > 2) continue;
            int Max = 0;
            for (int j = 1; j <= n; j++)
            {
                int Min = 0x3f3f3f3f;
                for (int k = 1; k <= n; k++)
                {
                    if (i & (1 << k - 1))
                    {
                        int x = j, y = k, sum = 0;
                        if (dep[x] > dep[y]) swap(x, y);
                        while (dep[x] < dep[y])
                        {
                            sum++;
                            y = f[y];
                        }
                        while (x != y)
                        {
                            sum += 2;
                            x = f[x];
                            y = f[y];
                        }
                        Min = min(Min, sum);
                    }
                }
                Max = max(Max, Min);
            }
            ans = min(ans, Max);
        }
        cout << ans << '\n';
    }
    return 0;
}
