//GZ-S00015 贵阳市第二实验中学 严杨帅森 
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
#define cL 500005
#define inf 0x3f3f3f3f3f3f3f

struct dict{
	ll key;
	ll value;
};

ll c,n,m,d,q;
ll w[500005];
ll x[100005],y[100005];
ll ans[100005];

std::vector<dict> map[500505];

ll dp[500505];

ll dfs(ll p,ll fa)
{
	if(dp[p] != inf)
	{
		return dp[p];
	}
	for(auto i:map[p])
	{
		if(i.key == fa) continue;
		dp[p] = std::min(dp[p],dfs(i.key,p)+i.value);
	}
	return dp[p];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>c>>n>>m>>d>>q;
	for(ll i=1;i <= m;++i)
	{
		std::cin>>w[i];
	}
	for(ll i=1;i <= n;++i)
	{
		ll k;
		std::cin>>k;
		for(ll j=1;j <= k;++j)
		{
			ll a,t;
			std::cin>>a>>t;
			dict u,v;
			u.key = cL+i;
			u.value = t;
			v.key = a;
			v.value = t;
			map[a].push_back(u);
			map[cL+i].push_back(v);
		}
	}
	for(ll r=1;r <= q;++r)
	{
		std::cin>>x[r]>>y[r];
	}
	for(ll r=1;r <= q;++r)
	{
		std::fill(dp,dp+500505,inf);
		ans[r] = w[x[r]] + w[y[r]];
		dp[x[r]] = 0;
		ans[r] += dfs(y[r],0);
	}
	for(ll r=1;r <= q;++r)
	{
		std::cout<<ans[r]<<std::endl;
	}
	return 0;
}
