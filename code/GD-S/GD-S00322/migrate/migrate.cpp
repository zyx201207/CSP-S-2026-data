#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < int, int > pii;
#define unmp unordered_map
#define vc vector
#define pb push_back
#define FT first 
#define SD second 
#define mpr make_pair
const int N = 2e6 + 5;
const ll inf = 1e18;
vc < int > g[N];
ll dis[N], cnt[N], x[N];
bool vis[N];
int n;
ll d;
void dij(int s) {
	static priority_queue < pii, vc < pii >, greater < pii > > q;
	while (!q.empty())
		q.pop();
	for (int i = 1; i <= n; i++)
		dis[i] = inf, vis[i] = cnt[i] = 0;
	dis[s] = 0, cnt[s] = 1;
	q.push(mpr(0, s));
	while (!q.empty()) {
		int u = q.top().SD;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto v : g[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(mpr(dis[v], v));
			}
			else if (dis[v] == dis[u] + 1) {
				cnt[v] += cnt[u];
			}
		}
	}
}
ll ans;
void slv() {
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		g[i].clear();
	for (int i = 1; i <= n; i++) 
		cin >> x[i];
	for (int i = 1, pos; i <= n; i++) {
		//pos = upper_bound(x + 1, x + 1 + n, x[i] + d) - x - 1;
		for (int j = i + 1; j <= n; j++) {
			if (x[j] - x[i] > d)
				break;
			g[i].pb(j);
			g[j].pb(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		dij(i);
		for (int j = i + 1; j <= n; j++)
			if (cnt[j] == 2)
				ans++;
//		cout << i << endl;
//		for (int j = i + 1; j <= n; j++)
//			cout << dis[i] << ' ' << cnt[j] << 
	}
	cout << ans << '\n';
//	cout << "g:\n";
//	for (int i = 1; i <= n; i++) {
//		for (auto j : g[i])
//			cout << j << ' ';
//		cout << endl;
//	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--)
		slv();
	return 0;
}
/*
0 1
4 2
1 2 3 4
*/
