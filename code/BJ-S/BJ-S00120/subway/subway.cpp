#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int v, w;
    bool operator < (const node &x) const
    {
        return w > x.w;
    }
};
int d[505][505], g[505][505], K[505], ct[500005], q[500005][25],  t[500005][505];
bool vis[505];
int w[500005];
int n;
void dijkstra(int s)
{
    priority_queue<node> q;
    q.push({s, 0});
    memset(vis, 0, sizeof(vis));
    d[s][s] = 0;
    while(!q.empty())
    {
        int u = q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 1; i <= n;i++)
        {
            int v = i;
            if(!vis[v] && (d[s][v] > d[s][u] + g[u][i]))
            {
                d[s][v] = d[s][u] + g[u][i];
                q.push({v, d[s][v]});
            }
        }
    }
    return;
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, m, D, Q;//别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
    cin >> c >> n >> m >> D >> Q;
    for(int i = 1; i <= m;i++) cin >> w[i];
    for(int i = 1; i <= n;i++)
    {
        cin >> K[i];
        for(int j = 1; j <= K[i];j++)
        {
            int x;
            cin >> x;
            cin >> t[x][i];
            ct[x]++;//记录该地铁站在多少层出现过
            q[x][ct[x]] = i;//记录该地铁站被哪几条线路经过
        }
    }
    memset(g, 0x3f, sizeof(g));
    for(int i = 1; i <= n;i++) g[i][i] = 0;
    for(int i = 1; i <= m;i++)
    {
        for(int o1 = 1; o1 < ct[i];o1++)
        {
            for(int o2 = o1 + 1; o2 <= ct[i];o2++)
            {
                int j = q[i][o1], k = q[i][o2];
                g[j][k] = g[k][j] = min(g[j][k], t[i][j] + t[i][k]);
            }
        }
    }
    memset(d, 0x3f, sizeof(d));
    for(int i = 1; i <= n;i++)
    {
        dijkstra(i);
    }
    while(Q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 1e18;
        for(int i = 1; i <= ct[x];i++)
        {
            for(int j = 1; j <= ct[y];j++)
            {
                int xx = q[x][i], yy = q[y][j];
               // cout << xx << " " << yy << endl;
                ans = min(ans, d[xx][yy] + t[x][xx] + t[y][yy]);
            }
        }
        cout << ans + w[x] + w[y] << endl;
    }
    return 0;
}
