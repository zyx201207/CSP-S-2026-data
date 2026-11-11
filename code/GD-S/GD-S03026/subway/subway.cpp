#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define st first
#define nd second

struct Edge { int u, v, w; };
struct Node { int st, nd, val; };
struct TT { int x, d; };
bool operator < (TT x, TT y) { return x.d > y.d; }
int c, n, m, d, q;
const int M = 5e5 + 7;	// 地铁站数
const int N = 507;	// 线路数量 
vector<int> w(M);	// 出入站开销（最后加） 
vector<pair<int, int>> ind[M];	// 每个点出现在那些位置
vector<int> v;	// 离散化数组 
int f (int x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }
vector<Edge> edge;	// 边集 
vector<Node> _map[M];

void debug () {
	for (int i = 0; i < M; ++i) {
		if (ind[i].empty()) continue;
		cerr << i << ": ";
		for (auto &j: ind[i]) {
			cerr << '(' << j.st << ", " << j.nd << "), ";
		}
		cerr << endl;
	}
	cerr << endl;
	for (int i = 0; i < M; ++i) {
		if (_map[i].empty()) continue;
		cerr << i << "-> ";
		for (auto &j: _map[i]) {
			cerr << '(' << j.st << ", " << j.nd << "), ";
		}
		cerr << endl;
	}
}


const int INF = (1LL << 60);
vector<int> dist(M, INF);
int dij (int x, int y, int ques) {
	priority_queue<TT> q;
	int S = 0, T = 5e5 + 3;
	for (auto &i: ind[x]) {
		_map[S].push_back({i.st, i.nd, ques});
	}
	for (auto &i: ind[y]) {
		_map[i.st].push_back({T, i.nd, ques});
	}
	for (auto &i: dist) i = INF;
	q.push({S, 0});	dist[S] = 0;
	while (!q.empty()) {
		int u = q.top().x;	q.pop();
		for (auto &i: _map[u]) {
			int v = i.st, dis = i.nd, val = i.val;
			if (val != 0 && val != ques) continue;
			if (dist[v] == INF) {
				dist[v] = dist[u] + dis;
				q.push({v, dist[v]});
			} 
			else if (dist[v] > dist[u] + dis) {
				dist[v] = dist[u] + dis;
			}
		}
	}
	_map[S].clear();
	for (auto &i: ind[y]) {
		_map[i.st].pop_back();
	}
//	debug();
	return dist[T];
}

signed main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		int k;	cin >> k;
		int las = -1;
		for (int j = 1; j <= k; ++j) {
			int a, t;	cin >> a >> t;
			if (las != -1) 
				edge.push_back({las + i * m, a + i * m, 0});
			las = a;
			ind[a].push_back({a + i * m, t});
			v.push_back(a + i * m);
		}
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto &i: edge) {
		i.u = f(i.u) + 1, i.v = f(i.v) + 1;
		_map[i.u].push_back({i.v, i.w, 0});
		_map[i.v].push_back({i.u, i.w, 0});
	}
	for (int i = 1; i <= m; ++i) {
		for (auto &j: ind[i]) {
			j.st = f(j.st) + 1;
		}
		
		for (int j = 0; j < ind[i].size(); ++j) {
			for (int k = j + 1; k < ind[i].size(); ++k) {
				auto &jt = ind[i][j], &kt = ind[i][k];
				_map[jt.st].push_back({kt.st, jt.nd + kt.nd, 0});
				_map[kt.st].push_back({jt.st, jt.nd + kt.nd, 0});
			}
		}
	} 
//	debug();
	for (int i = 1; i <= q; ++i) {
		int x, y;	cin >> x >> y;
		cout << dij(x, y, q) + w[x] + w[y] << endl;
	}
	return 0;
}

