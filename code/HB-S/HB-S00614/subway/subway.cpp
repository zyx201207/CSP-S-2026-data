#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=5e5+10;
int c,n,m,d,q;
int w[mx],k[505];
long long dis[505][505],ed[505][505];
struct edge
{
    int to;
    long long w;
};
vector<edge> to[mx];
vector<edge> e[505];
long long Min(long long x,long long y)
{
    if(x>y) return y;
    return x;
}
void floyd()
{
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=n;i;i--)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=Min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) 
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int a,t;
            cin>>a>>t,to[a].push_back({i,t});
        } 
            
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dis[i][j]=ed[i][j]=21400000000000000;
    for(int i=1;i<=m;i++)
    {
        for(auto j:to[i])
        {
            for(auto k:to[i])
            {
                int u=j.to,v=k.to;
                if(u!=v) 
                {
                    ed[u][v]=Min(ed[u][v],j.w+k.w);
                    dis[u][v]=Min(dis[u][v],j.w+k.w);
                }
                    
            }
        }
    }
    floyd();
    while(q--)
    {
        int xr,yr;
        cin>>xr>>yr;
        long long res=21400000000000000;
        for(auto x:to[xr])
        {
            for(auto y:to[yr])
            {
                int u=x.to,v=y.to;
                res=Min(res,dis[u][v]+w[xr]+w[yr]+x.w+y.w);
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}