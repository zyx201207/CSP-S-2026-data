#include <bits/stdc++.h>
#define int long long 
const int N = 2e6 + 5; 
using namespace std; 
int n, d, C, ans; 
int a[N], f[5005][5005]; 
bool v[5005]; 
inline int js(int l, int r) {
	int R = l, t = 0; 
	while(R <= r) {
		if(R < r && a[R + 1] - a[R] > d) return 0; 
		if(a[R + 1] - a[l] > d || R + 1 > r) {
			++t; l = R; 
		}
		++R; 
	}
	return t; 
}
inline void work(int l, int r) {
	int R = l; 
	while(R <= r) {
		if(a[R + 1] - a[l] > d || R + 1 > r) {
			l = R; v[l] = 1; 
		}
		++R; 
	}
	return ; 
}
inline void bl() {
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			f[i][j] = js(i, j); 
	for(int i = 1, t; i <= n; ++i)
		for(int j = i + 2; j <= n; ++j) {
			if(!f[i][j]) continue; 
			for(int l = i; l <= j; ++l) v[l] = 0; 
			work(i, j); 
			t = 0; 
			for(int l = i + 1; l < j; ++l)
				if(!v[l] && f[i][l] + f[l][j] == f[i][j]) ++t; 
			if(t == 1) ++ans; 
		}
	cout << ans << "\n"; 
	return ; 
}
inline void solve() {
	cin >> n >> d; ans = 0; 
	for(int i = 1; i <= n; ++i) cin >> a[i]; 
	if(C <= 10) return bl(); 
	return ; 
}
signed main() {
	freopen("migrate.in", "r", stdin); 
	freopen("migrate.out", "w", stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 
	int _; cin >> C >> _; 
	while(_--) solve(); 
	return 0; 
}
