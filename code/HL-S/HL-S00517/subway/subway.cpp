#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q,w[500005],dis[1005][1005],x,y,aaa;
bool vis[1005];
//map<long long,long long>mp[505];
struct Edge
{
    int v,w;
};
struct Node
{
    int pos,dis;
    bool operator<(const Node &x)const{
        return x.dis<dis;
    }
};
vector<Edge>G[600005],g[1005];
struct quest
{
    int i,f,t,ans;
};
vector<quest>vec;
void dij(int s)
{
    memset(vis,0,sizeof vis);
    priority_queue<Node>q;
    q.push({s,0});
    dis[s][s]=0;
    vis[s]=1;
    while(!q.empty())
    {
        Node tp=q.top();q.pop();
        int u=tp.pos;
        vis[u]=1;
        for(Edge e:g[u])
        {
            int v=e.v,w=e.w;
            if(vis[v])continue;
            if(dis[s][v]>dis[s][u]+w)
            {
                dis[s][v]=dis[s][u]+w;
                q.push({v,dis[s][v]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            long long a,t;
            cin>>a>>t;
            for(Edge e:G[a])
            {
                g[i].push_back({e.v-m,t+e.w});
                g[e.v-m].push_back({i,t+e.w});
            }
            G[m+i].push_back({a,t});
            G[a].push_back({m+i,t});

        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)
    {
        dij(i);
    }

    for(int i=1;i<=Q;i++)
    {
        cin>>x>>y;
        long long ans=1e18;
        for(Edge a:G[x])
        {
            for(Edge b:G[y])
            {
                ans=min(ans,dis[a.v-m][b.v-m]+a.w+b.w);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }

    return 0;
}
