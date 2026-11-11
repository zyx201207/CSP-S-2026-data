#include <bits/stdc++.h>
using namespace std ;
#define int unsigned long long

const int MAXN = 2e5 + 5 ;

int n ;
int a[MAXN], ans ;
char c[MAXN] ;

signed main() {
	freopen("string.in", "r", stdin) ;
	freopen("string.out", "w", stdout) ;
	
//	freopen("string3.in", "r", stdin) ;
//	freopen("string3.out.txt", "w", stdout) ;
	// string1 OkClear!
	// string2 OkClear!
	// [Big Point]string3 OkClear!
	// string4 OkClear!
	// string5 OkClear!
	// string6 OkClear!
	
	scanf("%d", &n) ;
	for(int i = 1; i <= n; i++) scanf("%d %c", &a[i], &c[i]) ;
	int i = 1, j = n, ans = 0 ;
	while(i < j) {
		if(a[i] >= a[j]) {
			if(c[i] != c[j]) ans = ans + a[j] ;
			a[i] = a[i] - a[j--] ;
			if(a[i] == 0) i++ ; 
		}
		else {
			if(c[i] != c[j]) ans = ans + a[i] ;
			a[j] = a[j] - a[i++] ;
		}
//		printf("%llu %llu\n", i, j) ;
//		printf("%llu %llu %llu\n", a[i], a[j], ans) ;
	}
	// i == j时剩下的肯定都是一样的，不管单数复数。 
	printf("%llu", ans) ;
	return 0 ;
}

