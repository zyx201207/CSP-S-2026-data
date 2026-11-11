#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int x,d;
    bool friend operator<(node a,node b)
    {
        return a.d>b.d;
    }
};
struct edge
{
    int v,w;
};
int c,m,n,d,q,w[500010],k[510];
vector<edge> g[501010];
int dis[501010],dist[2010][2010];
bool vis[501010];
//厅：1~n 台：n+1~n+m
inline void dijkstra(int s)
{
    for(int i=1;i<=n+m+5;i++)
        dis[i]=1e18,vis[i]=0;
    priority_queue<node> q;
    dis[s]=0;
    q.push({s,0});
    while(!q.empty())
    {
        int x=q.top().x;
        q.pop();
        if(vis[x]) continue;
        vis[x]=true;
        for(auto e:g[x])
        {
            int to=e.v,w=e.w;
            if(dis[to]>dis[x]+w)
            {
                dis[to]=dis[x]+w;
                q.push({to,dis[to]});
            }
        }
    }
}
inline void bfs(int s)
{
    queue<int> q;
    for(int i=1;i<=n+m+5;i++)
        dis[i]=1e18,vis[i]=0;
    dis[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto e:g[x])
        {
            int to=e.v;
            if(vis[to]) continue;
            dis[to]=dis[x]+1;
            vis[to]=true;
            q.push(to);
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    if(c<=11)
    {
        for(int i=1;i<=m;i++)
        {
            cin>>k[i];
            for(int j=1;j<=k[i];j++)
            {
                int a,t;
                cin>>a>>t;
                g[i+n].push_back({a,t});
                g[a].push_back({i+n,t});
            }
        }
        memset(dist,-1,sizeof(dist));
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            if(dist[x][y]==-1)
            {
                dijkstra(x);
                memcpy(dist[x],dis,sizeof(dist[x]));
            }
            cout<<dist[x][y]+w[x]+w[y]<<"\n";
        }
    }
    else if(c<=15)
    {
        int T;
        for(int i=1;i<=m;i++)
        {
            cin>>k[i];
            for(int j=1;j<=k[i];j++)
            {
                int a,t;
                cin>>a>>t;
                T=t;
                g[i+n].push_back({a,1});
                g[a].push_back({i+n,1});
            }
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            bfs(x);
            cout<<dis[y]*T+w[x]+w[y]<<"\n";
        }
    }
    return 0;
}
