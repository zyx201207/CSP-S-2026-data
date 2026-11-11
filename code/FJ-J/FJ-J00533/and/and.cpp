#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[2005][2005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		dp[i][1]=a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
			dp[i][j]=dp[i-1][j-1]&a[i];
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i][m]);
	cout<<ans;
	return 0;
}
