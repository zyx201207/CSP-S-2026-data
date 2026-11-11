#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int w[N], k[510];
int a[510][1010], t[510][1010];
long long dis[N];
int c, n, m, d, q;
bool vis[N];
struct Sb{
	int v, w;
};
struct node {
	int w, u;
	bool operator >(node &o) const{
		return w > o.w;
	}
};
vector<Sb> st[N]; 
void dj(int s) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<vector<node>, greater<node>, node> q;
	dis[s] = 0;
	q.push({0, s});
	while(!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto ed : id[u]) {
			int w = ed.w, v = ed.u;
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push({dis[v], v});
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int m = 1; m <= 1; m++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			st[j * 2].push_back({j, t[i][j]});
			st[j].push_back({j * 2, t[i][j]});
			if (j == 1) continue;
			st[j].push_back({j - 1, 0});
			st[j - 1].push_back({j, 0});
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		dj(x);
		cout << w[x] + dis[y] + w[y] << '\n';
	}
	
	return 0;
}
