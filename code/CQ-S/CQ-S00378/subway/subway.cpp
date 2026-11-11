#include <bits/stdc++.h>
#define int long long 
const int N = 5e2 + 5, M = 5e5 + 5; 
using namespace std; 
int C, n, m, d, q; 
int w[M], t[M], G[N][N]; 
pair<int, int> a[M][25]; 
inline int Min(int x, int y) {
	if(!x) return y; 
	return min(x, y); 
}
inline void solve() {
	cin >> C >> n >> m >> d >> q; 
	for(int i = 1; i <= m; ++i) cin >> w[i]; 
	for(int i = 1, k, x, y; i <= n; ++i) {
		cin >> k; 
		while(k--) cin >> x >> y, a[x][++t[x]] = {i, y}; 
	}
	for(int id = 1; id <= m; ++id)
		for(int i = 1; i < t[id]; ++i)
			for(int j = i + 1; j <= t[id]; ++j)
				G[a[id][j].first][a[id][i].first] = G[a[id][i].first][a[id][j].first] = Min(G[a[id][i].first][a[id][j].first], a[id][i].second + a[id][j].second); 
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(i != j) {
				for(int k = 1; k <= n; ++k)
					if(i != k && j != k && G[i][k] && G[k][j]) G[i][j] = G[j][i] = Min(G[i][j], G[i][k] + G[k][j]); 
			}
	int x, y, ans = -1, ss; 
	while(q--) {
		cin >> x >> y; 
		for(int i = 1; i <= t[x]; ++i)
			for(int j = 1; j <= t[y]; ++j) {
				ss = G[a[x][i].first][a[y][j].first] + a[x][i].second + a[y][j].second; 
//				cout << a[x][i].first << " " << a[y][j].first << "\n"; 
				ans = (ans == -1 ? ss : min(ans, ss)); 
			}
		cout << ans + w[x] + w[y] << "\n"; 
		ans = -1; 
	}
	return ; 
}
signed main() {
	freopen("subway.in", "r", stdin); 
	freopen("subway.out", "w", stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 
	solve(); 
	return 0; 
}
