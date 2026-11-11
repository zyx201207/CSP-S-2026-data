#include <iostream>
#include <algorithm>
using namespace std ;

#define int long long

const int N = 500010 ;
int n ,m ;
int a[N] ;
int ans = -1e9 ,key ;

signed main() {
	freopen("crystal.in" ,"r" ,stdin ) ;
	freopen("crystal.out" ,"w" ,stdout ) ;
	
	scanf("%lld%lld" ,&n ,&m ) ;
	
	for (int i = 1 ; i <= n ; i ++ ) 
		scanf("%lld" ,&a[i] ) ;
	
	sort(a + 1 ,a + n + 1 ) ;
	
	if (n >= 5010) key = 1 ;
	else key = n ;

	bool flag = false ;
	for (int i = 1 ; i <= key ; i ++ ) {
		int tol = m ,res = 0 ;
		
		if (flag) break ;
		
		for (int j = i ; j <= n - 1 ; j ++ ) {
			int len = j - i + 1 ;
			int cost = (a[j + 1] - a[j]) * len ;
			
			if (cost >= tol && j == i) flag = true ;
			
			if (cost >= tol) {
				int father ,k ;
				
				if (cost == tol) {
					res = len + 1 ;
					father = a[j + 1] ;
					k = j + 2 ;
				}
				else {
					res = len ;
					father = a[j] ;
					k = j + 1 ;
				}
				
				for (int p = k ; p <= n ; p ++ )
					if (a[p] == father) {
						res ++ ;
					}
					else break ;
				
				break ;
			}
			else tol -= cost ;
		}
		
		ans = max(ans ,res ) ;
	}
	
	if (ans != 1) printf("%lld\n" ,ans ) ;
	else printf("0\n") ;
	
	return 0 ;
}
