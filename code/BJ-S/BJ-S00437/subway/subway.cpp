#include<bits/stdc++.h>
using namespace std;
#define int long long
#define min(x,y) x>y?y:x
struct node
{
    int v,w;
} s[500005][25];
int cnt[500005];
int w[500005],dis[505][505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            s[a][++cnt[a]]=(node){i,t};
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=(i==j?0:1e18);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=cnt[i];j++)
        {
            for(int k=1;k<=cnt[i];k++)
            {
                if(s[i][j].v!=s[i][k].v)
                {
                    dis[s[i][j].v][s[i][k].v]=min(dis[s[i][j].v][s[i][k].v],s[i][j].w+s[i][k].w);
                    dis[s[i][k].v][s[i][j].v]=min(dis[s[i][k].v][s[i][j].v],s[i][j].w+s[i][k].w);
                }
            }
        }
    }
    for(int z=1;z<=n;z++)for(int x=1;x<=n;x++)for(int y=1;y<=n;y++)dis[x][y]=min(dis[x][y],dis[x][z]+dis[z][y]);
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int ans=1e18;
        for(int i=1;i<=n;i++)
        {
            int ou=1e18,ov=1e18;
            for(int j=1;j<=cnt[u];j++)ou=min(ou,s[u][j].w+dis[s[u][j].v][i]);
            for(int j=1;j<=cnt[v];j++)ov=min(ov,s[v][j].w+dis[s[v][j].v][i]);
            ans=min(ans,ou+ov);
        }
        cout<<w[u]+w[v]+ans<<'\n';
    }
    return 0;
}
