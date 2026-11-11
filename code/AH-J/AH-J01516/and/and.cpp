#include<bits/stdc++.h>
using namespace std;
long long a[200010],dp[2001][2001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=max(dp[i-1][1],a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=k;j++)
		{
			if(i<j)
			{
				dp[i][j]=0;
			}
			else
			{
				dp[i][j]=max(dp[i][j-1]&dp[i-1][j-1],dp[i-1][j]);
			}
		}
	}
	cout<<dp[n][k];
}
