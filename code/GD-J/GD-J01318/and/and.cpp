#include<bits/stdc++.h>
using namespace std ; 
const int KN = 2e5 + 10 ;
int a[KN] , f[32] ;  
int n , m ; 
int main () {
	freopen ("and.in" , "r" , stdin ) ; 
	freopen ("and.out" , "w" , stdout ) ; 
	memset (a , 0 , sizeof (a) ) ;
	int ans = 0 , sum = 0 ;  
	int cnt = 0 ;  
	scanf ("%d%d" , &n , &m ) ;
	int x ; scanf ("%d" , &x ) ; 
	sum = x ; 
	ans = x ; 
	bool bk = 1 ; 
	for (int i = 1 ; i <= n ; i ++ ) {
		scanf ("%d" , &a[i] ) ; 
		if ((int) pow (2 , (int)log2(a[i] + 1)) != a[i] + 1 ) bk = 0 ; 
		int x = a[i] ; 
		int t = 0 ; 
		while (x) {
			f[t] += x % 2 ; 
			x /= 2 ; 
			t ++ ; 
		}
		ans = max (ans , a[i]) ; 
		sum = a[i] & sum ; 
	}
	if (m == 1 ) {
		printf ("%d" , ans ) ; 
		return 0 ; 
	} else if (m == n ) {
		printf ("%d" , sum ) ; 
		return 0 ; 
	}
	sort (a + 1 , a + n + 1 ) ; 
	if (bk) {
		printf ("%d" , a[n - m + 2] ) ; 
		return 0 ; 
	}
	int t = 1 ; 
	ans = 0 ; 
	for (int i = 0 ; i <= 30 ; i ++ ) {
		if (f[i] >= m ) {
			ans += t ; 
		}
		t = t* 2 ; 
	}
	printf ("%d" , ans ) ; 
	return 0 ; 
} 
