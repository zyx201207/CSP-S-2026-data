#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

const int N = 2e6 + 7;

int n, k;
std::vector<std::pair<int, int>> g[N];

int fa[N], *tf[N], *ft[N];
void dfs(int u) {
	for(auto& [v, $]: g[u]) {
		if(v == fa[u]) tf[u] = &$;
		else fa[v] = u, ft[v] = &$, dfs(v);
	}
}

int dep[N], siz[N];
std::basic_string<int> mem;
void collect(int u, int fa) {
	mem += u, siz[u] = 1;
	for(auto& [v, $]: g[u]) {
		if(v == fa || $) continue;
		collect(v, u), siz[u] += siz[v];
	}
}
void calcdep(int u, int fa) {
	dep[u] = 0;
	for(auto& [v, $]: g[u]) {
		if(v == fa || $) continue;
		calcdep(v, u);
		dep[u] = std::max(dep[v]+1, dep[u]);
	}
}
int maxd, index;
void findmax(int u, int fa, int dist) {
	if(dist > maxd) maxd = dist, index = u;
	for(auto& [v, $]: g[u]) {
		if(v == fa || $) continue;
		findmax(v, u, dist+1);
	}
}
int target, result[N];
bool track(int u, int fa, int dist) {
	result[dist] = u;
	if(u == target) return 1;
	for(auto& [v, $]: g[u]) {
		if(v == fa || $) continue;
		if(track(v, u, dist+1)) return 1;
	}
	return 0;
}

const int inf = 1e9;
int tmp[N], tmp1[N], tmp2[N];

void _work(int u, int *tar) {
	mem.clear(), collect(u, 0);
	maxd = -1, findmax(u, 0, 0); int v = index;
	maxd = -1, findmax(v, 0, 0), target = index, track(v, 0, 0);
	int x = result[maxd/2];
	calcdep(x, 0);
	for(int i = 0; i <= siz[u]; ++i) tar[i] = 0;
	for(int y: mem) ++tar[dep[y]];
	for(int i = siz[u]-1; ~i; --i) tar[i] += tar[i+1];
}

int work(int u) { // break u-fa
	*tf[u] = *ft[u] = 1;

	_work(u, tmp1), _work(fa[u], tmp2);
	int ans = 0;
	// std::cerr << "work " << u << "-" << fa[u] << "\n";
	for(int i = 0; i <= std::max(siz[u], siz[fa[u]]); ++i) {
		int res = 0;
		if(i <= siz[u]) res += tmp1[i];
		if(i <= siz[fa[u]]) res += tmp2[i];
		if(res <= k) { ans = i; break; }
		// std::cerr << i << ' ' << tmp1[i] << ' ' << tmp2[i] << "\n";
	}

	*tf[u] = *ft[u] = 0;

  // std::cerr << "work " << u << ' ' << ans << "\n";
	return ans;
}

int c;

inline void solve() {
	std::cin >> n >> k;
	for(int i = 1; i <= n; ++i) g[i].clear();
	for(int x, y, t = n; --t; ) {
		std::cin >> x >> y;
		g[x].emplace_back(y, 0);
		g[y].emplace_back(x, 0);
	}
	dfs(1);

	int ans = 1e9;
	for(int i = 2; i <= n; ++i) {
		ans = std::min(ans, work(i)); 
	}
	std::cout << ans << "\n";
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int t; std::cin >> c >> t; 
	while(t--) solve();
}
