#include <bits/stdc++.h>
//#define int long long
using namespace std ;
using ll = long long ;
ll n , ans ;
string s ;
signed main() {
	freopen("string.in" , "r" , stdin) ;
	freopen("string.out" , "w" , stdout) ;
	cin.tie(nullptr) -> ios :: sync_with_stdio(false) ;
	cin >> n ;
	for(ll i = 1 , a ; i <= n ; i ++) {
		char c ;
		cin >> a >> c ;
		while(a --) s += c ;
	}
	for(ll i = 0 ; i < (s.size() / 2) ; i ++) {
		if(s[i] != s[s.size() - i - 1]) ans ++ ;
	}
	cout << ans << "\n" ;
	return 0 ;
}
