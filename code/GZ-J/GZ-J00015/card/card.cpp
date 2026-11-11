//GZ-J00015 贵阳市第二实验中学 严杨帅森 
#include<iostream>
#include<cstdio>
#define ll long long
ll n,m;
ll a[500005];
ll prenum[300005];
ll reality[300005];
ll ans[300005];
ll cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>n>>m;
	for(ll i=1;i <= n;++i)
	{
		std::cin>>a[i];
	}
	for(ll i=1;i <= n;++i)
	{
		for(ll j=1;j <= m;++j)
		{
			prenum[j] = 0;
			ans[j] = 0;
		}
		for(ll j=i;j <= n;++j)
		{
			reality[j] = 1;
		}
		for(ll j=i;j <= n;++j)
		{
			if(prenum[a[j]] == 0)
			{
				prenum[a[j]] = j;
				++ans[a[j]];
			}
			else
			{
				for(ll k=prenum[a[j]];k < j;++k)
				{
					if(reality[k] != -1)
					{
						prenum[a[k]] = 0;
						reality[k] = -1;
						--ans[a[k]];
					}
				}
				prenum[a[j]] = j;
				++ans[a[j]];
			}
		}
		for(ll j=1;j <= m;++j)
		{
			if(ans[j] > 0)
			{
				++cnt[j];
			}
		}
	}
	for(ll i=1;i <= m;++i)
	{
		std::cout<<cnt[i]<<" ";
	}
	return 0;
}
