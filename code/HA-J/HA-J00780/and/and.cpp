#include <bits/stdc++.h>
using namespace std;
int n,m,dp[2005][2005],ans;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=a[i];
		for(int j=2;j<=m;j++)
			dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]& (int)a[i]);
	}
	cout<<dp[n][m];
	return 0;
}