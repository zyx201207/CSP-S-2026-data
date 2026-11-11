//GZ-J00015 贵阳市第二实验中学 严杨帅森 
#include<iostream>
#include<cstdio>
#define ll long long
ll n,m;
ll a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>n>>m;
	for(ll i=1;i <= n;++i)
	{
		std::cin>>a[i];
	}
	dp[1] = a[1];
	for(ll i=2;i <= n;++i)
	{
		for(ll j=std::min(i,m);j > 1;--j)
		{
			dp[j] = std::max(dp[j],dp[j-1] & a[i]);
		}
		dp[1] = std::max(dp[1],a[i]);
	}
	std::cout<<dp[m];
	return 0;
}
