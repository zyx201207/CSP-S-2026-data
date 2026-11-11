// GZ-S00114 安顺市第二高级中学 程泊郡
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;

const int N = 2000010;
const ll INF = 1000000000000000000;

int c, n, m, d, q;
ll dis[N];
vector<pii> v[N];

ll dij(int x, int y) {
	for (int i = 1; i <= m * 2 + n + 10; i++) dis[i] = INF;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dis[x] = 0;
	pq.push({0, x});
	while (pq.size()) {
		pii p = pq.top();
		pq.pop();
		if (dis[p.second] != p.first) continue;
		for (int i = 0; i < (int)v[p.second].size(); i++) {
			pii e = v[p.second][i];
			if (dis[e.second] >= e.first + p.first) {
				dis[e.second] = e.first + p.first;
				pq.push({dis[e.second], e.second});
			}
		}
	}
	return dis[y];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		ll w;
		scanf("%lld", &w);
		v[i].push_back({w, m + i});
		v[m + i].push_back({w, i});
	}
	for (int i = 1, k; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int pd;
			ll w;
			scanf("%d%lld", &pd, &w);
			v[i + 2 * m].push_back({w, pd + m});
			v[pd + m].push_back({w, i + 2 * m});
		}
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", dij(x, y));
	}
	return 0;
}

