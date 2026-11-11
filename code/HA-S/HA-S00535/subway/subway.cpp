#include <bits/stdc++.h>
#define LL long long
#define PLI pair<LL, int>

using namespace std;

const int N = 510;
const int M = 5e5 + 10;
const int P = 1e6 + 10;
const int K = 2e6 + 10;
const LL INF = 1e18;

int c, n, m, d, q;
int e[K], ne[K], h[M], idx = 0;
LL v[M], w[K], dist[K], res[M];
bool vis[K];

struct Node {
	int id;
	LL val;
};
struct Question {
	int st, ed;
	int id;
} qry[M];
vector<int> s[N];
vector<Node> state[N];

inline bool cmp (Node a, Node b) {
	return a.id < b.id;
}

inline bool cmp1 (Question a, Question b) {
	return a.st < b.st;
}

inline void add (int a, int b, LL cc) {
	e[idx] = b, ne[idx] = h[a], w[idx] = cc, h[a] = idx ++;
}

priority_queue<PLI, vector<PLI>, greater<PLI> > pq;
inline void dijkstra (int x) {
	while (pq.size()) pq.pop();
	memset (dist, 0x7f, sizeof dist), memset (vis, 0, sizeof vis);
	pq.push({0, n + qry[x].st});
	dist[n + qry[x].st] = 0;
	while (pq.size()) {
		auto t = pq.top(); pq.pop();
		int u = t.second;
		if (vis[u]) continue ;
		vis[u] = 1;
		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];
			if (dist[v] > dist[u] + w[i]) {
				dist[v] = dist[u] + w[i];
				pq.push({dist[v], v});
			}
		}
	}
}

int main() {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);

	scanf ("%d %d %d %d %d", &c, &n, &m, &d, &q);
	memset (h, -1, sizeof h);
	for (int i = 1; i <= m; i ++) scanf ("%d", &v[i]);

	for (int i = 1, sz; i <= n; i ++) {
		scanf ("%d", &sz);
		for (int j = 1; j <= sz; j ++) {
			int st;LL tm;
			scanf ("%d %lld", &st, &tm);
			add (st + n, i, tm), add (i, st + n, tm);
//			cout << st + n << " " << i << " " << tm << endl;
			s[i].push_back(st - 1);
			state[i].push_back({st, tm});
		}
		sort (state[i].begin(), state[i].end(), cmp);
		sort (s[i].begin(), s[i].end());
	}

//	for (int i = 1; i <= m; i ++) sort (stop[i].begin(), stop[i].end());

//	cout << 1 << endl;

//	for (int i = 1; i <= n; i ++) {
//		for (auto u : s[i]) cout << u << " ";
//		cout << endl;
//	}

	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			LL minn = INF;
//			cout << minn << endl;
			for (int k = 0; k < s[i].size(); k ++) {
				int u = s[i][k];
				auto v = lower_bound (s[j].begin(), s[j].end(), u) - s[j].begin();
				if (v == *s[j].end()) continue;
//				cout << u << " " << s[j][v] << endl;
				if (u == s[j][v]) {
					minn = min (minn, state[j][v].val + state[i][k].val);
//					cout << u << " " << s[j][v] << " " << state[j][s[j][v]].val << " " << state[i][u].val << endl;
				}
//				cout << minn << endl;
//				cout << 1 << endl;
			}
			if (minn == INF) continue ;
//			cout << minn << endl;
//			cout << i << " " << j << " " << minn << endl;
			add (i, j, minn), add (j, i, minn);
		}
	}
	
//	cout << 1 << endl;
	
	for (int i = 1, st, ed; i <= q; i ++) {
		scanf ("%d %d", &st, &ed);
		qry[i] = {st, ed, i};
	}
	sort (qry + 1, qry + q + 1, cmp1);

	for (int i = 1; i <= q; i ++) {
		if (qry[i].st != qry[i - 1].st) dijkstra(i);
//		cout << n + qry[i].ed << endl;
		res[qry[i].id] = v[qry[i].st] + v[qry[i].ed] + dist[n + qry[i].ed];
	}

	for (int i = 1; i <= q; i ++) printf ("%lld\n", res[i]);
}
/*
*/