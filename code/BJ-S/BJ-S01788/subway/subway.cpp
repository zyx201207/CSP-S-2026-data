#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn=505;
const int maxm=500005;
struct Edge
{
    int v;
    ll w;
    bool operator < (const Edge &rhs) const
    {
        return w<rhs.w;
    }
};
int c,n,m,d,q;
int k[maxn];
ll w[maxm];
vector<Edge> a[maxm];
vector<Edge> e[maxn];
//dij
//priority_queue<Edge> sq;
ll dis[maxn][maxn];
bool vis[maxn];
void dijkstra(int s)
{
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    int tm=0;
    while(tm<n-1)
    {
        int dv=0;
        ll dm=dis[0][0];
        for(int i=1; i<=n; ++i)
        {
            if(vis[i])
                continue;
            if(dis[s][i]<dm)
            {
                dm=dis[s][i];
                dv=i;
            }
        }
        for(int i=1; i<=n ;++i)
        {
            dis[s][i]=min(dis[s][i],dis[s][dv]+dis[dv][i]);
        }
        vis[dv]=1;
        ++tm;
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1; i<=m; ++i)
        scanf("%lld",&w[i]);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&k[i]);
        for(int j=1; j<=k[i]; ++j)
        {
            int s1;
            ll s2;
            scanf("%d%lld",&s1,&s2);
            Edge neww;
            neww.v=i;
            neww.w=s2;
            a[s1].pb(neww);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1; i<=n; ++i)
        dis[i][i]=0;
    for(int i=1; i<=m; ++i)
    {
        //for(int x=0; x<a[i].size(); ++x)
            //for(int y=0; y<a[i].size(); ++y)//500000*400=2e8;
        for(auto x:a[i])
            for(auto y:a[i])
            {
                if(x.v==y.v)
                    continue;
                dis[x.v][y.v]=min(dis[x.v][y.v],x.w+y.w);
                dis[y.v][x.v]=min(dis[y.v][x.v],x.w+y.w);
            }
    }
    for(int i=1; i<=n; ++i)
    {
        dijkstra(i);
    }
    //warn
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
        {
            if(dis[i][j]<0)
                printf("warn1\n");
            if(dis[i][j]!=dis[j][i])
                printf("warn2\n");
            if(dis[i][j]>=dis[0][0])
                printf("warn3\n");
        }

    for(int i=1; i<=q; ++i)
    {
        ll ans=dis[0][0];
        int s1,s2;
        scanf("%d%d",&s1,&s2);
        for(auto x:a[s1])
            for(auto y:a[s2])
            {
                ans=min(ans,w[s1]+w[s2]+x.w+y.w+dis[x.v][y.v]);
            }
        printf("%lld\n",ans);
    }
}
