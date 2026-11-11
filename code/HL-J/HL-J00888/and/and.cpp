#include<bits/stdc++.h>
#define int long long
using namespace std;

int m, n, a[200010], lyy;

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    if(m==1)
    {
        sort(a+1,a+1+n);
        printf("%lld",a[n]);
        return 0;
    }
    else if(m==2)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                lyy=max(a[i]&a[j],lyy);
            }
        }
        printf("%lld",lyy);
        return 0;
    }
    else if(m==n)
    {
        lyy=a[1];
        for(int i=2; i<=n; i++)
        {
            lyy=lyy&a[i];
        }
        printf("%lld",lyy);
        return 0;
    }
    printf("0");
    return 0;
}
