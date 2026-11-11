#include <bits/stdc++.h>
using namespace std ;
#define int long long

const int MAXN = 2e6 + 5 ;

int n, d ;
int x[MAXN], cnt[MAXN] ;

inline bool check(int i) {
	return cnt[i] == 2 &&
		   (cnt[i - 1] == 1 || cnt[i - 1] == 2) &&
		   cnt[i - 3] == 1 &&
		   (cnt[i - 4] == 0 || cnt[i - 4] == 1) ;
}

inline int calc(int _x, int y) {
	if(_x == y) return 1 ;
	if(_x > y) return 0 ;
	
	int res = 0 ;
	for(int i = _x; i <= y; i++) if(x[i] - x[_x] <= d)
			res = res + calc(i, y) ;
	
	return res ;
}

signed main() {
	freopen("migrate.in", "r", stdin) ;
	freopen("migrate.out", "w", stdout) ;
	
//	freopen("migrate1.in", "r", stdin) ;
//	freopen("migrate1.out.txt", "w", stdout) ;
	// migrate1 WonderfulAnser
	// migrate2 OkClear!
	// migrate3 
	// migrate4 
	// migrate5 
	// migrate6 
	
	
	int C, T ; scanf("%lld %lld", &C, &T) ;
	while(T--) {
		scanf("%lld %lld", &n, &d) ;
		for(int i = 1; i <= n; i++) scanf("%lld", &x[i]) ;
		if(n <= 9) {
			int ans = 0 ;
			for(int i = 1; i <= n; i++)
				for(int j = i + 1; j <= n; j++) if(calc(i, j) == (long long)2)
						ans++ ;
			
			printf("%lld\n", ans) ;
		}
		else {
			int l = x[2] - x[1] ;
			int num = d / l ;
			while(n > num) n = n - num ;
			if(n = num - 2) puts("1") ;
			else puts("0") ;
		}
	}
	
	return 0 ;
}



