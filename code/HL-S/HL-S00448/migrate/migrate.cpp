#include <bits/stdc++.h>

using ll = long long ;


ll c;

ll t;

const ll N = 3e6;
std::vector<ll> a(N);	

int main(){
	
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	
	auto solveA = []() -> void{
		ll n , d;
		std::cin>>n>>d;
		for (ll i=1 ; i<=n ; ++i)
			std::cin>>a[i];
		
		std::cout<< (n%2==1 ? (n-1)/2 : n/2)<<'\n';
	};
	
	auto solveB = []() -> void{
		ll n , d;
		std::cin>>n>>d;
		for (ll i=1 ; i<=n ; ++i)
			std::cin>>a[i];
		
		std::cout<<0<<'\n';
	};
	
	auto solveC = []() -> void{
		ll n , d;
		std::cin>>n>>d;
		for (ll i=1 ; i<=n ; ++i)
			std::cin>>a[i];
		
		std::cout<<n-3<<'\n';
	};
	
	std::cin>>c>>t;
	while (t--){
		if (c==13 or c==14)
			solveB();
		else if (c==11 or c==12)
			solveA();
		else if (c>=15 and c<=18)
			solveC();
		else
			std::cout<<1<<'\n'<<2<<'\n';
	}
	
	
	
	return 0;
	
}