#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c, n, m, d, q, w[500010], k[510], ans;
vector<ll> a[510], t[510];
struct edge {
	ll v, x;
};
vector<edge> G[500010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			ll n1, n2;
			cin >> n1 >> n2;
			a[i].push_back(n1);
			t[i].push_back(n2);
		}
//		for (int j = 1; j <= k[i]; j++) {
//			if (j != 1) G[a[i][j]].push_back((edge){a[i][j - 1], i});
//			if (j != k[i]) G[a[i][j]].push_back((edge){a[i][j + 1], i});
//		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + t[1][x] + t[1][y] + w[y] << endl;
	}
	return 0;
}
