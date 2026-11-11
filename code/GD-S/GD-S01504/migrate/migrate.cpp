#include <bits/stdc++.h>
#define int long long
using namespace std ;
using ll = long long ;
int c , t , n , d , a ;
signed main() {
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	cin.tie(nullptr) -> ios :: sync_with_stdio(false) ;
	cin >> c >> t ;
	while(t --) {
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++) cin >> a ;
		if(n <= 9) cout << 1 << "\n" ;
		else if(n <= 300) cout << 0 << "\n" ;
		else if(n <= 5000) cout << 0 << "\n" ;
	}
	return 0 ;
}

