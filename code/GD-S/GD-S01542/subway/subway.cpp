#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>

#define repm(i, begin, end) for (indice i = (begin); i < indice(end); i += 1)
#define rep(i, n) repm(i, 0, n)

using namespace std;

using lld = int64_t;
using indice = int32_t;

using IdxVec = vector<indice>;

template<class T>
using CR = const T&;

#ifdef MDEBUG
template<class... Args>
void debug(CR<Args>... arg) {
	int _[] = { (cerr << arg << ' ', 0)... };
	cerr << '\n';
}
#else
#define debug(...) ((void)0)
#endif


constexpr lld inf = 1e18;

struct Matrix {
	indice n;
	vector<lld> data;
	
	Matrix(indice n_) : n(n_), data(n * n, +inf) { }
	
	lld& operator () (indice i, indice j) {
		return data[i * n + j];
	}
};

/*


bool operator < (Arc a, Arc b) {
	return a.w > b.w;
}

#include <queue>

using pqueue = priority_queue<Arc>; 

void dijkstra(indice s, Matrix& dis) {
	pqueue<DisInfo> q;
	
	auto update = [&](indice u, lld d){
		if (d < dis[u]) {
			dis[u] = d;
			q.push({u, d});
		}
	};
	
	while(!q.empty()) {
		indice u = q.top(); q.pop();
		
		rep(v, n) {
			update(v, dis[u] + w);
		}
	}
	
	
}
*/

void chmin(lld& x, lld val) {
	if (val < x) {
		x = val;
	}
}

/*
struct Arc {
	indice v;
	int w;
};

using Adj = vector<vector<Arc>>;
*/

struct Graph {
	struct Arc {
		indice v;
		int w;
		
		indice nexte;
	};
	
	vector<Arc> arcs;
	IdxVec head;
	
	void reserve(indice m) {
		arcs.reserve(m);
	}
	
	Graph(indice n) : head(n, -1) {
		
	}
	
	void add_arc(indice u, indice v, int w) {
		indice e = arcs.size();
		
		arcs.push_back({v, w, head[u]});
		head[u] = e;
	}
};

#define fore(e, u) for (indice e = g.head[u]; e != -1; e = g.arcs[e].nexte)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	indice c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	vector<int> w(m);
	
	rep(i, m) {
		cin >> w[i];
	}
	
	// station -> subway
	Graph g(m);
	//Adj adj(m);
	
	g.reserve(5e5);
	
	rep(i, n) {
		indice k;
		cin >> k;
		
		rep(j, k) {
			indice a; int t;
			cin >> a >> t;
			
			a -= 1;
			
			//adj[a].push_back({i, t});
			g.add_arc(a, i, t);
		}
	}
	
	//Floyd
	Matrix dis(n);
	
	rep(i, n) dis(i, i) = 0; 
	
	rep(i, m) {
		/*
		sort(adj[i].begin(), adj[i].end(), [](Arc a, Arc b) {
			return a.w < b.w;
		});
		*/
		
		//for (Arc arc1: adj[i]) {
		fore(e1, i) {
			auto arc1 = g.arcs[e1];
			
			indice v1 = arc1.v;
			int w1 = arc1.w;
			
			//for (Arc arc2: adj[i]) {
			fore(e2, i) {
				auto arc2 = g.arcs[e2];
				
				indice v2 = arc2.v;
				int w2 = arc2.w;
				
				if (v2 == v1) break;
				
				if (w1 + w2 < dis(v1, v2)) {
					dis(v1, v2) = dis(v2, v1) = w1 + w2;
				}
				
				//chmin(dis(v1, v2), (lld)w1 + w2);
			}
		}
	}
	
	rep(k, n) {
		rep(i, n) {
			rep(j, n) {
				chmin(dis(i, j), dis(k, i) + dis(k, j));
			}
		}
	}
	
	rep(i, q) {
		indice u, v;
		cin >> u >> v;
		
		u -= 1; v -= 1;
		
		lld ans = +inf;
		
		//for (Arc arc1: adj[u]) {
		fore(e1, u) {
			auto arc1 = g.arcs[e1];
			
			indice v1 = arc1.v;
			int w1 = arc1.w;
			
			//for (Arc arc2: adj[v]) {
			fore(e2, v) {
				auto arc2 = g.arcs[e2];
				
				indice v2 = arc2.v;
				lld w2 = arc2.w;
				
				//if (w1 + w2 > ans) break;
				
				//debug("to", v1, v2, w1, w2, dis(v1, v2));
				
				chmin(ans, (lld)w1 + w2 + dis(v1, v2));
			}
		}
		
		// 2e9
		ans += w[u] + w[v];
		
		cout << ans << '\n';
	}
	
	return 0;
}
