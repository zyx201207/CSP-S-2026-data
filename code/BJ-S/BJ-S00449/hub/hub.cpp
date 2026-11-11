#include<bits/stdc++.h>
using namespace std;

const int nr = 1e6 + 10;
int n, k, dep[nr]; vector<int> adj[nr];

namespace LCA
{
    const int lr = 25;
    int lg[nr], eu[nr << 1], dep[nr], dfn[nr], st[nr << 1][lr], etot, dtot;
    void dfs(int x, int ft)
    {
        dfn[x] = ++dtot, dep[x] = dep[ft] + 1;
        eu[++etot] = x;
        for (int i = 0; i < adj[x].size(); i++)
            if (adj[x][i] != ft) dfs(adj[x][i], x), eu[++etot] = x;
    }
    void init()
    {
        lg[0] = -1;
        for (int i = 1; i <= n << 1; i++) lg[i] = lg[i >> 1] + 1;
        dtot = etot = 0;
        dfs(1, 0);
        for (int i = 1; i <= etot; i++) st[i][0] = eu[i];
        for (int len = 1; 1 << len <= etot; len++)
            for (int i = 1; i + (1 << len) - 1 <= etot; i++)
                st[i][len] = dep[st[i][len - 1]] < dep[st[i + (1 << len - 1)][len - 1]] ? st[i][len - 1] : st[i + (1 << len - 1)][len - 1];
    }
    int query(int l, int r)
    {
        if (l > r) swap(l, r);
        int z = lg[r - l + 1];
        return dep[st[l][z]] < dep[st[r - (1 << z) + 1][z]] ? st[l][z] : st[r - (1 << z) + 1][z];
    }
    int lca(int x, int y)
    {
        int ex = dfn[x], ey = dfn[y];
        return query(ex, ey);
    }
    int dis(int x, int y)
    {
        int l = lca(x, y);
        return dep[x] + dep[y] - 2 * dep[l];
    }
}

namespace bf
{
    bool vis[nr], in[nr]; int dis[nr];
    void clear()
    {
        for (int i = 1; i <= n; i++) vis[i] = in[i] = false, dis[i] = n;
    }
    void render(int x)
    {
        if (vis[x] || !in[x]) return;
        vis[x] = true;
        for (int i = 0; i < adj[x].size(); i++) render(adj[x][i]);
    }
    void dfs(int x, int ft, int d)
    {
        dis[x] = min(dis[x], d);
        for (int i = 0; i < adj[x].size(); i++)
            if (adj[x][i] != ft) dfs(adj[x][i], x, d + 1);
    }
    void solve()
    {
        int res = n;
        for (int sta = 0; sta < 1 << n; sta++) if (__builtin_popcount(sta) == k)
        {
            clear();
            for (int i = 1; i <= n; i++) if (sta >> i - 1 & 1) in[i] = true;
            int cnt = 0;
            for (int i = 1; i <= n; i++) if (in[i] && !vis[i]) render(i), cnt++;
            if (cnt > 2) continue;
            for (int i = 1; i <= n; i++) if (in[i]) dfs(i, 0, 0);
            int now = 0;
            for (int i = 1; i <= n; i++) now = max(now, dis[i]);
            res = min(res, now);
        }
        cout << res << '\n';
    }

}

namespace poly
{
    int anc[nr], val[nr], mid, dep[nr], dfn[nr], sz[nr], len[nr], dtot;
    void init(int x, int ft)
    {
        dep[x] = dep[ft] + 1;
        for (int i = 0; i < adj[x].size(); i++)
            if (adj[x][i] != ft) init(adj[x][i], x);
    }
    void dfs(int x, int ft)
    {
        len[x] = 0, anc[x] = ft, dfn[x] = ++dtot, sz[x] = 1;
        for (int i = 0; i < adj[x].size(); i++)
            if (adj[x][x] != ft) dfs(adj[x][i], x), sz[x] += sz[adj[x][i]], len[x] = max(len[x], len[adj[x][i]] + 1);
    }
    int dfs2(int x, int ft)
    {
        int sum = 0;
        for (int i = 0; i < adj[x].size(); i++)
            if (adj[x][i] != ft) sum += dfs2(adj[x][i], x);
        sum += len[x] >= mid;
    }
    int calc(int x)
    {
        return dfs2(x, anc[x]) + (len[x] < mid);
    }
    bool check()
    {
        for (int root = 1; root <= n; root++)
        {
            dtot = 0, dfs(root, 0);
            for (int i = 1; i <= n; i++) val[i] = calc(i);
            for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (dfn[i] + sz[i] - 1 < dfn[j] || dfn[j] + sz[j] - 1 < dfn[i])
            {
                int sum = val[i] + val[j]; if (sum > k) continue;
                for (int x = 1; x <= n; x++) if (!(dfn[x] >= dfn[i] && dfn[x] <= dfn[i] + sz[i] - 1) && !(dfn[x] >= dfn[i] && dfn[x] <= dfn[i] + sz[i] - 1))
                    if (max(LCA::dis(x, i), LCA::dis(x, j)) > mid) { sum = k + 1; break; }
                if (sum <= k) return true;
            }
        }
        return false;
    }
    void solve()
    {
        int L = 0, R = 0, Len = 0;
        init(1, 0); for (int i = 1; i <= n; i++) if (dep[i] > dep[L]) L = i;
        init(L, 0); for (int i = 1; i <= n; i++) if (dep[i] > dep[R]) R = i, Len = dep[R] - 1;
        int l = 0, r = Len / 2, res = Len / 2;
        while (l <= r)
        {
            mid = l + r >> 1;
            if (check()) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << res << '\n';
    }
}

namespace k2
{
    void solve()
    {

    }
}

namespace A
{
    void solve()
    {

    }
}

void CLEAR();
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int CASE, T; cin >> CASE >> T;
    while (T--)
    {
        cin >> n >> k;
        CLEAR();
        for (int i = 1; i < n; i++)
        {
            int u, v; cin >> u >> v;
            adj[u].push_back(v), adj[v].push_back(u);
        }
        LCA::init();
        if (CASE <= 3) bf::solve();
    }
    return 0;
}

void CLEAR()
{
    for (int i = 1; i <= n; i++) adj[i].clear();
}
