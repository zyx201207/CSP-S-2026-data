#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
typedef pair<long long, int> PLI;
vector<PLI> a[N];
vector<PLI> v[M];
long long w[M];
long long dist[M];
bool final[M];

void search(int s, int e) {
	priority_queue<PLI, vector<PLI>, greater<PLI>> q;
	memset(dist, 0x3f, sizeof(dist));
	memset(final, 0, sizeof(final));
	dist[s] = w[s];
	q.push({dist[s], s});
	while (!q.empty()) {
		PLI p = q.top();
		q.pop();
		int u = p.second;
		//printf("%d %d\n", u, final[u]);
		if (u == e) {
			printf("%lld\n", p.first + w[e]);
			return;
		}
		if (final[u]) continue;
		final[u] = true;
		//printf("u:%d %lld\n", u, p.first);
		for (PLI pp : v[u]) {
			int i = pp.second;
			long long d = p.first + pp.first;
			//printf("%d d:%lld\n", i, d);
			for (PLI h : a[i]) {
				int v = h.second;
				//printf("%d\n", v);
				if (final[v]) continue;
				if (d + h.first < dist[v]) {
					dist[v] = d + h.first;
					//printf("v:%d %lld\n", v, dist[v]);
					q.push({dist[v], v});
				}
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1;i <= m;i++) {
		scanf("%lld", w + i);
	}
	for (int i = 1;i <= n;i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1;j <= k;j++) {
			int a1, t;
			scanf("%d%d", &a1, &t);
			a[i].push_back({t, a1});
			v[a1].push_back({t, i});
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		search(x, y);
	}
	return 0;
}
