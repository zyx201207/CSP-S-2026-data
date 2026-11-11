#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;         
int n,m;
int a[N],dp[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
		for(int j=i;j>=1;j--)
		{
			cnt+=(a[i]-a[j]);
		}
        if(cnt<=m)
		{
			dp[i]=i;
		}
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
