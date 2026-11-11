#include<bits/stdc++.h>
#define FOR(i , a , b) for(int i = (a) ; i <= (int)(b) ; ++ i)
using namespace std ;
using ll = long long ;
const int N = 5e5 + 10 ;
list<ll> q ;
ll a[N] ; 
signed main(){
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	ios::sync_with_stdio(false) , cin.tie(0) ; 
	ll n , m ; cin >> n >> m ; 
	FOR(i , 1 , n) cin >> a[i] ;
	sort(a + 1 , a + n + 1) ;
	ll ans = 0 ;
	q.push_back(a[1]) ;
	ll cnt = 0 ;  
	FOR(i , 2 , n){
		ll k = (a[i] - a[i - 1]) * (int)(q.size()) ;
		cnt += k ;
		while(cnt > m){
			cnt -= (a[i] - q.front()) ;
			q.pop_front() ;  
		}
		q.push_back(a[i]) ;  
		ans = max(ans , (ll)(q.size())) ;
	}
	cout << ans ;
	return 0 ; 
}
/*
5 5
1 2 4 8 9
*/
