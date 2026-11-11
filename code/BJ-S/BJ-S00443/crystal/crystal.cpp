#include<bits/stdc++.h>
using namespace std;
const long long MX=5e5+10;
long long n,m,a[MX],dp[MX][2],mxx=-1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][0]=1;
        dp[i][1]=m;
    }
    sort(a+1,a+n+1);
    long long gc=a[2]-a[1];
    bool mk=0;
    for(int i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=gc)
        {
            mk=1;
            break;
        }
    }
    if(!mk)
    {
        long long ans=0;
        for(int i=n-1;i>=1;i--)
        {
            if(m>=(n-i)*gc)
            {
                m-=(n-i)*gc;
                ans++;
            }
            else
            {
                break;
            }
        }
        cout<<ans+1;
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        long long u;
        for(int j=1;j<i;j++)
        {
            if((a[i]-a[j])*dp[j][0]<=dp[j][1])
            {
                if(dp[i][0]<dp[j][0]+1)
                {
                    dp[i][0]=dp[j][0]+1;
                    u=dp[j][1]-(a[i]-a[j])*dp[j][0];
                }
            }
        }
        dp[i][1]=u;
        mxx=max(mxx,dp[i][0]);
    }
    cout<<mxx;
    return 0;
}
