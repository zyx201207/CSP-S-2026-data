#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=510;
const int M=5e5+10;
const int D=25;
const int nlp=1e18;
int c,d,q,n,m;
int w[M];
int a[D][M];
int t[D][M];
int siz[M];
int f[N][N];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    int cn,aa,tt;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&cn);
        for(int j=1;j<=cn;j++)
        {
            scanf("%lld%lld",&aa,&tt);
            siz[aa]++;
            a[siz[aa]][aa]=i;
            t[siz[aa]][aa]=tt;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            f[i][j]=nlp;
        f[i][i]=0;
    }
    int u,v;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=siz[i];j++)
        {
            for(int k=j+1;k<=siz[i];k++)
            {
                u=a[j][i],v=a[k][i];
                f[u][v]=min(f[u][v],t[j][i]+t[k][i]);
                f[v][u]=f[u][v];
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    int ans;
    while(q--)
    {
        ans=nlp;
        scanf("%lld%lld",&u,&v);
        int s,e;
        for(int i=1;i<=siz[u];i++)
        {
            for(int j=1;j<=siz[v];j++)
            {
                s=a[i][u],e=a[j][v];
                ans=min(ans,f[s][e]+t[i][u]+t[j][v]+w[u]+w[v]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
