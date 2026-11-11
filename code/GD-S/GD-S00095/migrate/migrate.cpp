#include <bits/stdc++.h>
#define ll long long
#define pii pair <ll, ll>
using namespace std;
const int N = 1e6 + 10;
const ll inf = 1e18;
ll c, T, n, d;
ll x[N];
ll dis[N], cnt[N];
bool vis[N];
vector <ll> g[N];
void dijkstra (ll s) {
	for (int i = 1; i <= n; ++ i) {dis[i] = inf; cnt[i] = 0; vis[i] = 0;}
	priority_queue <pii, vector <pii>, greater <pii> > q;
	q.push ({0, s}); dis[s] = 0; cnt[s] = 1;
	while (! q.empty ()) {
		ll u = q.top ().second; q.pop ();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < g[u].size (); ++ i) {
			ll v = g[u][i];
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push ({dis[v], v});
			} else if (dis[v] == dis[u] + 1) {
				cnt[v] += cnt[u];
			}
		}
	}
}
void solve ();
int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T --) {solve ();}
	return 0;
}
void solve () {
	cin >> n >> d;
	for (int i = 1; i <= n; ++ i) cin >> x[i];
	for (int i = 1; i <= n; ++ i) g[i].clear ();
	for (int i = 1; i <= n; ++ i) {
		for (int j = i + 1; j <= n; ++ j) {
			if (x[j] - x[i] <= d) {
				g[i].push_back (j); g[j].push_back (i);
			} else break;
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; ++ i) {
		dijkstra (i);
		for (int j = 1; j <= n; ++ j) {
			if (j == i) continue;
			if (cnt[j] == 2) {
				++ res;
			} 
		}
	}
	cout << res / 2 << '\n';
}
