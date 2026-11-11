#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

const int N = 5e5+507, M = 5e6+7;

int h[N];
int tot = 0;

struct edge {
	int u, v, w;
};
struct node {
	int ed, w, nxt;
}ne[M];
//vector<edge> elist;
void addedge(int u, int v, int w) {
	ne[++tot] = {v, w, h[u]};
	h[u] = tot;
//	elist.pb({u, v, w});
}
int tid, n, m, d, Q;
struct pii {
	int first, second;
	bool operator < (const pii x) const {
		return first < x.first;
	}
};
vector<pii> a[507];
int w[N];
map<PII, int> mp;

ll dis[N];
bool vis[N];
priority_queue<PII, vector<PII>, greater<PII>> pq;
void dijk(int src) {
	memset(vis, 0, sizeof vis);
	memset(dis, 0x7f, sizeof dis);
	pq.push({0, src});
	dis[src] = 0;
	while (pq.size()) {
		PII top = pq.top();
		pq.pop();
		int u = top.se;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = h[u]; i; i = ne[i].nxt) {
			int v = ne[i].ed;
			ll w = ne[i].w;
//			cout << dis[u] << endl;
			if (dis[u] + w < dis[v] && !vis[v]) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
//		cout << endl;
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> tid >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			a[i].pb({x, y});
			addedge(x + 500, i, y + w[x]);
			addedge(i, x + 500, y + w[x]);
		}
		sort(a[i].begin(), a[i].end());
	}
	
	for (int i = 1; i <= n; i++) {
		for (pii &p : a[i]) {
			for (int j = i + 1; j <= n; j++) {
				int idx = lower_bound(a[j].begin(), a[j].end(), p) - a[j].begin();
//				cout << a[j][idx].fi << " " << a[j][idx].se << " " << p.fi << " " << p.se << endl;
				if (a[j][idx].fi == p.fi) {
					if (mp[{i, j}] == 0) mp[{i, j}] = p.se + a[j][idx].se;
					else mp[{i, j}] = min(mp[{i, j}], p.se + a[j][idx].se);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (mp[{i, j}] != 0) addedge(i, j, mp[{i, j}]), addedge(j, i, mp[{i, j}]);
		}
	}
	while (Q--) {
		int x, y;
		cin >> x >> y;
		x += 500;
		y += 500;
		dijk(x);
		cout << dis[y] << "\n";
	}
//	for (auto &i : elist) {
//		cout << i.u << " " << i.v << " " << i.w << endl;
//	}
//	cout << mp[{2, 3}] << endl;
	
	return 0;
}
