#include<bits/stdc++.h>
using namespace std;
const long long N=510,M=5e5+10,inf=0x3f3f3f3f3f3f3f3f;
struct node
{
    long long v,w;
};
struct point
{
    long long u,x;
    bool operator < (const point opt) const
    {
        return x>opt.x;
    }
};
struct station
{
    long long sub_id,sub_time;
};
long long c,n,m,d,q,w[M],dis[N+M],dis_sub[N][N],tot;
bool vis[N+M];
long long u,v,val,k,ai,ti,x,y,ans,sub_p,sub_q;
vector<node> adj[N+M];
vector<station> f[M];
void dijkstra(long long s)
{
    for(int i=1;i<=tot;i++) dis[i]=inf;
    for(int i=1;i<=tot;i++) vis[i]=false;
    priority_queue<point> q;
    q.push(point{s,0});
    dis[s]=0;
    while(!q.empty())
    {
        u=q.top().u;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0;i<adj[u].size();i++)
        {
            v=adj[u][i].v,val=adj[u][i].w;
            if(dis[v]>dis[u]+val)
            {
                dis[v]=dis[u]+val;
                q.push(point{v,dis[v]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k);
        while(k--)
        {
            scanf("%lld%lld",&ai,&ti);
            f[ai].push_back(station{i,ti});
        }
    }
    tot=n;
    for(int i=1;i<=m;i++)
    {
        if(f[i].size()<=1) continue;
        tot++;
        for(int j=0;j<f[i].size();j++)
        {
            adj[tot].push_back(node{f[i][j].sub_id,f[i][j].sub_time});
            adj[f[i][j].sub_id].push_back(node{tot,f[i][j].sub_time});
        }
    }
    for(int i=1;i<=n;i++)
    {
        dijkstra(i);
        for(int j=1;j<=n;j++) dis_sub[i][j]=dis[j];
    }
    while(q--)
    {
        ans=inf;
        scanf("%lld%lld",&x,&y);
        for(int i=0;i<f[x].size();i++)
        {
            for(int j=0;j<f[y].size();j++)
            {
                sub_p=f[x][i].sub_id,sub_q=f[y][j].sub_id;
                ans=min(ans,dis_sub[sub_p][sub_q]+f[x][i].sub_time+f[y][j].sub_time);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
