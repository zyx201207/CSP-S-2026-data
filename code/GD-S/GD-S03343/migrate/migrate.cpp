#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 5;
int n, d, x[N], dis[505][505], sum[505][505], ans, diff;

inline void init() {
	ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			dis[i][j] = 1e18;
			sum[i][j] = 0;
		}
		dis[i][i] = 0;
	}
}

void solve() {
	ans = 0;
	cin >> n >> d;
	for(int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	if(n == 1) {
		cout << 0 << endl;
		return ;
	}
	init();
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= n; ++j)
	if(abs(x[i] - x[j]) <= d)
		dis[i][j] = sum[i][j] = dis[j][i] = sum[j][i] = 1;
	for(int k = 1; k <= n; ++k)
	for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= n; ++j) {
		if(dis[i][j] > dis[i][k] + dis[k][j]) {
			dis[i][j] = dis[i][k] + dis[k][j];
			sum[i][j] = sum[i][k] * sum[k][j];
		}
		else if(dis[i][j] == dis[i][k] + dis[k][j])
			sum[i][j] += sum[i][k] * sum[k][j];
	}
	for(int i = 1; i <= n; ++i)
	for(int j = i + 1; j <= n; ++j)
		if(sum[i][j] == 2) ++ ans;
	cout << ans << endl;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0); cin.tie(0);

	int _, T; cin >> _ >> T;
	while(T --) solve();
	
	return 0;
}
/*
0 1
5 2
1 2 3 4 5

24 pts
*/
