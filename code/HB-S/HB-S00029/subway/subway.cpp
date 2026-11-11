#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+5+500;
const int INF=0x3f3f3f3f;

int n,c,m,q,d,x,y,a[MAXN],dis[MAXN];
bool vis[MAXN];
vector<pair<int,int>> adj[MAXN];

void dijkstra(int s)
{
    memset(dis,INF,sizeof dis);
    memset(vis,0,sizeof vis);
    priority_queue<pair<int,int>> pq;
    dis[s]=0;
    pq.push({-dis[s],s});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(pair<int,int> p:adj[u])
        {
            int v=p.first,w=p.second;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pq.push({-dis[v],v});
            }
        }
    }
}


int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        for(int j=1,v,w;j<=k;j++)
        {
            cin>>v>>w;
            adj[m+i].push_back({v,w});
            adj[v].push_back({m+i,w});
        }
    }
    while(q--)
    {
        cin>>x>>y;
        dijkstra(x);
        cout<<dis[y]+a[y]+a[x]<<endl;
    }
    return 0;
}
