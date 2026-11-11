#include<bits/stdc++.h>
using namespace std;
long long n,m,dp[200005],dp2[200005],a[200005],dp3[200005];
int pf(long long x)
{
    int sum=0;
    while(x>0)
    {
        sum=sum+x%2;
        x/=2;
    }
    return sum;
}
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[0]=dp3[0]=(1<<30)-1;
        dp2[0]=0;
        //cout<<a[i]<<' '<<(1023&256)<<"\n";
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=m;j>=1;j--)
        {
            //cout<<j<<' '<<dp[j]<<' '<<a[i]<<' '<<(dp[j]&a[i])<<"\n";
            long long x=dp[j-1]&a[i];
            dp3[j]=max(dp3[j],x);
            x=pf(x);
            if(dp2[j]<x)
            {
                dp2[j]=x;
                dp[j]=dp[j-1]&a[i];
            }
            
        }
    }
    cout<<max(dp[m],dp3[m])<<"\n";
    return 0;
}