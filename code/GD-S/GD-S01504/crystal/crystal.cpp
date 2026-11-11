#include <bits/stdc++.h>
//#define int long long
using namespace std ;
using ll = long long ;
const int N = 5e5 + 5 ;
ll n , m , a[N] , b[N] , r = -1e12 , l = 1e12 , ans ;
bool check(ll x , ll a[] , ll y) {
	for(ll i = 1 ; i <= n ; i ++) {
		if(a[i] < x) {
			y -= (x - a[i]) ;
			a[i] = x ;
		}
	}
	return (y >= 0) ;
}
void func(ll x) {
	//cout << x << "\n" ;
	for(ll i = 1 ; i <= n ; i ++) {
		//cout << x <<" ";
		if(b[i] < x) b[i] = x ;
		//cout << a[i] << "\n" ;
	}
}
int main() {
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	cin.tie(nullptr) -> ios :: sync_with_stdio(false) ;
	cin >> n >> m ;
	for(ll i = 1 ; i <= n ; i ++) {
		cin >> a[i] ;
		b[i] = a[i] ;
		r = max(r , a[i]) ;
		l = min(l , a[i]) ;
	}
	//cout << r << "\n" ;
	//cout << l << "\n" ;
	while(l < r) {
		ll mid = (l + r + 1) >> 1 ;
		if(check(mid , a , m)) l = mid ;
		else r = mid - 1 ;
	}
	//cout << l << "\n" ;
	func(l) ;
	//for(int i = 1 ; i <= n ; i ++) cout << b[i] << "\n" ;
	for(int i = 1 ; i <= n ; i ++) 
		if(b[i] == l) ans ++ ;
	cout << ans << "\n" ;
	return 0 ;
}

