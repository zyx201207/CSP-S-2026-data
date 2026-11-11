#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 2e5 + 5 ;
const int INF = 1e9 + 7 ;

int n, m ;
int a[MAXN] ;
int f[2][MAXN] ;

int main() {
	freopen("and.in", "r", stdin) ;
	freopen("ans.out", "w", stdout) ;

//	freopen("and4.in", "r", stdin) ;
//	freopen("and4.out.txt", "w", stdout) ;
	// and1 OkClear!
	// and2 OkClear!
	// and3 OkClear!
	// and4 OkClear!
	// and5 WonderfulAnser
	
	scanf("%d %d", &n, &m) ;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]) ;
		
	int it = 0 ;
	for(int i = 1; i <= n; i++) {
		int last = 1 - it ;
		f[it][1] = max(f[last][1], a[i]) ;
		for(int j = 2; j <= min(i, m); j++) f[it][j] = max(f[last][j], f[last][j - 1] & a[i]) ;
		it = last ;
		
//		for(int j = 1; j <= min(i, m); j++) printf("%d ", f[1 - it][j]) ;
//		printf("\n") ;
	}
	
	it = 1 - it ;
	printf("%d\n", f[it][m]) ;
	return 0 ;
}

