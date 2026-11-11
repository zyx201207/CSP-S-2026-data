#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using cint = const int;
using cLL = const long long;
using uint = unsigned int;
using uLL = unsigned long long;

#define N 2000005
#define base 137
#define inf 1000000007
#define mod 998244353

const double PI = acos(-1.0);

int n, k;
vector<int> vt[N];


int c[N];
bool vis[N];
int cnt = 0;
bool check() {
	cnt = 0;
	memset(vis, false, sizeof(*vis) * (n + 1));
	for (int i = 1; i <= n; ++i) {
		auto dfs = [&](auto &dfs, cint p) -> void {
			vis[p] = true;
			for (auto i : vt[p])
				if (c[i] == 1 && !vis[i])
					dfs(dfs, i);
			return;
		};
		if (!vis[i] && c[i] == 1) ++cnt,
			dfs(dfs, i);
	}
	return cnt <= 2;
}

int ans;
int dis[N];
void dfs(cint p, cint r) {
	if (p == n + 1) {
		if (r) return;
		if (check() == false) return;
		memset(dis, -1, sizeof(*dis) * (n + 1));
		queue<int> q;
		for (int i = 1; i <= n; ++i)
		if (c[i] == 1)
			dis[i] = 0, q.emplace(i);
		for (int x; !q.empty(); ) {
			x = q.front(), q.pop();
			for (auto i : vt[p])
				if (dis[i] == -1)
					dis[i] = dis[x] + 1, q.emplace(i);
		}
		ans = min(ans, *max_element(dis + 1, dis + n + 1));
		return;
	}
	c[p] = 0, dfs(p + 1, r);
	if (r > 0)
		c[p] = 1, dfs(p + 1, r - 1);
	return;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (; t--; ) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
			vt[i].clear();
		for (int i = n, x, y; --i; ) {
			cin >> x >> y;
			vt[x].emplace_back(y);
			vt[y].emplace_back(x);
		}
		if (c <= 3) {
			ans = inf;
			dfs(1, k);
			;
		}
		cout << ans << '\n';
	}
	return 0;
}
/*

0 1
5 2
1 2
2 3
3 4
4 5

*/
