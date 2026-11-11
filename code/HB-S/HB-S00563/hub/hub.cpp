#include <bits/stdc++.h>
using namespace std;

#define gc getchar
inline int rd()
{
    int x = 0, f = 1;
    char c = gc();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = gc();
    }
    while (isdigit(c))
        x = x * 10 + c - '0', c = gc();
    return x * f;
}

const int N = 1000010, inf = 0x7f7f7f7f;
int n, k, fa[N][20], dep[N] = {-1}, f[N], minn, vis[N];
vector<int> vec[N], p;

void init(int u, int f)
{
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for (int i = 1; i < 20; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : vec[u])
        if (v != f)
            init(v, u);
}

int lca(int x, int y)
{
    if (dep[y] > dep[x])
        swap(x, y);
    for (int i = 0, d = dep[x] - dep[y]; d; d >>= 1, i++)
        if (d & 1)
            x = fa[x][i];
    if (x == y)
        return x;
    for (int i = 19; i >= 0 && x != y; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

void check(int x)
{
    vis[x] = 1;
    for (int i : vec[x])
        if (!vis[i] && f[i])
            check(i);
}

void dfs(int cur, int r)
{
    if (!r)
    {
        for (int i = 1; i <= n; i++)
            vis[i] = 0;
        int cnt = 0;
        for (int i : p)
            if (!vis[i])
            {
                check(i), cnt++;
                if (cnt > 2)
                    return;
            }
        int mx = -1, mn;
        for (int i = 1; i <= n; i++)
        {
            if (f[i]) continue;
            mn = inf;
            for (int j : p)
                mn = min(mn, dep[i] + dep[j] - 2 * dep[lca(i, j)]);
            mx = max(mx, mn);
        }
        minn = min(minn, mx);
        return;
    }
    for (int i = cur + 1; i <= n; i++)
    {
        f[i] = 1;
        p.push_back(i);
        dfs(i, r - 1);
        p.pop_back();
        f[i] = 0;
    }
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, T, u, v;
    c = rd(), T = rd();
    while (T--)
    {
        n = rd(), k = rd();
        for (int i = 1; i < n; i++)
        {
            u = rd(), v = rd();
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        init(1, 0);
        minn = inf;
        dfs(0, k);
        printf("%d\n", minn);
        for (int i = 1; i <= n; i++)
            vec[i].clear(), f[i] = 0;
        p.clear();
    }
    return 0;
}