#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e4 + 7;
const ll M = 1e4 + 7;

struct s {
	ll id;
	ll d;
	bool operator < (const s &z) const {
		return d > z.d;
	}
};

struct ss {
	ll to;
	ll v;
	ll nxt;
} e[M];

ll head[M];

priority_queue <s> que;

ll dis[M];
ll mp[M][M];
ll use[M];
ll to[M];
ll w[M];
bool vis[M];

ll c, n, m, d, q, cnt, cnte, x1, x2, ans;

void add (ll x, ll y, ll v) {
	e[++cnte].to = y;
	e[cnte].v = v;
	e[cnte].nxt = head[x];
	head[x] = cnte;
}

int main () {
	cin.tie (0) -> sync_with_stdio (0);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	cnt = m;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> to[j];
			if (!use[to[j]]) use[to[j]] = ++cnt;
			add (use[to[j]], use[to[j - 1]], 0);
			add (use[to[j - 1]], use[to[j]], 0);
		}
		for (int j = 1, x; j <= k; j++) cin >> x, add (use[to[j]], to[j], x), add (to[j], use[to[j]], x);
	}
	while (q--) {
		cin >> x1 >> x2;
		ans = 0;
		ans = w[x1] + w[x2];
		que.push ({x1, 0});
		memset (dis, 0x3f, sizeof dis);
		memset (vis, 0, sizeof vis);
		vis[x1] = true;
		dis[x1] = 0;
		while (que.size ()) {
			s tool = que.top ();
			que.pop ();
			if (vis[tool.id]) continue;
			vis[tool.id] = true;
			for (int i = head[tool.id]; i; i = e[i].nxt) {
				if (dis[e[i].to] > dis[tool.id] + e[i].v) {
					dis[e[i].to] = dis[tool.id] + e[i].v;
					que.push ({e[i].to, dis[e[i].to]});
				}
			}
		}
		ans += dis[x2];
		cout << ans << '\n' ;
	}
}
