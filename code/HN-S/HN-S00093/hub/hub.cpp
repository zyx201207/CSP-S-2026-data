#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lg = 21;
const int N = 1e6 + 5;
vector<int> g[N];
int c, T, n, k, cnt, dfn[N], dep[N], st[lg][N];
struct DSU
{
    int fa[N];
    void init()
    {
        iota(fa + 1, fa + n + 1, 1);
        return;
    }
    int find(int x)
    {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if(x == y) return 0;
        fa[x] = y;
        return 1;
    }
}dsu;
void dfs(int u, int fa)
{
    dfn[u] = ++cnt, dep[u] = dep[fa] + 1, st[0][dfn[u]] = fa;
    for(auto v : g[u])
    {
        if(v == fa) continue;
        dfs(v, u);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    auto get = [&](int u, int v)
    {
        return dep[u] < dep[v] ? u : v;
    };
    auto dis = [&](int u, int v)
    {
        int lca;
        if(u == v) lca = u;
        else 
        {
            int _u = dfn[u], _v = dfn[v];
            if(_u > _v) swap(_u, _v);
            int k = __lg(_v - _u++);
            lca = get(st[k][_u], st[k][_v - (1 << k) + 1]);
        }
        return dep[u] + dep[v] - 2 * dep[lca];
    };
    cin >> c >> T;
    while(T--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1, u, v; i < n; i++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cnt = dep[1] = 0;
        dfs(1, 0);
        for(int j = 1; j < lg; j++)
        {
            for(int i = 1; i + (1 << j) - 1 <= n; st[j][i] = get(st[j - 1][i], st[j - 1][i + (1 << j - 1)]), i++);
        }
        int ans = 1e9;
        for(int mask = 0, full = (1 << n), tot; mask < full; mask++)
        {
            if(__builtin_popcount(mask) != k) continue;
            vector<int> vec;
            tot = k;
            dsu.init();
            for(int i = 1; i <= n; i++)
            {
                if((mask >> i - 1) & 1) 
                {
                    vec.push_back(i);
                    for(auto v : g[i])
                    {
                        if((mask >> v - 1) & 1) tot -= dsu.merge(v, i);
                    }
                }
            }
            if(tot > 2) continue;
            int res = 0;
            for(int i = 1, _res; i <= n; i++)
            {
                _res = 1e9;
                for(auto x : vec) _res = min(_res, dis(i, x));
                res = max(res, _res);
            }
            ans = min(ans, res);
        }
        cout << ans << "\n";
    }
    return 0;
}