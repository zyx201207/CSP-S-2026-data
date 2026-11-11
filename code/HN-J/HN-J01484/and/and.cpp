#include<bits/stdc++.h>

using ll = long long;
#define f first
#define s second
const int inf = (1 << 30) - 1;
const ll INF = 1ll << 60;

const int N = 2e5 + 10;
int n, m;
ll ans, a[N];
bool vis[N];
std::vector<int> pos[N];
std::vector<std::pair<std::vector<int>, int>> id[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	for (int i = 30; i >= 0; i--) for (int j = 1; j <= n; j++) if ((a[j] >> i) & 1) pos[j].push_back(i);
	for (int i = 30; i >= 0; i--) for (int j = 1; j <= n; j++) if ((a[j] >> i) & 1) id[i].push_back({pos[j], j});
	for (int i = 30; i >= 0; i--) std::sort(id[i].begin(), id[i].end(), std::greater<std::pair<std::vector<int>, int>>());
	for (int i = 30; i >= 0; i--) if (id[i].size() >= m) {
		for (auto &v : id[i]) if (m) vis[v.s] = true, m--;
		break;
	}
	ans = (1 << 30) - 1;
	for (int i = 1; i <= n; i++) if (vis[i]) ans &= a[i];
	std::cout << ans << '\n';
	return 0;
} 
