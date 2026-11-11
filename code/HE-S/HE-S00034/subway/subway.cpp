#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//20f
const int maxn = 505;
const int maxm = 5e5 + 5;
const ll inf = 1e18;

int nn;
ll c, n, m, d, q;
ll w[maxm];
ll dis[maxn];
bool p[maxn];
ll ans[maxn][maxn];


struct node {
	ll u, w;
};

vector<node> e[maxm];

void dij(int st) {
	priority_queue<pair<int, int> > q;
	for (int i = 1; i <= n; i++) dis[i] = inf, p[i] = 0;
	dis[st] = 0;
	p[st] = 1;
	q.push(make_pair(st, 0));
	while (!q.empty()) {
		int u = q.top().first;
		q.pop();
		for (int n_eu = e[u].size(), i = 0; i < n_eu; i++) {
			int v = e[u][i].u, wu = e[u][i].w;
			if (p[v]) continue;
			p[v] = 1;
			if (dis[v] > dis[u] + wu) {
				dis[v] = dis[u] + wu;
				q.push(make_pair(v, dis[v]));
			}
		}
	}
	return ;
}
/*
0 7 6 20 10
4 4 4 4 4 4
2 1 5 2 5
2 1 2 4 6
2 2 1 4 3
2 2 2 3 3
2 4 1 3 1
2 3 4 6 2
2 4 6 5 7
1 3
2 5
*/

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k, u, w1, v, w2; i <= n; i++) {
		cin >> k >> u >> w1 >> v >> w2;
		nn = max(nn, max(u, v));
		e[u].push_back((node){v, w1 + w2});
		e[v].push_back((node){u, w1 + w2});
	}
	for (int i = 1; i <= nn; i++) {
		dij(i);
		for (int j = 1; j <= nn; j++) {
			ans[i][j] = w[i] + w[j] + dis[j];
		}
	}
	for (int i = 1, u, v; i <= q; i++) {
		cin >> u >> v;
		cout << ans[u][v] << '\n';
	}
	return 0;
}
