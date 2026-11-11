#include<bits/stdc++.h>
using namespace std;
int n,m,a[20010],dp[20010][20010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int Nnum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		Nnum=max(Nnum,a[i]);
		dp[i][1]=Nnum;
	}
	for(int i=2;i<=n;i++)
	{
		for(int t=2;t<=m;t++)
		{
			for(int j=1;j<i;j++)
			{
				dp[i][t]=max(dp[j][t-1]&a[i],dp[i][t]);
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}






