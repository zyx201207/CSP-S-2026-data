#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Edge
{
    int to,w;
};
vector<Edge>g[2000001];
int dis[2000001];
bool vis[2000001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
void dijkstra(int s)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    pq.push({0,s});
    dis[s]=0;
    vis[s]=1;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(auto i:g[u])
        {
            int v=i.to,w=i.w;
            if(vis[v])continue;
            vis[v]=1;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}
int w[500001];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int cnt=m;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int t=cnt;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            cnt++;
            g[a].push_back({cnt,t});
            g[cnt].push_back({a,t});
        }
        for(int j=t+2;j<=cnt;j++)
        {
            g[j].push_back({j-1,0});
            g[j-1].push_back({j,0});
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        dijkstra(x);
        cout<<dis[y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
