#include <bits/stdc++.h>
#define int long long

inline int max(int a, int b) { return a > b ? a : b ; }

const int maxn = 5e5 + 1 ;
int n, m, ans ;
int a[maxn], sum[maxn] ;

bool check(int l, int r) { return (a[r] * (r - l + 1) - (sum[r] - sum[l - 1])) <= m ; }

int find(int x) {
	int l = 1, r = x, res = 0 ;
	while(l <= r) {
		int mid = l + r >> 1 ;
		if(check(mid, x)) {
			res = x - mid + 1 ;
			r = mid - 1 ;
		}
		else l = mid + 1	  ;
	}
	return res ;
}

signed main() {
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	std::ios::sync_with_stdio(0) ;
	std::cin.tie(0) ;
	std::cin >> n >> m ;
	for(int i=1 ; i<=n ; i++) std::cin >> a[i] ;
	std::sort(a + 1, a + n + 1) ;
	for(int i=1 ; i<=n ; i++) {
		sum[i] = sum[i - 1] + a[i] ;
		ans = max(ans, find(i)) ;
	}
	std::cout << ans ;
	return 0 ;
}

