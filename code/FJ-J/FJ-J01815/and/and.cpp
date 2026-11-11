#include<bits/stdc++.h>
using namespace std;
long long a[1000000];int n,m;
long long dp[3000][3000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		dp[i][1]=a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int k=2;k<=m;k++)
			{
				
				dp[i][k]=max(dp[i][k],dp[j][k-1]&a[i]);
				
			}
		}
	}
	cout<<dp[n][m];
	
	return 0;
}
