#include <bits/stdc++.h>
using namespace std ;
#define int long long

const int MAXN = 5e5 + 5 ;

int n, m, ans ;
int a[MAXN] ;

signed main() {
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	
//	freopen("crystal4.in", "r", stdin) ;
//	freopen("crystal4.out.txt", "w", stdout) ;
	// crystal1 OkClear!
	// crystal2 OkClear!
	// crystal3 OkClear!
	// crystal4 RunTimeError
	
	scanf("%lld %lld", &n, &m) ;
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]) ;
	sort(a + 1, a + n + 1) ;
	
	for(int i = 1; i <= n; i++) {
		int last = m, cnt = 1 ;
		for(int j = i - 1; j >= 1; j--) if(a[i] - a[j] <= last)
				last = last - (a[i] - a[j]), cnt++ ;
				
		ans = max(ans, cnt) ;
		if(last == 0) break ;
		
	}
	
	printf("%lld\n", ans) ;
	return 0 ;
}

