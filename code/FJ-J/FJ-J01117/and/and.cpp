#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	vector<vector<int>>dp(m+1,vector<int>(m*m));
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=max(max(dp[i-1][j-1]&a[j],dp[i][j-1]&a[j]),a[j]);
		}
	}
	cout<<dp[m][n];
	return 0;
}