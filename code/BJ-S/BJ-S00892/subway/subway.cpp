#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'
#define int long long
#define double long double
#define sqrt sqrtl

const int INF = 9e18;

struct Node
{
    int u, d;
    Node(int _u = -1, int _d = 0): u(_u), d(_d) {}
    bool operator < (const Node &nd) const
    {
        return d > nd.d;
    }
};

int ext[500010], G[510][510], d[510][510];
vector<pair<int, int>> cont[500010];
bool vis[510][510];

void bfs(int s, int n)
{
    memset(d[s], 0x3f, sizeof d[s]);
    d[s][s] = 0;
    priority_queue<Node> q;
    q.push(Node(s, 0));
    while (!q.empty())
    {
        Node nd = q.top();
        q.pop();
        int u = nd.u;
        if (vis[s][u])
        {
            continue;
        }
        vis[s][u] = true;
        for (int v = 1; v <= n; ++v)
        {
            if (d[s][v] > d[s][u] + G[u][v])
            {
                d[s][v] = d[s][u] + G[u][v];
                q.push(Node(v, d[s][v]));
            }
        }
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testid, n, m, capa, q;
    cin >> testid >> n >> m >> capa >> q;
    for (int i = 1; i <= m; ++i)
    {
        cin >> ext[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        while (t--)
        {
            int p, x;
            cin >> p >> x;
            cont[p].push_back({i, x});
        }
    }
    memset(G, 0x3f, sizeof G);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < cont[i].size(); ++j)
        {
            for (int k = j + 1; k < cont[i].size(); ++k)
            {
                G[cont[i][j].first][cont[i][k].first] = min(G[cont[i][j].first][cont[i][k].first], cont[i][j].second + cont[i][k].second);
                G[cont[i][k].first][cont[i][j].first] = G[cont[i][j].first][cont[i][k].first];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        bfs(i, n);
    }
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        int ans = INF;
        for (int i = 0; i < cont[s].size(); ++i)
        {
            for (int j = 0; j < cont[t].size(); ++j)
            {
                ans = min(ans, cont[s][i].second + cont[t][j].second + d[cont[s][i].first][cont[t][j].first]);
            }
        }
        cout << ans + ext[s] + ext[t] << EOL;
    }
    return 0;
}
