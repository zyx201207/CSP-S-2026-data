#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 505
#define M 500005
#define D 25
#define int long long
using namespace std;
int c,n,m,d,q;
int w[M];
int k,a,t;
int u,v;
int ans;
struct edge
{
    int to,dis;
};
edge fstl[M][D];//from stations to lines
int cntsl[M];
int dis[N][N];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    const int inf=dis[0][0];
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",w+i);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%lld%lld",&a,&t);
            fstl[a][++cntsl[a]]={i,t};
        }
    }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int j=1,fr,dfr;j<=cntsl[i];j++)
        {
            fr=fstl[i][j].to,dfr=fstl[i][j].dis;
            for(int k=j+1,to;k<=cntsl[i];k++)
            {
                to=fstl[i][k].to;
                dis[fr][to]=dis[to][fr]=min(dfr+fstl[i][k].dis,dis[fr][to]);
            }
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        {
            if(i==k)continue;
            for(int j=i+1;j<=n;j++)
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    while(q--)
    {
        scanf("%lld%lld",&u,&v);
        if(u==v)
        {
            printf("0\n");
            continue;
        }
        ans=inf;
        for(int i=1;i<=cntsl[u];i++)
            for(int j=1;j<=cntsl[v];j++)
                ans=min(ans,fstl[u][i].dis+fstl[v][j].dis+dis[fstl[u][i].to][fstl[v][j].to]);
        printf("%lld\n",ans+w[u]+w[v]);
    }
    return 0;
}