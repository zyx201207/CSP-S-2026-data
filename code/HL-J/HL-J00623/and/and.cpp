#include<bits/stdc++.h>
using namespace std;
long long a[200000];
long long dp[20000][20000]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][0]=a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=max(dp[i][j-1]&a[i],dp[i][j]&a[i]);
		}
	}
	cout<<dp[n][m];
	return 0;
} 
