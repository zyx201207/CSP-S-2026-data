#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 50;
int T, c, n, m, d, Q, tot;
ll w[N], dis[N << 1], k[N], G[550][550];
bool vis[N << 1];
vector<pair<ll, ll> > g[N << 1];
void Dijkstra(int s, int t) {
	for (int i = 0; i <= k[n]; i++) dis[i] = 1e18, vis[i] = false;
	for (int i = 1; i <= m; i++) dis[500000 + i] = 1e18, vis[500000 + i] = false;
	dis[s] = 0;
	priority_queue< pair<ll, int> > q;
	q.push(make_pair(0ll, s));
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		if (u == t) return ;
		vis[u] = true;
		for (pair<int, int> pir : g[u]) 
			if (dis[pir.first] > dis[u] + pir.second) {
				dis[pir.first] = dis[u] + pir.second;
				q.push(make_pair(-dis[pir.first], pir.first));
			}
	}
}
int calc1(int i, int j) {
    return k[i - 1] + j - 1;
}
inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48ll);
		ch = getchar();
	}
	return x * f;
}
void Sub1() {
	for (int i = n + 1; i <= n + m; i++) {
		for (pair<int, int> pir1 : g[i]) 
			for (pair<int, int> pir2 : g[i]) {
				if (pir1.first != pir2.first) {
					G[pir1.first][pir2.first] = G[pir2.first][pir1.first] = 1;
				}
			}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			if (!G[i][j] && i != j) G[i][j] = 1e18;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				G[i][j] = G[j][i] = min(G[i][j], G[i][k] + G[k][j]);
	while (Q--) {
		int x = read(), y = read();
		ll ans = 1e18;
		for (pair<int, int> k : g[n + x])
			for (pair<int, int> l : g[n + y]) ans = min(ans, G[k.first][l.first]);
		cout << ans * T + w[x] + w[y] << '\n';
	}
} 
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(); n = read(); m = read(); d = read(); Q = read();
    for (int i = 1; i <= m; i++) w[i] = read();
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
		if (c < 9) {
	        vector<int> v;
	        for (int j = 1, u, t; j <= k[i]; j++) {
	            u = read(); t = read();
	            g[500000 + u].push_back({calc1(i, j), t});
	            g[calc1(i, j)].push_back({500000 + u, t});
	            v.emplace_back(calc1(i, j));
	        }
	        k[i] += k[i - 1];
	        for (int j = 0; j < v.size() - 1; j++) {
	            g[v[j]].push_back({v[j + 1], 0});
	            g[v[j + 1]].push_back({v[j], 0});
	        }
		} else {
			for (int j = 1, u, t; j < k[i]; j++) {
				u = read(); t = read();
				g[i].push_back({n + u, t});
				g[n + u].push_back({i, t}); 
				T = t;
			}
		}
    }
    if (c >= 12) Sub1();
    while(Q--) {
        int x = read(), y = read();
        Dijkstra(500000 + x, 500000 + y);
        cout << dis[500000 + y] + w[x] + w[y] << '\n';
    }
    fclose(stdin);
    fclose(stdout);
}
