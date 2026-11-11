#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 505, maxm = 5e5 + 5, maxt = maxn + maxm;
int c, n, m, d, q, t, w[maxm], dis[maxt], firstt = -1, anc[maxt][20], dep[maxt];
bool checked[maxt], flag1 = true, flag2 = true;
struct edge {
	int u, value;
} fa[maxt]; vector<edge> e[maxt];
// c -> 测试点标号; n -> 地铁线路数; m -> 地铁站数; d -> 每个地铁站最多被几条线路经过; q -> 出行计划数

int dij(int vs, int vf) {
	for(int i = 1; i < vs; i++) dis[i] = LLONG_MAX;
	for(int i = vs + 1; i <= t; i++) dis[i] = LLONG_MAX;
	dis[vs] = 0;
	memset(checked, 0, sizeof checked);
	for(int i = 1; i <= t; i++) {
		int ind = 0, mn = LLONG_MAX;
		for(int j = 1; j <= t; j++) {
			if(!checked[j] && dis[j] < mn) {
				mn = dis[j];
				ind = j;
			}
		}
		checked[ind] = true;
		for(auto y : e[ind]) {
			dis[y.u] = min(dis[y.u], dis[ind] + y.value);
		}
	}
	return dis[vf];
}

int spfa(int vs, int vf) {
	for(int i = 1; i < vs; i++) dis[i] = LLONG_MAX;
	for(int i = vs + 1; i <= t; i++) dis[i] = LLONG_MAX;
	dis[vs] = 0;
	queue<pair<int, int>> q;
	q.push({vs, 0});
	while(!q.empty()) {
		auto curr = q.front();
		q.pop();
		for(auto y : e[curr.first]) {
			if(dis[y.u] != LLONG_MAX) continue;
			dis[y.u] = curr.second + 1;
			q.push({y.u, curr.second + 1});
		}
	}
	return dis[vf];
}

signed main() {
	(void)freopen("subway.in", "r", stdin);
	(void)freopen("subway.out", "w", stdout);
	(void)scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	t = n + m;
	for(int i = 1; i <= m; i++) (void)scanf("%lld", &w[i]);
	for(int i = 1; i <= n; i++) {
		int k;
		(void)scanf("%lld", &k);
		if(k > 2) flag1 = false;
		for(int j = 1; j <= k; j++) {
			int a, t;
			(void)scanf("%lld %lld", &a, &t);
			a += n;
			e[i].push_back({a, t});
			e[a].push_back({i, t});
			if(firstt == -1) firstt = t;
			else if(t != firstt) flag2 = false;
		}
	}
	while(q--) {
		int x, y;
		(void)scanf("%lld %lld", &x, &y);
		int ans = 0;
		if(flag2) {
			ans = spfa(x + n, y + n) * firstt;
		} else {
			ans = dij(x + n, y + n);
		}
		(void)printf("%lld\n", (ans + w[x] + w[y]));
	}
	return 0;
}
