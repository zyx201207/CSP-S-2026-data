#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int g[505][500005];
int dis[505][505],ds[1005][1005],p[500005];
bool vis[500005];
vector<int> v[500005],w[500005];
struct node
{
    int v,w;
};
bool operator > (node x,node y)
{
    return x.w<y.w;
}
priority_queue<node,vector<node>,greater<node>> pq;

void dijkstra(int s)
{
    for(int i = 1; i<=m; i++) ds[s][i]=0x3f3f3f3f3f3f3f3f;
    memset(vis,0,sizeof vis);
    ds[s][s]=0;
    //vis[s]=1;
    pq.push({s,0});
    while(!pq.empty())
    {
        int u=pq.top().v;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i = 0; i<v[u].size(); i++)
        {
            int vi=v[u][i],wi=w[u][i];
            if(ds[s][u]+wi<ds[s][vi]&&!vis[vi])
            {
                ds[s][vi]=ds[s][u]+wi;
                pq.push({vi,ds[s][vi]});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(g,0x3f,sizeof g);
    memset(dis,0x3f,sizeof dis);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1; i<=m; i++)
    {
        scanf("%lld",p+i);
    }
    if(c==9||c==10||c==11)
    {
        for(int i = 1; i<=n; i++)
        {

            int temp;
            scanf("%lld",&temp);
            if(temp==2)
            {
                int x,y,z1,z2;
                scanf("%lld%lld%lld%lld",&x,&z1,&y,&z2);
                v[x].push_back(y);
                v[y].push_back(x);
                w[x].push_back(z1+z2);
                w[y].push_back(z1+z2);
            }
            else{
                for(int j = 1; j<=temp; j++)
                {
                    int abcd,efgh;
                    scanf("%lld%lld",&abcd,&efgh);
                }
            }
        }
        for(int i = 1; i<=m; i++)
        {
            dijkstra(i);
        }
        while(q--)
        {
            int l,r;
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",ds[l][r]+p[l]+p[r]);
        }
        return 0;
    }
    for(int i = 1; i<=n; i++)
    {
        int temp;
        scanf("%lld",&temp);
        for(int j = 1; j<=temp; j++)
        {
            int a,t;
            scanf("%lld%lld",&a,&t);
            g[i][a]=t;
        }
    }
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            for(int k = 1; k<=m; k++)
            {
                dis[i][j]=min(dis[i][j],g[i][k]+g[j][k]);
            }
        }
    }
    for(int i = 1; i<=n; i++) dis[i][i]=0;
    for(int i = 1; i<=n; i++)
    {
        for(int j = i; j<=n; j++)
        {

            for(int k = 1; k<=n; k++)
            {
                dis[i][j]=min(dis[min(i,k)][max(i,k)]+dis[min(j,k)][max(j,k)],dis[i][j]);
            }
        }
    }
    while(q--)
    {
        int l,r,ans=0x3f3f3f3f3f3f3f3f;
        scanf("%lld%lld",&l,&r);
        for(int i = 1; i<=n; i++)
        {
            for(int j = i; j<=n; j++)
            {
                ans=min(ans,g[i][l]+g[j][r]+dis[i][j]);
                ans=min(ans,g[i][r]+g[j][l]+dis[i][j]);
            }
        }
        printf("%lld\n",p[l]+p[r]+ans);
    }
    return 0;
}