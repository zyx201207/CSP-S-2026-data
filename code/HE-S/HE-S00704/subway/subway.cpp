# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> PII;
const int N = 5e5 + 10;
int O_o, n, m, K, Q;
ll w[N], c[510][510];
map<int, map<int, ll> > t;
vector<int> v[N];
vector<int> e[510];
ll D[510][510];
ll d[510];
bool st[510];
void di(int S) {
	memset(d, 0x3f, sizeof d);
	memset(st, 0, sizeof st);
	d[S] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({0, S});
	while (heap.size()) {
		int u = heap.top().second;
		heap.pop();
		if (st[u]) continue;
		st[u] = true;
		for (int j : e[u]) {
			ll dist = d[u] + c[u][j];
			if (dist < d[j]) {
				d[j] = dist;
				heap.push({d[j], j});
			}
		} 
	}
	for (int i = 1; i <= m; i ++) 
		D[S][i] = D[i][S] = d[i];
}
int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0); 
	cin >> O_o >> m >> n >> K >> Q;
	for (int i = 1; i <= n; i ++) cin >> w[i];
	memset (c, 0x3f, sizeof c);
	for (int i = 1; i <= m; i ++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			int a;
			ll b;
			cin >> a >> b;
			t[a][i] = b;
			v[a].push_back(i);
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (v[i].size()) {
			for (int j = 0; j < v[i].size(); j ++) {
				for (int k = j + 1; k < v[i].size(); k ++) {
					int a = v[i][j], b = v[i][k];
					e[a].push_back(b);
					e[b].push_back(a);
					c[a][b] = c[b][a] = min(c[a][b], t[i][a] + t[i][b]); 
				}
			}
		}
	}
	for (int i = 1; i <= m; i ++) di(i);
	while (Q --) {
		int x, y;
		cin >> x >> y;
		ll ans = 1e18;
		for (int j : v[x]) {
			for (int k : v[y]) {
				ans = min(ans, t[x][j] + D[j][k] + t[y][k]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
} 
