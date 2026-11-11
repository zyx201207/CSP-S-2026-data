#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long dp[5005][5005];
long long inf;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool bz=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		double d;
		d=log2(a[i]+1);
		if(d!=floor(d))
		bz=1;
	}
	inf=pow(2,31)-1;
	if(n<=5000)
	{
		if(m==1)
		{
			long long maxx=0;
			for(int i=1;i<=n;i++)
			maxx=max(maxx,a[i]);
			cout<<maxx;
			return 0;
		}
		if(m==n)
		{
			for(int i=1;i<=n;i++)
			inf&=a[i];
			cout<<inf;
			return 0;
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=n;i++)
		dp[i][0]=inf;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			}
		}
		cout<<dp[n][m];
	}
	else
	{
		sort(a+1,a+1+n,cmp);
		if(!bz)
		{
			cout<<a[m];
			return 0;
		}
		else
		{
			for(int i=1;i<=m;i++)
			{
				inf&=a[i];
			}
			cout<<inf;
		}
	}
	return 0;
}
