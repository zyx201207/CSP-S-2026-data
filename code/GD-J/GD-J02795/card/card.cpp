#include<bits/stdc++.h>
using namespace std;
long long a[1000005],s,b[1000005],sum,n,m,dp[3005][3005];
int main()
{
	//freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=m;j++)
		{
			dp[a[j]][i]+=dp[a[j]][i-1];
		}
		dp[a[x]][i]+=1;
	}
	for(int i=1;i<=n;i++)
	{
		int k=i;
		for(int j=i;j<=n;j++)
		{
			for(int q=1;q<=n;q++)
			{
				if(dp[q][j]-dp[q][k]>=2)
				{
					k=j-1;
				}
			} 
		}
		for(int j=1;j<=m;j++)
		{
			if(dp[j][n]-dp[j][k]>=1) b[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
} 
