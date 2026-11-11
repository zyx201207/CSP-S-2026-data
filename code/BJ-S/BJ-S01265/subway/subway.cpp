#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int c,n,m,d,q;
int w[500005],eg[505][505],f[505][505];
vector<pii> vec[500005];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++)
        {
            int a,t;
            scanf("%lld%lld",&a,&t);
            vec[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            eg[i][j]=eg[j][i]=1e18;
            f[i][j]=f[j][i]=1e18;
        }
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            for(int k=0;k<vec[i].size();k++)
            {
                pii x=vec[i][j],y=vec[i][k];
                eg[x.fi][y.fi]=eg[y.fi][x.fi]=min(eg[x.fi][y.fi],x.se+y.se);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(eg[i][j]!=1e18)f[i][j]=f[j][i]=eg[i][j];
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        int ans=1e18;
        for(int i=0;i<vec[x].size();i++)
        {
            for(int j=0;j<vec[y].size();j++)
            {
                pii u=vec[x][i],v=vec[y][j];
                ans=min(ans,f[u.fi][v.fi]+u.se+v.se+w[x]+w[y]);
            }
        }
        printf("%lld\n",ans);
    }
}
