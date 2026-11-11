#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005],c[500005],d[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld",&n);
    scanf("%lld",&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    bool f=0;
    for (int i=1;i<n;i++)
    {
        b[i]=a[i+1]-a[i];
        if(b[i]!=b[i-1]&&i!=1)
        {
            f=1;
        }
        c[i]=b[i]*i;
        d[i]=d[i-1]+c[i];
    }
    if(f==0)
    {
        long long ans=0;
        long long ans2=0;
        for (int i=1;i<n;i++)
        {
            ans2+=c[i];
            if(ans2>m)
            {
                ans=i;
                break;
            }
        }
        if(ans==0)
        {
            ans=n;
        }
        printf("%lld\n",ans);
    }
    else
    {
        for (int i=n;i>=1;i--)
        {
            if(d[i-1]>m)
            {
                long long q=d[i-1];
                for (int j=2;j<=n-i+1;j++)
                {
                    q-=a[j+i-2]-a[j-1];
                    q+=(a[j+i-1]-a[j+i-2])*(i-1);
                    if(q<=m)
                    {
                        printf("%d\n",i);
                        return 0;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
