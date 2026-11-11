#include <bits/stdc++.h>
#define ll long long
#define INF 40000000000000000

using namespace std;

struct edge
{
    int v;
    ll w;
};

struct quest
{
    int u,v;
};

int c,n,m,d,q;
ll w[500010];
vector <edge> G[500510];
ll dis[500510];
queue <int> Q;
quest qst[100010];
ll ans[100010];

void bfs(int u)
{
    for(int i = 1; i <= m + n; i++)
        dis[i] = INF;

    dis[u] = 0;
    Q.push(u);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        //cout << "now" << u << "\n";
        //cout << "now" << dis[u] << "\n";

        for(edge e : G[u])
        {
            int v = e.v, w = e.w;
            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                Q.push(v);
            }
        }
    }
}

void update()
{
    for(int i = 1; i <= q; i++)
        ans[i] = min(ans[i], dis[qst[i].u] + dis[qst[i].v]);
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> n >> m >> d >> q;

    for(int i = 1; i <= m; i++)
        cin >> w[i];

    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            int v;
            ll w;
            cin >> v >> w;
            G[m + i].push_back({v, w});
            G[v].push_back({m + i, w});
        }
    }

    for(int i = 1; i <= q; i++)
    {
        cin >> qst[i].u >> qst[i].v;
        ans[i] = INF;
    }

    for(int i = 1; i <= n; i++)
    {
        bfs(m + i);
        update();
    }

    for(int i = 1; i <= q; i++)
        cout << ans[i] + w[qst[i].u] + w[qst[i].v] << "\n";

    return 0;
}