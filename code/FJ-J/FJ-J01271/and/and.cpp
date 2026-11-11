#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
long long a[N];
long long dp[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	long long maxx=0;
	long long s=2147483647;
	dp[0]=2147483647;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		s&=a[i];
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		cout<<s;
		return 0;
	}
	maxx=0;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
