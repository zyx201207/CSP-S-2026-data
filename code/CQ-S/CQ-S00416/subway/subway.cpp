#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int N = 5e5 + 5;
const int M = 505;
const int L = 5e6 + 5;

int c, n, m, d, q;
ll w[N];
ll sss[L];
vector<pair<int, ll>> g[N];
vector<pair<int, int>> ddd[N];
ll dist[L];
ll ww[N];
ll a[N], t[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
			a[j] += (i - 1) * m;
			sss[a[j]] = t[j];
		}
		for (int j = 1; j <= k; j++) {
			for (int kk = j + 1; kk <= k; kk++) {
				g[a[j]].push_back(make_pair(a[kk], t[kk]));
				g[a[kk]].push_back(make_pair(a[j], t[j]));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = i + 1; k < n; k++) {
			for (int j = 1; j <= m; j++) {
				if (sss[i * m + j] && sss[k * m + j]) {
					g[i * m + j].push_back(make_pair(k * m + j, sss[k * m + j]));
					g[k * m + j].push_back(make_pair(i * m + j, sss[i * m + j]));
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		ddd[x].push_back(make_pair(y, i));
	}
	for (int i = 1; i <= m; i++) {
		if (ddd[i].empty()) continue;
		memset(dist, 0x3f, sizeof(dist));
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		for (int j = 1; j <= n; j++) {
			if (sss[i + (j - 1) * m]) {
				pq.push(make_pair(sss[i + (j - 1) * m], i + (j - 1) * m));
				dist[i + (j - 1) * m] = sss[i + (j - 1) * m];
//				cout << i + (j - 1) * m;
			}
		}
//		cerr << sss[i] << endl;
		while (pq.size()) {
			ll ww = pq.top().first;
			int u = pq.top().second;
//			int pre = pq.top().second.second;
			pq.pop();
//			cerr << " ";
//			cerr << u << " " << ww << endl;
			for (pair<int, ll> xxx : g[u]) {
//			cerr << 111 << endl;
				int v = xxx.first;
				ll w = xxx.second;
//				if (pre == v) continue;
//				if (u == 7 && v == 8) cerr << w << endl;
//				if (pre != 0 && (((pre - 1) / m == (u - 1) / m && (u - 1) / m == (v - 1) / m) || ((pre) % m == (u) % m && (u) % m == (v) % m))) {
////					cerr << 111 << endl;
//					if (dist[v] > dist[u] + w - sss[u]) {
//						dist[v] = dist[u] + w - sss[u];
//						pq.push(make_pair(dist[v], make_pair(v, u)));
//					}
//				} else {
					if (dist[v] > dist[u] + w) {
						dist[v] = dist[u] + w;
						pq.push({dist[v], v});
					}
//				}
			}
		}
		for (pair<int, int> xx : ddd[i]) {
			int vv = xx.first;
			ll ans = 0x3f3f3f3f3f3f3f3f;
			for (int i = 1; i <= n; i++) {
				ans = min(ans, dist[vv + (i - 1) * m]);
			} 
			ww[xx.second] = ans + w[i] + w[vv];
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ww[i] << endl;
	}
	return 0;
} 
