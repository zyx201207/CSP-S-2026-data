#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int w[N];
int c,n,m,d,q;
struct node{
    int v, w, id;
};
struct edge{
    int to, val;
    bool operator > (const edge ea)const{
        return val > ea.val;
    }
};

vector<node> g[N];
int a[507][N], t[507][N],k[507];
int dis[N];
bool vis[N];
int dijkstra(int s, int r)
{
    priority_queue<edge,vector<edge>, greater<edge> > q;
    memset(dis, 0x3f, sizeof dis);
    q.push({s, 0});
    dis[s] = 0;
    memset(vis, 0, sizeof vis);
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        if (vis[t.to])
            continue;
        vis[t.to] = 1;
        for (auto it : g[t.to])
        {
            if (dis[it.v] > dis[t.to] + it.w)
            {
                dis[it.v] = dis[t.to] + it.w;
                q.push({it.v, dis[it.v]});
            }
        }
    }
    return dis[r];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >>q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // stations to road and road to stations
            g[i].push_back({m + j, t[i][j], i});
            g[m + j].push_back({i, t[i][j], i});
            // xianlu lianjie qita
            for (int t = 1; t <= k[j]; t++)
            {
                g[m + j].push_back({m + a[j][t], 0, i});
            }
        }
    }
    while (q--)
    {
        int st, sr;
        cin >> st >> sr;
        dijkstra(st,sr);
        cout << dis[sr] + w[st] + w[sr] << '\n';
    }
    return 0;
}
