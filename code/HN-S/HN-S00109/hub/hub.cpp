#include <bits/stdc++.h>
using namespace std;
#define ll long long 


#define cout fout
#define cin fin
ifstream fin("hub.in");
ofstream fout("hub.out");

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
	int n;
	vector <int> f, sz;
	DSU(){}
	DSU(int _n) {
		n = _n + 1;
		f.resize(n + 1);
		sz.resize(n + 1, 1);
		for (int i = 1; i <= n; i++) {
			f[i] = i;
		}
	}
	int find(int x) {
		return f[x] == x ? x : find(f[x]);
	}
	bool un(int l, int r) {
		l = find(l), r = find(r);
		if (l == r) return 0;
		if (sz[l] > sz[r]) swap(l, r);
		// l < r
		f[l] = r;
		sz[r] += sz[l];
		return 1;
	}
	
};

int c, t;
int p = 0;
vector <int> dis;
vector <vector<int> > ve;
void dfs(int u, int fa) {
	if (dis[p] < dis[u]) p = u;
	for (auto v : ve[u]) {
		if (v == fa) continue;
		dis[v] = dis[u] + 1;
		dfs(v, u);
	}
}
void solve() {
	int n, k;
	cin >> n >> k;
	vector <vector<int> > (n + 1).swap(ve);
	vector <int> (n + 1).swap(dis);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	dis[1] = 0;
	dfs(1, 1);
	int l = p;
	dis[l] = 0;
	dfs(l, l);
	int r = p, len = dis[p];
	auto dis1 = dis;
	dfs(r, r);
	vector <int> vis(n + 1);
	for (int i = 1; i <= n; i++) {
		if(dis[i] + dis1[i] == len) {
			vis[i] = 1;
		}
	}
	
	vector <int> vh(n + 1, inf), rd(n + 1);
	vh[0] = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		rd[i] = ve[i].size();
		if (ve[i].size() == 1) q.push(i), vh[i] = 0;
	}
	vector <vector<int> > vl(n + 1);
	while (q.size()) {
		auto u = q.front(); q.pop();
		vl[vh[u]].push_back(u);
		for (auto v : ve[u]) {
			vh[v] = min(vh[v], vh[u] + 1);
			if (--rd[v] == 1) {
				q.push(v);
			} 
		}
	}
	
	
	int mxh = *max_element(vh.begin(), vh.end());
//	cout << mxh << '\n';
	{
		int l = 0, r = mxh;
		while (l < r) {
			int mid = l + r >> 1;
			if ([&](int mid) -> bool { 
				DSU dsu(n + 1);
				vector<int> used(n + 1);
				int cnt = 0, cc = 0;
				for (int i = mid; i <= mxh; i++) {
					cnt += vl[i].size();
					if (cnt > k) return 0;
					for (auto u : vl[i]) {
						used[u] = 1;
						for (auto v : ve[u]) {
							if (used[v]) cc += dsu.un(u, v);
						}
					}
					if (cnt - cc <= 2 && i >= mxh - mid) return 1;
				}
				return 0;
			}(mid) ) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		
		cout << l << '\n';
	}
	
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> t;
	while (t--) {
		solve();
	}
	
} 



