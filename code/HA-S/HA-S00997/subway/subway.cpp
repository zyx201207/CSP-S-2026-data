#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500005], t[505][505];
long long ans;
struct xl {
	int a, t;
};
vector<xl> rd[505];
struct side {
	int p;
	long long w;
	bool operator < (const side &a) const {
		return w < a.w;
	}
};
map<side, int> mp;
vector<int> s[500005];
void bfs(int u, int v) {
	priority_queue<side> pq;
	pq.push({u, w[u]});
	bool d = 0;
	while (!pq.empty()) {
		int tp = pq.top().p;
		long long tw = pq.top().w;
		pq.pop();
		int l = s[tp].size();
		for (int i = 0; i < l; ++i) {
			side ttt= {s[tp][i],tp};
			int ttp = mp[ttt];
			long long ttw = tw + t[tp][tp] + t[tp][ttp];
			if (ttp == v) {
				ans = tw + w[v];
				d = 1;
				break;
			}
			qp.push({ttp, ttw});
		}
		if (d) {
			break;
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		int a[k + 5];
		a[0] = 0;
		for (int j = 1; j <= k; ++j) {
			int t;
			cin >> a[j] >> t;
			s[i].push_back({a[j], t});
			s[a].push_back(j);
			mp[ {i, a[j - 1]}] = a[j];
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		bfs(u, v);
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
