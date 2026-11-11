#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int c,n,m,d,q;
int w[N];
int e[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    memset(e,0x3f3f3f3f,sizeof e);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=1;j<=x;j++)
        {
            int a,t;
            scanf("%d%d",&a,&t);
            e[a][m+i]=t;
            e[m+i][a]=t;
        }
    }
    for(int k=1;k<=n+m;k++)
    {
        for(int i=1;i<=n+m;i++)
        {
            for(int j=1;j<=n+m;j++)
            {
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    while(q--)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        printf("%d\n",e[s][t]+w[s]+w[t]);
    }
    return 0;
}
