#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2000005;
int n, d, x[N], dis[N], c[N];
bool v[N];

void dfs(int p, int q) {
	if (q < dis[p]) {
		dis[p] = q;
		c[p] = 0;
	}
	if (q == dis[p]) ++c[p];
	
	for (int i = p + 1; i <= n; ++i) {
		if (x[p] + d >= x[i]) {
			dfs(i, q + 1);
		}
	}
}

void solve() {
	cin >> n >> d;
	
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	
	memset(dis, 0x3f, sizeof(dis));
	memset(c, 0, sizeof(c));
	dfs(1, 0);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (c[i] == 2) {
			++cnt;
		}
	}
	
	cout << cnt << '\n';
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int C, T;
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
