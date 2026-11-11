#include<bits/stdc++.h>
using namespace std ; 
const int KN = 2e5 + 10 ; 
int n ;
long long a[KN] ; 
bool bk[KN] ; 
char b[KN] ; 
char c[KN] ;  
int main () {
	freopen ("string.in" , "r" , stdin ) ; 
	freopen ("string.out" , "w" , stdout ) ; 
	memset (a , 0 , sizeof (a) ) ;
	long long ans = 0 ;  
	int cnt = 0 ; 
	int maxn = 0 ; 
	scanf ("%d" , &n ) ;
	for (int i = 1 ; i <= n ; i ++ ) {
		int x ;
		char ch ; 
		scanf ("%d" , &x ) ; 
		maxn = max (maxn , x ) ; 
		cin >> ch ; 
		if (ch == c[cnt] ) a[cnt] += x ; 
		else {
			cnt ++ ; 
			a[cnt] = x ; 
			c[cnt] = ch ; 
		}  
	}
	if (cnt == 1 ) {
		printf ("0" ) ; 
		return 0 ; 
	} 
	int l = 1 , r = cnt ; 
	while (l < r ) {
		if (a[l] <= 0 ) l ++ ; 
		if (a[r] <= 0 ) r -- ; 
		if (c[l] != c[r] ) {
			if (a[l] > a[r] ) {
				ans += a[r] ; 
				a[l] -= a[r] ; 
				a[r] = 0 ; 
				r -- ; 
			} else {
				ans += a[l] ; 
				a[r] -= a[l] ; 
				a[l] = 0 ; 
				l ++  ; 
			}
		}else {
			if (a[l] > a[r] ) { 
				a[l] -= a[r] ; 
				a[r] = 0 ; 
				r -- ; 
			} else {
				a[r] -= a[l] ; 
				a[l] = 0 ; 
				l ++  ; 
			}
		}
	}
	printf ("%lld" , ans ) ;  
	return 0 ; 
} 
