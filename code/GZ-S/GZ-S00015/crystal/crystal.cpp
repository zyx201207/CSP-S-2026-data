//GZ-S00015 贵阳市第二实验中学 严杨帅森 
#include<iostream>
#include<cstdio>
#define ll long long
ll n,m;
ll ans;
ll a[500005];
ll dp[5005][5005]; //dp[i][j]表示前i颗水晶，前j次操作的最优解 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>n>>m;
	for(ll i=1;i <= n;++i)
	{
		std::cin>>a[i];
	}
	for(ll j=0;j <= m;++j)
	{
		dp[1][j] = 1;
	}
	for(ll j=0;j <= m;++j)
	{
		for(ll i=2;i <= n;++i)
		{
			dp[i][j] = dp[i-1][j];
			ll sub=a[i]-a[i-1];
			for(ll k=0;k <= j;++k)
			{
				if(sub*dp[i-1][j] > j-k) continue;
				dp[i][j] = std::max(dp[i][j],dp[i-1][k]+1);
			}
			ans = std::max(ans,dp[i][j]);
		}
	}
	std::cout<<ans;
	return 0;
}
