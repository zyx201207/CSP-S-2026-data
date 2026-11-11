#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500050];
//去的下一个点，头，点间距，铁路间的
int to[500050];
int head[505];
int v[500050];
//l：地铁站间间距
long long l[500][505];
//站台对应点，间距
int lz[500050][25];
int lw[500050][25];
int cnt;
void point(int n,int a,int w)
{
    lz[a][0]++;
    lz[a][lz[a][0]]=n;
    lw[a][lz[a][0]]=w;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        cnt++;
        for(int j=1;j<=k;j++)
        {
            int a,w;
            scanf("%d%d",&a,&w);
            point(cnt,a,w);
        }
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            l[i][j]=100000000000000000;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=lz[i][0];j++)
        {
            for(int p=j+1;p<=lz[i][0];p++)
            {
                l[lz[i][j]][lz[i][p]]=lw[i][j]+lw[i][p];
                l[lz[i][p]][lz[i][j]]=lw[i][j]+lw[i][p];
                //printf("l[%d][%d]=%d\n",lz[i][p],lz[i][j],l[lz[i][p]][lz[i][i]]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==i)continue;
            for(int k=1;k<=n;k++)
            {
                if(k==i||k==j)continue;
                l[j][k]=min(l[j][k],l[j][i]+l[i][k]);
                //printf("l[%d][%d]=%lld\n",j,k,l[j][k]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans=1000000000000000000;
        for(int i=1;i<=lz[x][0];i++)
        {
            for(int j=1;j<=lz[y][0];j++)
            {
                ans=min(ans,l[lz[x][i]][lz[y][j]]+lw[x][i]+lw[y][j]);
            }
        }
        ans=ans+w[x]+w[y];
        printf("%lld\n",ans);
    }
}
