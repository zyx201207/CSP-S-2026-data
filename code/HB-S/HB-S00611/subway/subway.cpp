#include <bits/stdc++.h>
#define vi vector<int>
#define pb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
using namespace std;
constexpr int N=505,M=5e5+5;
constexpr ll inf=1e13;
int cid,n,m,d,q;
int w[M];
vector<pii>ln[M];
vi a[N],t[N];
ll dis[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&cid,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=inf;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1,k;i<=n;i++)
    {
        scanf("%d",&k);
        a[i].pb(k),t[i].pb(k);
        for(int j=1,a_,t_;j<=k;j++)
        {
            scanf("%d%d",&a_,&t_),a[i].pb(a_),t[i].pb(t_);
            ln[a_].pb(i,t_);
        }
    }
    for(int i=1;i<=m;i++)
        for(auto u:ln[i])
            for(auto v:ln[i])
            {
                if(u==v)continue;
                dis[u.fi][v.fi]=min(dis[u.fi][v.fi],1ll*(v.se+u.se));
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        int x,y;
        ll ans=inf;
        scanf("%d%d",&x,&y);
        for(auto u:ln[x])
            for(auto v:ln[y])
                ans=min(ans,dis[u.fi][v.fi]+u.se+v.se);
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}