#include <bits/stdc++.h>
using namespace std;
const long long N=2003;
int n,m,a[N],dp[N][N],ans;
void init()
{
	for(int i=2;i<=n;i++)
	{
		dp[i][i]=dp[i-1][i-1]&a[i];
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][1]=max(dp[i-1][1],a[i]);
	}
	init();
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		int cnt;
		for(int i=1;i<=n;i++)
		{
			cnt=INT_MAX;
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					cnt&=a[j];
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=20;i++)
	{
		int p=1<<i;
		if(p>=m)
		{
			cout<<p;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i>=j)
			{
				int k=dp[i-1][j-1];
				k&=a[i]; 
				dp[i][j]=max(dp[i][j],k);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i][m]);
	}
	cout<<ans;
	return 0;
}
