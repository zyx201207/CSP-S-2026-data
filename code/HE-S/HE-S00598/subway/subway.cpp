#include <bits/stdc++.h>
#define PII pair<ll, int>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int w[N];
vector<PII> e[N];
int c, n, m, D, q;
ll d[N];
bool st[N];
ll dij(int s, int t) {
	for (int i = 1; i <= m; i ++) d[i] = 0x3f3f3f3f3f3f3f3f, st[i] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > h;
	h.push({0, s});
	d[s] = 0;
	while (h.size()) {
		int u = h.top().second;
		h.pop();
		if (st[u]) continue;
		st[u] = true;
		for (auto it : e[u]) {
			int j = it.first;
			ll dist = d[u] + it.second;
			if (d[j] > dist) {
				d[j] = dist;
				h.push({d[j], j});
			}
		}
	}
	return d[t];
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> D >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	bool flag = true;
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		int t2[k + 1], t1[k + 1];
		for (int j = 1; j <= k; j ++) cin >> t1[j] >> t2[j];
		for (int j = 1; j <= k; j ++)
			for (int tp = 1; tp <= k; tp ++) {
				e[t1[j]].push_back({t1[tp], t2[j] + t2[tp]});
				e[t1[j]].push_back({t1[tp], t2[j] + t2[tp]});
			}
	}
	while (q --) {
		int x, y;
		cin >> x >> y;
		ll ans = w[x] + w[y];
		ans += dij(x, y);
		cout << ans << "\n";
	}
	return 0;
}
