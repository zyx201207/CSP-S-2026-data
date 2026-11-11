#include <bits/stdc++.h>

using ll = long long ;

ll n , m;

const ll N = 6e5;
std::vector<ll> a(N);

std::vector<ll> vis(N , 0);
std::vector<ll> ans(N , 0);

int main(){
	
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	
	std::cin>>n>>m;
	for (ll i=1 ; i<=n ; ++i){
		std::cin>>a[i];
		vis[a[i]] = i;
	}
	
	bool isOk = true;
	for (ll i=1 ; i<n ; ++i)
		if (a[i] > a[i+1])
			isOk = false;
	
	
	if (isOk){
		for (ll i=1 ; i<=m ; ++i)
			std::cout<<1<<' ';
		return 0;
	}
	

	for (ll beginning=1 ; beginning<=n ; ++beginning)
		for (ll i=beginning ; i<=n ; ++i){
			if (vis[a[i]] != i)
				i = vis[a[i]];
		
			if (vis[a[i]] == i){
				ans[a[i]]++;
				continue;
			}
		}
		
	for (ll i=1 ; i<=m ; ++i)
		std::cout<<ans[i]<<' ';

	return 0;

}
	
	
	