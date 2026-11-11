#include <bits/stdc++.h>
//#define long long ll 
using namespace std ;
const int MAXN = 500005 ;
long long n , m , a[MAXN] ;
long long maxx ;

queue <int> q ;

int main () {
	freopen ("crystal.in" , "r" , stdin) ;
	freopen ("crystal.out" , "w" , stdout) ;

	ios::sync_with_stdio (false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cin >> n >> m ;
	
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
	}
	
	sort (a+1 , a+n+1) ;
	
	long long now_m = 0 ;
	int l = 1 ;
	q.push(a[1]) ;
	for ( int r = 2 ; r <= n ; r ++ ) {
		long long h = a[r] - a[r-1] ;
		if (h*(r-l) + now_m > m) {
//			cout << "yes:\n" ;
			while (l <= r && h*(r-l)+now_m > m) {
				
				now_m -= (a[r-1]-a[l]) ;
				if (r-1 == l) now_m = a[r] - a[l] ;
				
				l ++ ;
//				cout << "l=" << l << " r=" << r << " now_m=" << now_m << "\n" ;
			}
//			cout << "//\n" ;
			
		}
		
		now_m += h*(r-l) ;
		maxx= max (maxx , (long long)(r-l+1)) ;
//		cout << "l=" << l << " r=" << r << " maxx=" <<maxx << " now_m=" << now_m << "\n" ;
	}
	
	cout << maxx ;
	
	return 0 ;
} 
