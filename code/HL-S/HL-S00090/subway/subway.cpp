#include<bits/stdc++.h>
using namespace std;

#define int long long
constexpr int N = 600;
int c, n, m, d, q, cnt;
int w[500010];
vector<pair<int, int> > g[500010];

int dis[30200], ans[500010], dis2[30010];
bool vis[30010];

struct node
{
    int a, b, ind;
    bool operator<(node s) { return a < s.a; }
} qry[100100];

void bfs(int S)
{
    for (int i = 1; i <= m + n + 1; ++i) vis[i] = 0, dis2[i] = 0;
    queue<pair<int, int> > q;
    q.emplace(S, 0);
    vis[S] = 1;
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        for (auto [to, v] : g[p.first])
        {
            ++cnt;
            if (!vis[to]) dis2[to] = p.second + v, q.emplace(to, dis2[to]), vis[to] = 1;
        }
    }
}

void dj(int S)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > hp;
    hp.emplace(0, S);
    dis[S] = 0;
    while (!hp.empty())
    {
        int p = hp.top().second;
        hp.pop();
        if (vis[p]) continue;
        vis[p] = 1;
        for (auto [to, v] : g[p])
            if (dis[to] > dis[p] + v)
                dis[to] = dis[p] + v, hp.emplace(dis[to], to);
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i)
            cin >> w[i];
    int to, v;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cnt;
        while (cnt--)
        {
            cin >> to >> v;
            g[m + i].emplace_back(to, v);
            g[to].emplace_back(m + i, v);
        }
    }
    for (int i = 1; i <= q; ++i)
        {
            cin >> qry[i].a >> qry[i].b;
            if (qry[i].a > qry[i].b) swap(qry[i].a, qry[i].b);
            qry[i].ind = i;
        }
        sort(qry + 1, qry + q + 1);
    if (c >= 12 && c <= 19)
        for (int i = 1; i <= q; ++i)
        {
            if (qry[i].a != qry[i-1].a)
                bfs(qry[i].a);
            ans[qry[i].ind] = w[qry[i].a] + w[qry[i].b] + dis2[qry[i].b];
        }
    else
    {
        for (int i = 1; i <= q; ++i)
        {
            if (qry[i].a != qry[i-1].a)
                dj(qry[i].a);
            ans[qry[i].ind] = w[qry[i].a] + w[qry[i].b] + dis[qry[i].b];
        }
    }
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << endl;
    return 0;
}