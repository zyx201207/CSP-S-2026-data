#include<bits/stdc++.h>
using namespace std;
int dp[100005][100005];
int a[100005];
int m,n;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=max(dp[i][j-1],dp[i][j-1]&a[i]);
		}
	}
	cout<<dp[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
