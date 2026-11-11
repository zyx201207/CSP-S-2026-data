#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[100005],dp[2005][2005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) dp[i][1]=a[i];
	if(m==n)
	{
		ll x=a[1];
		for(int i=2;i<=n;i++)
		{
			x=(x&a[i]);
		}
		cout<<x;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=min(i*1ll,m);j++)
		{
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],(dp[i-1][j-1]&a[i])));
		}
	}
	for(int i=m;i<=n;i++)
	{
		ans=max(ans,dp[i][m]);
	}
	cout<<ans;
	return 0;
}
