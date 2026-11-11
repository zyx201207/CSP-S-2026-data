#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 505,maxm = 500015;
const ll INF = 1e17;
int c,n,m,d,q,k[maxn],a,x,y;
ll w[maxm],dis[maxn][maxn],t,ans,tans;
struct node{
    int i;
    ll dis;
};
node rr;
vector<node> f[maxm];

void E(int i)
{
    for(int p1 = 0;p1<f[i].size();++p1)
        for(int p2 = p1+1;p2<f[i].size();++p2)
        {
            dis[f[i][p1].i][f[i][p2].i] =
            min(dis[f[i][p1].i][f[i][p2].i],f[i][p1].dis+f[i][p2].dis);
        }
}

ll S(int x,int y)
{
    tans =INF;
    for(auto p1:f[x])
        for(auto p2:f[y])
        {
            tans=min(tans,p2.dis+p1.dis+dis[p1.i][p2.i]);
        }
    return tans;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i =1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    for(int i =1;i<=m;++i)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&k[i]);
        for(int j =1;j<=k[i];++j)
        {
            scanf("%d%lld",&a,&t);
            rr ={i,t};
            f[a].push_back(rr);
        }
    }
    for(int i=1;i<=m;++i)
    {
        E(i);
    }
    for(int i =1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            dis[i][j] = min(dis[i][j],dis[j][i]);
        }
    for(int K =1;K<=n;++K)//floyd
    {

        for(int i =1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dis[i][j] = min(dis[i][j],dis[i][K]+dis[j][K]);
            }
        }
    }
    for(int i =1;i<=q;++i)
    {
        ans = 0;
        scanf("%d%d",&x,&y);
        ans+=w[x]+w[y];
        ans+=S(x,y);
        printf("%lld\n",ans);
    }
    return 0;
}
