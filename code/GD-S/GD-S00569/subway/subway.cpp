#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using pil = pair<int, LL>;
using pii = pair<int, int>;
using pli = pair<LL, int>;
constexpr int maxn = 500;
constexpr int maxm = 5e5;
constexpr LL inf = 0x3f3f3f3f3f3f3f3fLL;
constexpr int maxq = 1e5;
int n, m, d, q, idx;
LL w[maxn + 10];
LL f[maxn * 2 + 10][maxn * 2 + 10];
vector<pil> e[maxm * 2 + 10];
LL ans[maxq + 10];
vector<pii> qry[maxm * 2 + 10];
LL dis[maxm * 2 + 10];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int c; cin >> c;
	if (c <= 8) {
		cin >> n >> m >> d >> q; idx = m;
		memset(f, 0x3f, sizeof f);
		for (int i = 1; i <= m; ++i) cin >> w[i];
		for (int i = 1; i <= n; ++i) {
			++idx;
			int k; cin >> k;
			for (int j = 1; j <= k; ++j) {
				int a, t;
				cin >> a >> t;
				f[a][idx] = min(f[a][idx], (LL)t);
				f[idx][a] = f[a][idx];
			}
		}
		for (int i = 1; i <= idx; ++i) f[i][i] = 0;
		for (int k = 1; k <= idx; ++k)	
			for (int i = 1; i <= idx; ++i) 
				for (int j = 1; j <= idx; ++j) 
					if (f[i][k] + f[k][j] < f[i][j]) 
						f[i][j] = f[i][k] + f[k][j];
		while (q--) {
			int l, r;
			cin >> l >> r;
			cout << w[l] + w[r] + f[l][r] << "\n";
		}		
	} else {
		cin >> n >> m >> d >> q; idx = m;
		for (int i = 1; i <= m; ++i) cin >> w[i];
		for (int i = 1; i <= n; ++i) {
			int k; cin >> k; ++idx;
			for (int j = 1; j <= k; ++j) {
				int a, t;
				cin >> a >> t;
				e[idx].emplace_back(make_pair(a, t));
				e[a].emplace_back(make_pair(idx, t));
			}
		}
		for (int i = 1; i <= q; ++i) {
			int l, r;
			cin >> l >> r;
			if (l > r) swap(l, r);
			qry[l].emplace_back(make_pair(r, i));
		}
		for (int i = 1; i <= m; ++i) {
			if (qry[i].size() == 0) continue;
			priority_queue<pli, vector<pli>, greater<pli> > que;
			for (int j = 1; j <= idx; ++j) dis[j] = inf;
			dis[i] = 0;
			que.push(make_pair(dis[i], i));
			while (!que.empty()) {
				auto it = que.top(); que.pop();
				if (it.first != dis[it.second]) continue;
				for (auto be : e[it.second]) {
					if (it.first + be.second < dis[be.first]) {
						dis[be.first] = it.first + be.second;
						que.push(make_pair(dis[be.first], be.first));
					}
				}
			}
			for (auto it : qry[i]) ans[it.second] = dis[it.first] + w[i] + w[it.first];
		}
		for (int i = 1; i <= q; ++i) cout << ans[i] << "\n";
	}
	return 0;
}

