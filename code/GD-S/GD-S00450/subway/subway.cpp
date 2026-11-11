#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<=b; i++)
using namespace std;
const int N = 5e2 + 5, M = 5e5 + 5;
const long long inf = 1LL << 60;
long long n, m, q, w[M], d[N][N];
vector<pair<int, int>> r[M];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> n >> m >> q >> q;
	for(int i=1; i<=m; i++) cin >> w[i];
	for(int i=1, k, x, t; i<=n; i++){
		for(cin >> k; k --> 0;){
			cin >> x >> t; r[x].push_back({i, t});
		}
	}
	rep(i, 1, n) rep(j, 1, n) if(i != j) d[i][j] = inf;
	rep(k, 1, m) for(auto [i, t1]: r[k]) for(auto [j, t2]: r[k]){
		if(i != j) d[i][j] = min(d[i][j], t1 + t2 + 0ll);
	}
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n){
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}
	while(q --> 0){
		int x, y; cin >> x >> y;
		long long ans = inf;
		for(auto [i, t1]: r[x]) for(auto [j, t2]: r[y]){
			ans = min(ans, t1 + t2 + d[i][j]);
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}

