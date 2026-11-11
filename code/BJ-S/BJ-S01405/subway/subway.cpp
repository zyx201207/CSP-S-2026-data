#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
    bool operator < (const node &_) const
    {
        if (w != _.w)
            return w > _.w;
        else
            return v > _.v;
    }
};
int c,n,m,d,q,w[20005],k[505],a,t,x,y,vis[20505],dis[20505];
vector<node> e[20505];
priority_queue<node> pq;
void bfs(int st)
{
    for (int i = 1;i <= 20505;i++)
        dis[i] = -1;
    dis[st] = 0;
    queue<int> q1;
    q1.push(st);
    while (q1.size())
    {
        int u = q1.front();
        q1.pop();
        for (int i = 0;i < e[u].size();i++)
        {
            int v = e[u][i].v,w = e[u][i].w;
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + w;
                q1.push(v);
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
        cin >> w[i];
    if (12 <= c && 19 >= c)
    {
        for (int i = 1;i <= n;i++)
        {
            cin >> k[i];
            for (int j = 1;j <= k[i];j++)
            {
                cin >> a >> t;
                e[a].push_back({m + i,t});
                e[m + i].push_back({a,t});
            }
        }
        while (q--)
        {
            cin >> x >> y;
            bfs(x);
            cout << dis[y] + w[x] + w[y] << endl;
        }
        return 0;
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for (int j = 1;j <= k[i];j++)
        {
            cin >> a >> t;
            e[a].push_back({m + i,t});
            e[m + i].push_back({a,t});
        }
    }
    while (q--)
    {
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        cin >> x >> y;
        pq.push({x,0});
        dis[x] = 0;
        while (pq.size())
        {
            node x = pq.top();
            int u = x.v;
            pq.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (int i = 0;i < e[u].size();i++)
            {
                int v = e[u][i].v,w = e[u][i].w;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    pq.push({v,dis[v]});
                }
            }
        }
        cout << dis[y] + w[x] + w[y] << endl;
    }
    return 0;
}
