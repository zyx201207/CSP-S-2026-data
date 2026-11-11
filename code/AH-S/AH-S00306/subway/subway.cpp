#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int M = 5e5 + 5;

long long c, n, m, d, Q, w[M], k[N], dis[N][N];
struct stati {
	int l;
	vector <long long> frm;
	vector <long long> t;
} lies[M];
struct edge {
	long long v, d;
	friend bool operator < (edge x, edge y) {
		return x.d > y.d;
	}
};
vector <edge> G[N];
priority_queue <edge> q;

void dij(int s) {
	dis[s][s] = 0;
	while (!q.empty())	q.pop();
	q.push((edge) {s, 0});
	while (!q.empty()) {
		edge n1 = q.top();
		q.pop();
		long long u = n1.v;
		for (int i = 0; i < (int)(G[u].size()); i++) {
			long long v = G[u][i].v, d = G[u][i].d;
			if (dis[s][u] + d < dis[s][v]) {
				dis[s][v] = dis[s][u] + d;
				q.push((edge) {
					v, dis[s][v]
				});
			}
		}
	}
	return ;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++)	cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			long long a, t;
			cin >> a >> t;
			lies[a].l++;
			lies[a].t.push_back(t);
			lies[a].frm.push_back(i);
		}
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < lies[i].l; j++) {
			for (int k = j + 1; k < lies[i].l; k++) {
				long long fj = lies[i].frm[j], tj = lies[i].t[j];
				long long fk = lies[i].frm[k], tk = lies[i].t[k];
				G[fj].push_back((edge) {fk, tj + tk});
				G[fk].push_back((edge) {fj, tj + tk});
			}
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) {
		dij(i);
	}
	
	while (Q--) {
		int x, y;
		cin >> x >> y;
		long long ans = 1e18;
		for (int i = 0; i < lies[x].l; i++) {
			for (int j = 0; j < lies[y].l; j++) {
				long long xt = lies[x].t[i], xf = lies[x].frm[i];
				long long yt = lies[y].t[j], yf = lies[y].frm[j];
				ans = min(ans, w[x] + xt + dis[xf][yf] + yt + w[y]);
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
