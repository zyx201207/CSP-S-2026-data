#include <bits/stdc++.h>
namespace GD00492 {
using namespace std;
typedef long long ll;
#define fi first
#define se second
typedef pair<ll, int> pli;
const int maxn(509), maxm(5e5 + 5);
int n, m, d, q;
ll w[maxm];
vector<pli> g0[maxm], G[maxn];
ll dis[maxn][maxn]; bool vis[maxn];
priority_queue<pli, vector<pli>, greater<pli>> lis;
void dij(ll*dis, int s) {
	memset(dis + 1, 0x3f, sizeof(dis[0]) * n),
	memset(vis + 1, 0, sizeof(vis[0]) * n);
	lis.emplace(dis[s] = 0, s);
	while (!lis.empty()) {
		int u = lis.top().se; lis.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (pli i : G[u]) {
			if (dis[i.se] > dis[u] + i.fi)
				lis.emplace(dis[i.se] = dis[u] + i.fi, i.se);
		}
	}
}
void init() {}
void mian() {
	init();
	cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1, k; i <= n; ++i) {
		cin >> k;
		for (int j = 0, a, t; j < k; ++j) {
			cin >> a >> t;
			for (pli l : g0[a])
				G[i].emplace_back(t + l.fi, l.se),
				G[l.se].emplace_back(t + l.fi, i);
			g0[a].emplace_back(t, i);
		}
	}
	for (int i = 1; i <= n; ++i)
		dij(dis[i], i);
	int x, y; ll ans;
	while (q--) {
		cin >> x >> y;
		ans = 1e18;
		for (pli i : g0[x])
		for (pli j : g0[y])
			ans = min(ans, i.fi + j.fi + dis[i.se][j.se]);
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
}
} using namespace GD00492;
int main() {
	freopen("subway.in", "r", stdin),
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false),
	cin.tie(nullptr), cout.tie(nullptr);
	int c, T = 1; cin >> c;
//	cin >> T;
	while (T--) mian();
	return 0;
}

