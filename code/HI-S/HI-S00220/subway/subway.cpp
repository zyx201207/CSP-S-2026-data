#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1030;
int c , n , m , d , q , w[N] , k[N] , a[N][N] , t[N][N] , x , y;
vector<int> vis[N];
int ans , v[N] , mint , last;
void dfs(int now) {
	if (now == y) {
		ans = min(mint , ans);
		mint = 0;
	}
	mint += t[last][now];
	last = now;
	for (int i = 1 ; i <= vis[now].size() ; i++) {
		if (v[i]) dfs(vis[now][i]);
	}
}

signed main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= n ; i++) cin >> w[i];
	for (int i = 1 ; i <= n ; i++) {
		cin >> k[i];
		for (int j = 1 ; j <= k[i] ; j++) cin >> a[i][j] >> t[i][j];
		for (int j = 1 ; j <= k[i] ; j++) {
			for (int l = 1 ; l <= k[i] , l != j ; l++) vis[a[i][j]].push_back(a[i][l]);
		}
	}
	while (q--) {
		cin >> x >> y;
		v[x] = true;
		ans += w[x] + w[y];
		cout << ans << endl;
		fill(v + 1 , v + n + 1 , 0);
	}
	return 0;
}

