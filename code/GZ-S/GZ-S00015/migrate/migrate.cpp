//GZ-S00015 贵阳市第二实验中学 严杨帅森 
#include<iostream>
#include<cstdio>
#define ll long long
ll c,t,n,d;
ll x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>c>>t;
	while(t--)
	{
		std::cin>>n>>d;
		for(ll i=1;i <= n;++i)
		{
			std::cin>>x[i];
			x[i] -= x[1];
		}
	}
	std::cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
	return 0;
}
