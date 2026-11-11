#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],maxx=-100000000000,dp[500005],maxn;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        memset(dp,0,sizeof(dp));
        int ax=a[i];
        int maxn=-100000000000000;
        for(int k=1;k<=i;k++)
        {
            for(int j=m;j-(ax-a[k])>=0;j--)
            {
                dp[j]=max(dp[j],dp[j-(ax-a[k])]+1);
                maxn=max(maxn,dp[j]);
            }
        }
        maxx=max(maxx,maxn);
    }
    cout<<maxx;
    return 0;
}
