#include<bits/stdc++.h>
using namespace std;
long long a[200005],dp[200005];
bool d[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,l=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]>dp[1]) 
		{
			d[l]=0;
			l=i;
			d[i]=1;
			dp[1]=a[i];
		}
	}
	for (int i=2;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			l=0;
			if ((!d[j])&&dp[i]<(dp[i-1]&a[j]))
			{
				d[l]=0;
				l=j;
				d[l]=1;
				dp[i]=(dp[i-1]&a[j]);
			}
		}
	}
	cout<<dp[m];
	return 0;
}
