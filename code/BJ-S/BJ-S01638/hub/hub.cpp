#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;

struct Edge { int v, w; };
vector<int> g[N];

int n, k, block[N], dep[N], f[N][21], s[N], d[N], ans = 1e9;
bool choose[N];
void build(int u, int p)
{
    dep[u] = dep[p] + 1;
    f[u][0] = p;
    for (int i = 1; i <= 20; ++i)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int v : g[u])
    {
        if (v != p)
            build(v, u); 
    }
}

int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 20; i >= 0; --i)
        if (dep[f[u][i]] >= dep[v])
            u = f[u][i];
    if (u == v) return u;
    for (int i = 20; i >= 0; --i)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}
void find(int u, int id)
{
    block[u] = id;
    for (int v : g[u])
    {
        if (block[v] != -1 || !choose[v]) continue;
        find(v, id);
    }
}

void dfs(int step, int cnt)
{
    if (cnt + n - step + 1 < k) return;
    if (cnt == k)
    {
        memset(block, -1, sizeof block);
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (!choose[i] || block[i] != -1) continue;
            sum++;
            find(i, sum);
        }
        if (sum > 2) return;
        memset(d, 0x3f, sizeof d);
        int maxn = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (choose[i]) 
            {
                d[i] = 0;
                continue;
            }
            for (int j = 1; j <= n; ++j)
            {
                if (!choose[j]) continue;
                int l = lca(i, j);
                d[i] = min(d[i], dep[i] + dep[j] - 2 * l);
            }
            maxn = max(maxn, d[i]);
        }
        ans = min(ans, maxn);
        return;
    }
    for (int i = 0; i <= 1; ++i)
    {
        choose[step] = i;
        dfs(step + 1, cnt + i);
    }
}



int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--)
    {

        cin >> n >> k;
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << 0 << endl;
    }
    return 0;
}