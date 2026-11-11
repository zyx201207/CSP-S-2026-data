#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int d=a[2]-a[1],p=0;
    for(int i=2;i<=n;i++)
    {
        if((a[i]-a[i-1])!=d)
        {
            p=0;
            break;
        }
        else{p=1;}
    }
    if(p==1)
    {
        int sum=0,t=0;
        while(sum<=m)
        {
            sum=d*t*(t+1)/2;
            t++;
        }
        if(t-1>n)
        {
            printf("%d",n);
            return 0;
        }
        else
        {
            printf("%d",t-1);
            return 0;
        }
    }
    unsigned long long sum=1e18+1;
    while(sum>m)
    {
        sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[n]-a[i];
        }
        if(sum>m)
        {
            n--;
        }
    }
    printf("%d",n);
    return 0;
}