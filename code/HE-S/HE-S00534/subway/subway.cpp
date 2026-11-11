#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
long long f[N][N], a[N], a1[N][N], t[N][N];
int c, n, m, d, q;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) cin >> a[i];
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= m; ++j){
			f[i][j] = INT_MAX;
		}
	}
	for(int i = 1; i <= n; ++i) f[i][i] = 0;
	for(int i = 1; i <= n; ++i){
		int x; cin >> x;
		for(int j = 1; j <= x; ++j){
			cin >> a1[i][j] >> t[i][j];
			if(j > 1){
				f[a1[i][j - 1]][a1[i][j]] = t[i][j - 1] + t[i][j];
				f[a1[i][j]][a1[i][j - 1]] = t[i][j - 1] + t[i][j]; 
			}
		}
	}
	for(int k = 1; k <= m; ++k){
		for(int i = 1; i <= m; ++i){
			for(int j = 1; j <= m; ++j){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for(int i = 1; i <= q; ++i){
		int u, v; cin >> u >> v;
		cout << a[u] + f[u][v] + a[v] << "\n";
    }
	return 0;
}
