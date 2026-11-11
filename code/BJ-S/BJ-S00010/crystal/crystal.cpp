#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mi,dp[1000005];
bool flag1=true,flag2=true;
int main()
{
    freopen("crystal.in",r,stdin);
    freopen("crystal.out",w,stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=a[i-1])
        {
            flag1=false;
        }
    }
    sort(a+1,a+n+1);
    mi=a[2]-a[1];
    for(long long i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=mi)
        {
            flag2=false;
        }
    }
    if(flag1)
    {
        cout<<n;
        return 0;
    }
    if(flag2)
    {
        long long cnt=0;
        for(long long i=1;i<=n;i++)
        {
            if(cnt>m)
            {
                cout<<i-1;
                return 0;
            }
            cnt+=i;
        }
        cout<<n;
        return 0;
    }
    long long ans=1;
    for(long long i=1;i<=n;i++)
    {
        memset(dp,0,sizeof(dp));
        for(long long j=1;j<i;j++)
        {
            for(long long k=m;k>=a[i]-a[j];k--)
            {
                dp[k]=max(dp[k],dp[k-(a[i]-a[j])]+1);
                ans=max(ans,dp[k]+1);
            }
        }
    }
    cout<<ans;
    return 0;
}
