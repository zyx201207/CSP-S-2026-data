#include <bits/stdc++.h>
#define int long long

const int maxn = 5e3 + 1 ;
int f[maxn][maxn], x[maxn] ;
int n, d, ans ;

int find(int l, int r) {
	if(l == r) return 0 ;
	if(x[r] - x[l] <= d) return 1 ;
	if(x[l + 1] - x[l] > d) return 2000000 ;
	return find(std::upper_bound(x + l + 1, x + r + 1, x[l] + d) - x - 1, r) + 1 ;
}

int dfs(int l, int r, int cnt) {
	if(l != r && ! cnt || cnt < f[l][r]) return 0 ;
	if(l == r) return 1 ;
	int res = 0 ;
	for(int j=l+1 ; j<=r&&(x[j]-x[l]<=d) ; j++) {
		res += dfs(j, r, cnt - 1) ;
		if(res > 2) return 3 ;
	}
	return res ;
}

void Solve() {
	std::cin >> n >> d ; ans = 0 ;
	for(int i=1 ; i<=n ; i++) std::cin >> x[i] ;
	for(int i=1 ; i<=n ; i++) {
		for(int j=i+1 ; j<=n ; j++) f[i][j] = find(i, j) ;
	}
	for(int i=1 ; i<=n ; i++) for(int j=i+1 ; j<=n ; j++) if(f[i][j] < 2000000 && dfs(i, j, f[i][j]) == 2) ++ ans ;
	std::cout << ans << '\n' ;
}

signed main() {
	freopen("migrate.in", "r", stdin) ;
	freopen("migrate.out", "w", stdout) ;
	std::ios::sync_with_stdio(0) ;
	std::cin.tie(0) ;
	int c, _ ;
	std::cin >> c >> _ ;
	while(_ --) Solve() ;
	return 0 ;
}

