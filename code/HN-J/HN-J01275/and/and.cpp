#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2e4+5;
int n,m;
int a[N],dp[M][M];
void solve1()
{
	sort(a,a+n);
	int ans=a[n];
	for(int i=n-1;i>=n-m+1;i++)
	{
		ans&=a[i];
	}
	cout<<ans<<'\n';
}
void solve2()
{
	dp[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=min(m,i);j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);	
		}	
	}
	cout<<dp[n][m]<<'\n';
}
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
		dp[i][1]=max(dp[i-1][1],a[i]);
	}
	if(n>20000) solve1();
	else solve2();
	return 0;
}

