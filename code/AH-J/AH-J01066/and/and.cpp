#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005],a[2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		dp[i-1][0]=a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(j>=1)
				dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]&a[i]));
//			cout<<dp[i][j]<<" ";
		}
//		cout<<"\n";
	}
	cout<<dp[n][m];
	return 0;
}
