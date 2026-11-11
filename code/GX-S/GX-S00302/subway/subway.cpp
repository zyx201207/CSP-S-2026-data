#include<cstdio>
#include<iostream>
using namespace std;

const int nn=505;
const int mm=500005;
const int dd=22;
const long long INF=0x3f3f3f3f3f3f3f3f;

int n,m,d;
long long a[mm];
int b1[mm][dd],bx[mm];
long long b2[mm][dd];

long long f[nn][nn];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int qc,q;
    scanf("%d%d%d%d%d",&qc,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
    for(long long i=1,jie1,jie2,jie3;i<=n;i++)
    {
        scanf("%lld",&jie1);
        while(jie1--)
        {
            scanf("%lld%lld",&jie2,&jie3);
            bx[jie2]++;
            b1[jie2][bx[jie2]]=i;
            b2[jie2][bx[jie2]]=jie3;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) f[i][j]=INF;
        f[i][i]=0;
    }
    for(int i=1,x,y;i<=m;i++)
    {
        for(int j1=1;j1<bx[i];j1++) for(int j2=j1+1;j2<=bx[i];j2++)
        {
            x=b1[i][j1],y=b1[i][j2];
            f[x][y]=f[y][x]=min(f[x][y],b2[i][j1]+b2[i][j2]);
        }
    }

    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);

    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);

        long long ans=INF;
        for(int i=bx[x];i;i--) for(int j=bx[y];j;j--)
            ans=min(ans,f[b1[x][i]][b1[y][j]]+b2[x][i]+b2[y][j]);
        ans+=a[x]+a[y];

        printf("%lld\n",ans);
    }

    return 0;
}
