#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000007];
int tot;
int ans;
int fin;
int a[5007][5007];
bool dfs(int k,int j)
{
    int h = k;
    int t = k + 1;
    int f = 0;
    while(t < j)
    {
        if(t - h == 1 and x[t] - x[h] > d)
        {
            // cout << t << ' ' << h << endl;
            return 0;
        }
        while(x[t] - x[h] <= d)
        {
            t++;
        }
        f++;
        h++;
    }
    fin = f;
    for(int i = k ; i <= j; i++)
    {
        for(int j = 0; j <= fin ; j++)
        {
            a[i][j] = 1;
        }
    }
    for(int i = k + 1; i <= j ;i++)
    {
        t = i + 1;
        while(x[t] - x[i] <= d and t < n) t++;
        for(int l = fin; l > 0; l--)
        {
            for(int o = t; o >= i ; o--)
            {
                // printf("i = %d l = %d o = %d\n",i,l,o);
                a[i][l - 1] =  a[i][l - 1] + a[o][l];
                // printf("a[%d][%d] = %d \n",i,l - 1,a[i][l - 1]);
            }
        }
    }
    if(a[j][0] == 2) return 1;
    return 0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%d%d",&n,&d);
        for(int j = 1; j <= n; j++)
        {
            scanf("%d",&x[j]);
        }
        for(int j = 4; j <= n; j++)
        {
            for(int k = 1; k <= j - 3; k++)
            {
                ans = 0;
                if(dfs(k,j))
                {
                    tot++;
                    // printf("k = %d j = %d \n",k,j);
                }
            }
        }
        printf("%d\n",tot);
        tot = 0;
    }
    return 0;
}