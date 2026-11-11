#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],dp[5005][5005],sum,dp2[200005][3];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		for(int i=n;i>=1;i--)
		{
			if(!b[a[i]])
			{
				b[a[i]]=i;
			}
			for(int j=1;j<=m;j++)
			{
				if(b[a[i]]==i&&a[i]==j)
				{
					dp2[i][j]=1;
				}
				else if(b[a[i]]==i)
				{
					dp2[i][j]=dp2[i+1][j];
				}
				else
				{
					dp2[i][j]=dp2[b[a[i]]][j];
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			sum=0;
			for(int j=1;j<=n;j++)
			{
				sum+=dp2[j][i];
			}
			cout<<sum<<" ";
		}
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		if(!b[a[i]])
		{
			b[a[i]]=i;
		}
		for(int j=1;j<=m;j++)
		{
			if(b[a[i]]==i&&a[i]==j)
			{
				dp[i][j]=1;
			}
			else if(b[a[i]]==i)
			{
				dp[i][j]=dp[i+1][j];
			}
			else
			{
				dp[i][j]=dp[b[a[i]]][j];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		sum=0;
		for(int j=1;j<=n;j++)
		{
			sum+=dp[j][i];
		}
		cout<<sum<<" ";
	}
	return 0;
}
