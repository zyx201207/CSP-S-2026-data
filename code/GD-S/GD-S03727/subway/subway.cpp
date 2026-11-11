#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5 * 5 + 5;
long long c, n, m, d, q;
long long w[N];
vector<pair<long long, long long> > b[2 * N];
long long dis[2 * N];
long long dij(long long x, long long y) {
	for (int i = 1; i <= m + n; i++) {
		dis[i] = INT_MAX;
	}
	dis[x] = 0;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
	pq.push({0, x});
	bool bo[2 * N];
	memset(bo, false, sizeof(bo));
	while (!pq.empty()) {
		long long t1 = pq.top().first, t2 = pq.top().second;
		pq.pop();
		if (bo[t2] == true) continue;
		bo[t2] = true;
//		cout << t2 << " " << dis[t2] << "\n";
		for (auto i : b[t2]) {
			if (t1 + i.second < dis[i.first]) pq.push({t1 + i.second, i.first}), dis[i.first] = t1 + i.second;
		}
	}
	return dis[y] + w[x] + w[y];
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		long long k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			long long a, t;
			cin >> a >> t;
			b[i + m].push_back({a, t});
			b[a].push_back({i + m, t});
		}
	}
	for (int i = 1; i <= q; i++) {
		long long x, y;
		cin >> x >> y;
		cout << dij(x, y) << "\n";;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
