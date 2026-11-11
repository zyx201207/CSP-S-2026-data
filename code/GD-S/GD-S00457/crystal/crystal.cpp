#include <bits/stdc++.h>

#define ll long long 
#define N 5000005 
using namespace std ;
int n , ans = 1 , l , r ;
ll m , a[N] ;
ll pr[N] ;
int main() {
	
	ios :: sync_with_stdio(false) ;
	cin.tie(0) , cout.tie(0) ;
	
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++)cin >> a[i] ;
	sort(a + 1 , a + 1 + n) ;
//	for(int i = 1 ; i <= n ; i++)cout << pr[i] << " " ;
//	cout << '\n' ;
	
	l = 1 , r = 2 ;
	
	for(int r = 2 ; r <= n ; r++) {
		pr[r] = pr[r - 1] + 1ll * (a[r] - a[r-1]) * (r - l) ;
		while(pr[r] > m && l < r) {
			pr[r] = pr[r] - (a[r] - a[l]) ;
			l++ ;
		}
		ans = max(r - l + 1 , ans) ;
	}
	cout << ans ;
	 
	 
	return 0 ;
	
}
/*
5 8
-3 -1 2 2 7
 5 5
 1 2 4 8 9

*/
