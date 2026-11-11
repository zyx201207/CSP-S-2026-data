#include <bits/stdc++.h>
#define el "\n"
#define sp " "
#define r0 return 0
#define fi first
#define se second
#define F(i, a, b, c) for (int i = a; i <= b; i += c)

using namespace std;
typedef long long ll;
typedef string str;

int test, T;
int n, k;
std::vector<int> e[110], s;
int g[110];
std::bitset<110> f, b;
int ans;
int cnt = 0;
std::queue<int> q;
int d[110];

inline void dfsg(int x) {
	g[x] = cnt;
	for (auto i : e[x]) {
		if (f[i] && !g[i]) {
			dfsg(i);
		}
	}
}

inline void dfs(int x, int tot) {
	if (x == n + 1) {
		if (tot != k) {
			return;
		}
		F(i, 1, n, 1) {
			g[i] = 0;
		}
		cnt = 0;
		F(i, 1, n, 1) {
			if (f[i] && !g[i]) {
				cnt++;
				dfsg(i);
			}
		}
		if (cnt > 2) {
			return;
		}
		s.clear();
		F(i, 1, n, 1) {
			if (f[i]) {
				s.push_back(i);
			}
		}
		int ma = -1;
		F(i, 1, n, 1) {
			int mi = 1000000000;
			for (auto j : s) {
				b.reset();
				while (!q.empty()) {
					q.pop();
				}
				q.push(i);
				d[i] = 0;
				b[i] = 1;
				while (!q.empty()) {
					int x = q.front();
					q.pop();
					for (auto y : e[x]) {
						if (!b[y]) {
							b[y] = 1;
							q.push(y);
							d[y] = d[x] + 1;
						}
					}
				}
				mi = std::min(mi, d[j]);
			}
			ma = std::max(ma, mi);
		}
		ans = std::min(ans, ma);
		return;
	}
	if (tot + n - x + 1 < k) {
		return;
	}
	if (tot + n - x + 1 == k) {
		F(i, x, n, 1) {
			f[i] = 1;
		}
		dfs(n + 1, k);
		return;
	}
	F(i, 0, 1, 1) {
		f[x] = i;
		dfs(x + 1, tot + i);
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> test >> T;
	while (T--) {
		cin >> n >> k;
		F(i, 1, n, 1) {
			e[i].clear();
		}
		F(i, 1, n - 1, 1) {
			int x, y;
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		ans = 1000000000;
		dfs(1, 0);
		cout << ans << el;
	}
	r0;
}
