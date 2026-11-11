#include <bits/stdc++.h>
using namespace std;
long long n,a[500010];
long long m,ans;
long long box[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    if(n<=5000)
    {
        for(int i=1;i<=n;i++)
        {
            long long f=m,sum=1;
            for(int j=i-1;j>=1;j--)
            {
                if(f>=a[i]-a[j])f-=(a[i]-a[j]),sum++;
                else break;
            }
            ans=max(ans,sum);
        }
        printf("%lld",ans);
        return 0;
    }
    int flag=1;
    for(int i=2;i<=n-1;i++)
        if(a[i]-a[i-1]!=a[i+1]-a[i])flag=0;
    if(flag==1)
    {
        long long ji=a[n],p=m;
        for(long long i=n;i>=1;i--)
        {
            if(p>=ji-a[i])p-=(ji-a[i]),ans++;
            else break;
        }
        printf("%lld",ans);
        return 0;
    }
    long long ma=-1e18,mi=1e18;
    for(long long i=1;i<=n;i++)mi=min(mi,a[i]),ma=max(ma,a[i]);
    if(ma<=100&&mi>=-100)
    {
        for(long long i=1;i<=n;i++)box[a[i]+100]++;
        for(long long i=mi+100;i<=ma+100;i++)
        {
            long long p=m,sum=0;
            //基准线就是要改成的数字是a[i]，然后我要看往下的所以他们的距离就是i-j然后我再统计j有多少个判断剩下的是否够
            for(long long j=i;j>=mi+100;j--)
            {
                if(p>=box[j]*(i-j))p-=box[j]*(i-j),sum+=box[j];
                else
                {
                    sum+=p/(i-j);
                    break;
                }
            }
            ans=max(ans,sum);
        }
        printf("%lld",ans);
    }
    return 0;
}
