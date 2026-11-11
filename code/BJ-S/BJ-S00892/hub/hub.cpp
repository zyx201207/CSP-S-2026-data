#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'
#define int long long
#define double long double
#define sqrt sqrtl

const int INF = 9e18;

struct Graph
{
    int to[200010], nxt[200010], pos[100010], tot;
    Graph(): tot(0) {}
    void init(int siz)
    {
        fill(pos + 1, pos + siz + 1, 0);
    }
    void AddEdge(int u, int v)
    {
        ++tot;
        to[tot] = v;
        nxt[tot] = pos[u];
        pos[u] = tot;
    }
    void NewEdge(int u, int v)
    {
        AddEdge(u, v);
        AddEdge(v, u);
    }
};

Graph G;
int pa[100010][30], dep[100010];

void initLCA(int u)
{
    dep[u] = dep[pa[u][0]] + 1;
    for (int k = 1; ; ++k)
    {
        pa[u][k] = pa[pa[u][k - 1]][k - 1];
        if (!pa[u][k])
        {
            break;
        }
    }
    for (int eid = G.pos[u]; eid; eid = G.nxt[eid])
    {
        int v = G.to[eid];
        if (v == pa[u][0])
        {
            continue;
        }
        pa[v][0] = u;
        initLCA(v);
    }
}

int getLCA(int u, int v)
{
    if (dep[u] < dep[v])
    {
        swap(u, v);
    }
    for (int k = 20; k >= 0; --k)
    {
        if (dep[pa[u][k]] < dep[v])
        {
            continue;
        }
        u = pa[u][k];
    }
    if (u == v)
    {
        return u;
    }
    for (int k = 20; k >= 0; --k)
    {
        if (pa[u][k] == pa[v][k])
        {
            continue;
        }
        u = pa[u][k];
        v = pa[v][k];
    }
    return pa[u][0];
}

void solve()
{
    int n, k;
    cin >> n >> k;
    G.init(n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        G.AddEdge(u, v);
    }
    for (int i = 1; i <= n; ++i)
    {
        fill(pa[i] + 1, pa[i] + 21, 0);
    }
    initLCA(1);
    int ans = INF;
    for (int sta = 1; sta < (1 << n); ++sta)
    {
        vector<int> vec;
        for (int i = 1; i <= n; ++i)
        {
            if (sta & (1 << n - i))
            {
                vec.push_back(i);
            }
        }
        if (vec.size() != k)
        {
            continue;
        }
        int cnt = k;
        for (int u: vec)
        {
            for (int eid = G.pos[u]; eid; eid = G.nxt[eid])
            {
                int v = G.to[eid];
                cnt -= (u < v && (sta & (1 << n - v)));
            }
        }
        if (cnt > 2)
        {
            continue;
        }
        int now = 0;
        for (int i = 1; i <= n; ++i)
        {
            int tmp = INF;
            for (int j: vec)
            {
                tmp = min(tmp, dep[i] + dep[j] - (dep[getLCA(i, j)] << 1));
            }
            now = max(now, tmp);
        }
        ans = min(ans, now);
    }
    cout << ans << EOL;
}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c, T;
    cin >> c >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
