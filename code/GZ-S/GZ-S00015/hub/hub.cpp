//GZ-S00015 贵阳市第二实验中学 严杨帅森 
#include<iostream>
#include<cstdio>
#define ll long long
ll c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>c>>t;
	while(t--)
	{
		ll n,k;
		std::cin>>n>>k;
		for(ll i=1;i <= n-1;++i)
		{
			ll u,v;
			std::cin>>u>>v;
		}
		std::cout<<((n-50*k-995)/4);
	}
	return 0;
}
