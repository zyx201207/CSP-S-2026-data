#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5;
int c,n,m,d,qw;
int r[N];
int p[N];
int k,u[N],w[N];
struct edge{
    int v,w;
};
int st,ed;
vector<edge>e[N];
int dis[N];
int vis[N];
struct node{
    int uu,dis;
    bool operator<(const node& x)const
    {
        return x.dis<dis;
    }
};
priority_queue<node,vector<node>,less<node> >q;
inline void dijkstra(int st)
{
    while(!q.empty())q.pop();
    q.push((node){st,0});
    for(int i=1;i<=m;i++)
    {
        dis[i]=1e17;
        vis[i]=0;
    }
    dis[st]=0;
    while(!q.empty())
    {
        node t=q.top();
        q.pop();
        int uu=t.uu;
        if(vis[uu]==1)continue;
        vis[uu]=1;
        for(int i=0;i<e[uu].size();i++)
        {
            int v=e[uu][i].v;
            int w=e[uu][i].w;
            if(vis[v]==1)continue;
            if(dis[v]>dis[uu]+w)
            {
                dis[v]=dis[uu]+w;
                q.push((node){v,dis[v]});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&qw);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&r[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%lld%lld",&u[j],&w[j]);
            for(int l=1;l<j;l++)
            {
                e[u[l]].push_back((edge){u[j],w[l]+w[j]});
                e[u[j]].push_back((edge){u[l],w[l]+w[j]});
            }
        }
    }
    for(int i=1;i<=qw;i++)
    {
        scanf("%lld%lld",&st,&ed);
        dijkstra(st);
        //for(int j=1;j<=m;j++)cout<<dis[j]<<" ";
        printf("%lld\n",r[st]+r[ed]+dis[ed]);
    }
    return 0;
}
