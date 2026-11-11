#include <bits/stdc++.h>
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

const int MAXN = 1e6 + 10;

int n, K;
vector <int> e[MAXN];

int fa[MAXN], rt, dep[MAXN], clk;
void dfs(int u, int t)
{
    dep[u] = dep[t] + 1, fa[u] = t;
    if (dep[u] > dep[rt]) rt = u;
    for (auto v : e[u]) if (v ^ t) dfs(v, u);
}
void relabel(int u, int t)
{
    dep[u] = ++clk, fa[dep[u]] = dep[t];
    for (auto v : e[u]) if (v ^ t) relabel(v, u);
}
inline int findrt()
{
    rt = 0, dfs(1, 0), dfs(rt, 0);
    int ret = dep[rt] - 1 >> 1;
    for (int i = ret; i; i--) rt = fa[rt];
    clk = 0, relabel(rt, 0), assert(clk == n);
    return ret;
}

int ht[MAXN], dis[MAXN], deg[MAXN], to[MAXN][2];
bool vis[MAXN], avl[MAXN];
int idx[MAXN], lft[MAXN];
inline bool check(int d)
{
    for (int i = 1; i <= n; i++) vis[i] = (ht[i] >= d), dis[i] = deg[i] = to[i][0] = to[i][1] = 0, avl[i] = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) dis[fa[i]] = max(dis[fa[i]], ht[i] + 1);
    for (int i = 2; i <= n; i++) if (vis[i]) deg[i]++, deg[fa[i]]++;
    for (int i = 2; i <= n; i++) if (vis[i])
    {
        if (deg[i] == 2) to[i][!!to[i][0]] = fa[i];
        if (deg[fa[i]] == 2) to[fa[i]][!!to[fa[i]][0]] = i;
    }
    int tot = accumulate(vis + 1, vis + n + 1, 0), mn = tot;
    for (int o = 1; o <= n; o++) if (vis[o] && deg[o] == 2 && !avl[o])
    {
        int u = to[o][0], v, w = o;
        while (deg[u] == 2) swap(u, w), u = to[w][to[w][0] == u];
        int m = 1; idx[0] = u, idx[1] = w;
        while (deg[idx[m]] == 2) idx[m + 1] = to[idx[m]][to[idx[m]][0] == idx[m - 1]], m++; m--;
        for (int i = 1; i <= m; i++) avl[idx[i]] = 1, lft[i] = 0;
        for (int i = 1; i <= m; i++)
            if (i - d + dis[idx[i]] > 0 && i + d - dis[idx[i]] <= m)
                lft[i + d - dis[idx[i]]] = max(lft[i + d - dis[idx[i]]], i - d + dis[idx[i]]);
        int l = 0, mx = 0;
        for (int i = 1; i <= m; i++)
            if (lft[i] > l) mx = max(mx, i - l - 1), l = lft[i];
        mx = max(mx, m - l), mn = min(mn, tot - mx);
    }
    return mn <= K;
}

int main()
{
    // int st = clock();
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int cid, T; cin >> cid >> T;
    while (T--)
    {
        cin >> n >> K;
        for (int i = 1; i <= n; i++) e[i].clear(), ht[i] = 0;
        for (int i = 1, u, v; i < n; i++) cin >> u >> v, e[u].emplace_back(v), e[v].emplace_back(u);
        int l = 0, r = findrt(), mid;
        for (int i = n; i > 1; i--) ht[fa[i]] = max(ht[fa[i]], ht[i] + 1);
        while (l <= r)
        {
            mid = l + r >> 1;
            if (check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        cout << r + 1 << '\n';
    }
    // cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << '\n';
    return 0;
}