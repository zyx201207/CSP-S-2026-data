#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],b[5005][5005],e[5005][5005],ans;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(int i = 1;i<=t;i++)
    {
        scanf("%lld%lld",&n,&d);
        for(int j = 1;j<=n;j++)
        {
            scanf("%lld",&a[j]);
        }
        if(c<=10)
        {
            for(int j = 1;j<=n;j++)
            {
                for(int k = j;k<=n;k++)
                {
                    e[j][k] = 0;
                    e[k][j] = 0;
                    if(a[k]==a[j])
                    {
                        b[j][k] = 0;
                        b[k][j] = 0;
                        e[j][k] = 0;
                        e[k][j] = 0;
                    }
                    else if(a[k]-a[j]<=d)
                    {
                        b[j][k] = 1;
                        b[k][j] = 1;
                        e[j][k] = 1;
                        e[k][j] = 1;
                    }
                    else
                    {
                        b[j][k] = 1e18;
                        b[k][j] = 1e18;
                    }
                }
            }
            for(int j = 1;j<=n;j++)
            {
                for(int k = 1;k<=n;k++)
                {
                    for(int l = 1;l<=n;l++)
                    {
                        b[k][l] = min(b[k][l],b[k][j]+b[j][l]);
                    }
                }
            }
            for(int j = 1;j<=n;j++)
            {
                for(int k = 1;k<=n;k++)
                {
                    for(int l = 1;l<=n;l++)
                    {
                        if(abs(a[k]-a[l])>d&&b[k][l]==b[k][j]+b[j][l]&&k<=j&&l>=j)
                        {
                            e[k][l]+=e[k][j]*e[j][l];
                        }
                    }
                }
            }
            ans = 0;
            for(int j = 1;j<=n;j++)
            {
                for(int k = j+1;k<=n;k++)
                {
                    if(e[j][k]==2)
                    {
                        ans++;
                    }
                }
            }
            printf("%lld\n",ans);
        }
        else if(c<=12)
        {
            if(n==1)
            {
                printf("0\n");
            }
            else
            {
                int x = (d/(a[2]-a[1]))*2-1;
                if(x<=1||n-x<0)
                {
                    printf("0\n");
                }
                else
                {
                    printf("%lld\n",n-x);
                }
            }
        }
    }
    return 0;
}
