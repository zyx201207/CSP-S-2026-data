#include <bits/stdc++.h>

using ll = long long ;

ll n , m;

const ll N = 6e5;
std::vector<ll> a(N);

std::vector<ll> pre(N , 0);

int main(){
	
	
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	
	std::cin>>n>>m;
	for (ll i=1 ; i<=n ; ++i)
		std::cin>>a[i];
	
	std::sort(a.begin()+1 , a.begin()+n+1);

	
	pre[1] = 0;
	for (ll i=2 ; i<=n ; ++i)
		pre[i] = pre[i-1] + a[i] - a[i-1];

	ll id = n;
	ll ans = 0;
	while (id>=1){
		ll cost = 0;
		ll step = 0;	
		for (ll i=id ; i>=1 ; --i){
			cost += (pre[id] - pre[i]);
			if (cost > m)
				break;
			step++;
		}
		
		ans = std::max(step , ans);
		
		id--;
		
	}	
	
	
	std::cout<<ans;
	
	return 0;
		


}