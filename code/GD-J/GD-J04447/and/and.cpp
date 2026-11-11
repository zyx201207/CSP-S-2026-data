#include<bits/stdc++.h>
using namespace std;
long long a[200005],dp[2005][2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][1]=a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j-1]&a[i])); 
		}
	}
	cout<<dp[n][m];
}
