//GZ-J00015 贵阳市第二实验中学 严杨帅森 
#include<iostream>
#include<cstdio>
#define ll long long
ll n;
ll L;
ll a[200005];
char c[200005];
char h[200000005];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>n;
	ll count=1;
	for(ll i=1;i <= n;++i)
	{
		std::cin>>a[i]>>c[i];
		L += a[i];
		for(ll j=1;j <= a[i];++j)
		{
			h[count++] = c[i];
		}
	}
	ll mid=L/2;
	for(ll i=1;i <= mid;++i)
	{
		if(h[i] != h[L-i+1])
		{
			++ans;
		}
	}
	std::cout<<ans;
	return 0;
}
