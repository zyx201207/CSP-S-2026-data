#include <bits/stdc++.h>

using ll = long long ;

ll n , m;

const ll N = 3e5;
std::vector<ll> a(N);

int main(){
	
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	
	std::cin>>n>>m;
	for (ll i=1 ; i<=n ; ++i)
		std::cin>>a[i];
	
	std::sort(a.begin()+1 , a.begin()+n+1 , std::greater<ll>());

	for (ll i=2 ; i<=m ; ++i)
		a[1]&=a[i];
	
	std::cout<<a[1];
	
	return 0;
	
} 