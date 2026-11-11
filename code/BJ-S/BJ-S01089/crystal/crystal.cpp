#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500005],b[500005],ans = 1;
    b[0] = 0;
    a[0] = 0;
    scanf("%lld %lld",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i < n;i++)
    {
        b[i] = a[i + 1] - a[i];
    }
    a[1] = b[1];
    for(int i = 2;i < n;i++)
    {
        a[i] = a[i - 1] + b[i];
    }
    b[1] = a[1];
    for(int i = 2;i < n;i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    for(int i = 2;i <= n;i++)
    {
        if((m + b[i - 2]) / (i - 1) >= a[i - 1])
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
