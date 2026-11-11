#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M1=2e4+5,M2=5e5+5,N=505;
ll w[M2];
struct node
{
    int v;
    ll w;
};
int c,n,m,d,q;
vector<node >adj[N+M2];
vector<int> dist_bfs[N];
ll dist[N][N+M1],dis[3][N+M2];
bool st[N+M2];
void dijkstra(int s)
{
    for(int i=1;i<=n+m;i++) dist[s][i]=1e15;
    for(int i=1;i<=n+m;i++) st[i]=0;
    dist[s][m+s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>> > pq;
    pq.push({0,m+s});
    while(!pq.empty())
    {
        auto cur=pq.top();
        pq.pop();
        if(st[cur.second]) continue;
        st[cur.second]=1;
        for(auto e:adj[cur.second])
        {
            if(dist[s][e.v]>dist[s][cur.second]+e.w)
            {
                dist[s][e.v]=dist[s][cur.second]+e.w;
                pq.push({dist[s][e.v],e.v});
            }
        }
    }
    return ;
}
void dijkstra1(int s)
{
    for(int i=1;i<=n+m;i++) dis[s][i]=1e15;
    for(int i=1;i<=n+m;i++) st[i]=0;
    dis[s][m+s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>> > pq;
    pq.push({0,m+s});
    while(!pq.empty())
    {
        auto cur=pq.top();
        pq.pop();
        if(st[cur.second]) continue;
        st[cur.second]=1;
        for(auto e:adj[cur.second])
        {
            if(dis[s][e.v]>dis[s][cur.second]+e.w)
            {
                dis[s][e.v]=dis[s][cur.second]+e.w;
                pq.push({dis[s][e.v],e.v});
            }
        }
    }
    return ;
}
void bfs(int s)
{
    queue<int> q;
    q.push(m+s);
    for(int i=1;i<=n+m;i++) dist_bfs[s][i]=-1;
    dist_bfs[s][m+s]=0;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto e:adj[cur])
        {
            if(dist_bfs[s][e.v]==-1)
            {
                dist_bfs[s][e.v]=dist_bfs[s][cur]+1;
                q.push(e.v);
            }
        }
    }
    return ;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    ll T=-1;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a;ll t;
            cin>>a>>t;
            T=t;
            adj[m+i].push_back({a,t});
            adj[a].push_back({m+i,t});
        }
    }
    if(c<=11)
    {
        for(int i=1;i<=n;i++) dijkstra(i);
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            ll ans=9e18;
            for(int j=1;j<=n;j++) ans=min(ans,dist[j][x]+dist[j][y]);
            cout<<ans+w[x]+w[y]<<"\n";
        }
    }
    else if(c==20||c==21)
    {
        for(int i=1;i<=n;i++) dijkstra1(i);
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            ll ans=9e18;
            for(int j=1;j<=n;j++) ans=min(ans,dis[j][x]+dis[j][y]);
            cout<<ans+w[x]+w[y]<<"\n";
        }
    }
    else if(12<=c&&c<=19)
    {
        for(int i=1;i<=n;i++)
        {
            dist_bfs[i].resize(n+m+1);
            bfs(i);
        }
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            ll ans=9e18;
            for(int j=1;j<=n;j++) ans=min(ans,1ll*(dist_bfs[j][x]+dist_bfs[j][y]));
            cout<<T*ans+w[x]+w[y]<<"\n";
        }
    }
    return 0;
}
