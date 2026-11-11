#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int inf = 1e9;

struct dsu {
	int n; vector<int> f;
	void init(int _n) {
		n=_n, f.assign(n,-1);
	}
	
	int find(int x) {
		while(x!=f[x]) x=f[x]=f[f[x]];
		return x;
	}
};

void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v, u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<vector<int>> dis(n);
	for (int s = 0; s < n; s++) {
		dis[s].assign(n, -1); dis[s][s] = 0;
		queue<int> q; q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto v : g[u])
				if (dis[s][v] == -1) {
					dis[s][v] = dis[s][u] + 1;
					q.push(v);
				}
		}
	}
	
	auto calc = [&](const vector<int>& s) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int now = inf;
			for (auto j : s) now=min(now, dis[i][j]);
			ans=max(ans, now);
		}
		return ans;
	};
	
	auto check = [&](const vector<int>& s) {
		dsu uf; uf.init(n);
		for (auto u:s) uf.f[u]=u;
		
		set<int> tmp(s.begin(),s.end());
		for (auto u:s)
			for (auto v:g[u])
				if (tmp.count(v)) {
					int fu = uf.find(u),fv = uf.find(v);
					if (fu != fv) uf.f[fu]=fv;
				}
		int cnt=0;
		for(auto u:s) cnt+=uf.find(u)==u;
		return cnt<=2;
	};
	
	int ans = inf;
	auto search = [&](auto self, int i, const vector<int>& s) -> void {
		if (i == n) {
			if (check(s)) ans=min(ans, calc(s));
			return;
		}
		self(self, i + 1, s);
		if (s.size() < k) {
			auto ns = s;
			ns.push_back(i);
			self(self, i+1, ns);
		}
	};
	search(search,0,vector<int>{});
	cout << ans << '\n';
}

int c, t;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> t;
	while (t--) solve();
	
	return 0;
}

