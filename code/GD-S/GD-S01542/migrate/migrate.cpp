#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>
#include <deque>

#define repm(i, begin, end) for (indice i = (begin); i < indice(end); i += 1)
#define rep(i, n) repm(i, 0, n)

using namespace std;

using lld = int64_t;
using indice = int32_t;

using IdxVec = vector<indice>;
using BoolVec = vector<char>;

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

constexpr lld inf = 1e9;

struct Arc {
	indice u;
	indice dis;
};

bool operator < (Arc a, Arc b) {
	return a.dis > b.dis;
}

using Adj = vector<vector<Arc>>;

#include <queue>

using pqueue = priority_queue<Arc>; 

lld dijkstra(indice s, Adj& adj) {
	const indice n = adj.size();
	
	pqueue q;
	
	IdxVec dis(n, +inf);
	vector<lld> cnts(n, 0);
	
	auto update = [&](indice u, indice d, lld fcnt){
		if (d < dis[u]) {
			dis[u] = d;
			cnts[u] = 0;
			
			q.push({u, d});
		}
		
		if (d == dis[u]) {
			cnts[u] += fcnt;
		}
	};
	
	update(s, 0, 1);
	
	BoolVec vis(n, false);
	
	while(!q.empty()) {
		indice u = q.top().u; q.pop();
		
		if (vis[u]) continue;
		vis[u] = true;
		
		for (Arc arc: adj[u]) {
			indice v = arc.u;
			int w = arc.dis;
			
			update(v, dis[u] + w, cnts[u]);
		}
	}
	
	indice res = 0;
	
	indice o = n / 2;
	
	repm(i, o, n) {
		if (cnts[i] == 2) {
			res += 1;
		}
	}
	
	return res;
}

lld bfs01(indice s, Adj& adj) {
	const indice n = adj.size();
	
	deque<Arc> q;
	
	IdxVec dis(n, +inf);
	vector<lld> cnts(n, 0);
	
	auto update = [&](indice u, indice d, bool b, lld fcnt){
		if (d < dis[u]) {
			dis[u] = d;
			cnts[u] = 0;
			
			if (b == 1)
				q.push_back({u, d});
			else 
				q.push_front({u, d});
		}
		
		if (d == dis[u]) {
			cnts[u] += fcnt;
		}
	};
	
	update(s, 0, 0, 1);
	
	BoolVec vis(n, false);
	
	while(!q.empty()) {
		indice u = q.front().u; q.pop_front();
		
		if (vis[u]) continue;
		vis[u] = true;
		
		for (Arc arc: adj[u]) {
			indice v = arc.u;
			int w = arc.dis;
			
			update(v, dis[u] + w, w, cnts[u]);
		}
	}
	
	indice res = 0;
	
	indice o = n / 2;
	
	repm(i, o, n) {
		if (cnts[i] == 2) {
			res += 1;
		}
	}
	
	return res;
}

using u32 = uint32_t;

u32 bit_width(u32 x) {
	return 32 - __builtin_clz(x); 
}

void Case3() {
	indice n; lld d;
	cin >> n >> d;
	
	vector<lld> x(n);
	
	rep(i, n) {
		cin >> x[i];
	}
	
	if (n < 2) {
		cout << "0\n";
		return;
	}
	
	indice k = bit_width(n - 1);
	u32 o = 1 << k;
	
	Adj adj(2 * o);
	
	rep(i, o) {
		adj[i].push_back({i * 2 + 0, 0});
		adj[i].push_back({i * 2 + 1, 0});
	}
	
	rep(i, n) {
		indice r = 0;
		
		while(r < n && x[r] - x[i] <= d) {
			r += 1;
		}
		
		indice l = o + (i + 1);
		r += o;
		
		//debug("p", i, l, r);
		
		while(l < r) {
			if (l & 1) adj[o + i].push_back({l++, 1});
			if (r & 1) adj[o + i].push_back({--r, 1});
			
			l >>= 1;
			r >>= 1;
		}
	}
	
	lld ans = 0;
	
	rep(i, n) {
		ans += bfs01(o + i, adj);
	}
	
	cout << ans << '\n';
	return;
}

void SpecA() {
	indice n; lld d;
	cin >> n >> d;
	
	vector<lld> x(n);
	
	rep(i, n) {
		cin >> x[i];
	}
	
	if (n < 2) {
		//debug("n < 2");
		cout << "0\n";
		return;
	}
	
	lld p0 = x[1] - x[0];
	
	if (d < 2 * p0) {
		//debug(p0, "<", d, "* 2");
		cout << "0\n";
		return;
	}
	
	lld q = d / p0;
	
	lld ans = n - (2 * q - 1);
	
	cout << max(0ll, ans) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	indice c, t;
	cin >> c >> t;
	
	if (/*c == 0 ||*/ c == 11 || c == 12) {
		rep(i, t) {
			SpecA();
		}
		
		return 0;
	}
	
	rep(i, t) {
		Case3(); 
	}
	
	return 0;
}
