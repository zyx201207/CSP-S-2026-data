#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x,y;
const int M = 2007;
int w[M];
int k[500007];
int a[M][M];
int to[500007],ww;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            a[i][j] = 100000;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&k[i]);
        for(int j = 1; j <= k[i]; j++)
        {
            scanf("%d%d",&to[j],&ww);
            a[i][to[j]] = ww;
        }
        for(int j = 1; j <= k[i]; j++)
        {
            if(to[j] != i)
            {
                a[i][to[j]] += a[i][i]; 
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int l = 1; l <= m; l++)
            {
                // printf("i = %d j = %d l = %d\n",i,j,l);
                // printf("a[i][j] = %d a[i][l] = %d a[l][j] = %d\n",a[i][j],a[i][l],a[l][j]);
                a[i][j] = min(a[i][j] ,a[i][l] + a[l][j]);
            }
        }
    }
    for(int i = 1; i <= q ; i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",a[x][y] + w[x] + w[y]);
    }
    return 0;
}