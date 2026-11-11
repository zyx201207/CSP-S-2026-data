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
int n;
ll D;
ll a[2000010];
std::vector<int> e[2000010];
int d[2000010];

inline int dfs(int x) {
	for (auto i : e[x]) {
		d[i] = std::min(d[i], d[x] + 1);
		dfs(i);
	}
}

int tot = 0;
inline void dfsfind(int x, int cnt, int j) {
	if (x == j) {
		if (cnt == d[j]) {
			tot++;
		}
		return;
	}
	for (auto i : e[x]) {
		dfsfind(i, cnt + 1, j);
	}
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> test >> T;
	while (T--) {
		cin >> n >> D;
		F(i, 1, n, 1) {
			cin >> a[i];
			e[i].clear();
		}
		F(i, 1, n, 1) {
			F(j, i + 1, n, 1) {
				if (a[j] - a[i] <= D) {
					e[i].push_back(j);
				} else {
					break;
				}
			}
		}
		int ans = 0;
		F(i, 1, n, 1) {
			fill(d + 1, d + n + 1, 1000000000);
			d[i] = 0;
			dfs(i);
			F(j, i + 1, n, 1) {
				tot = 0;
				dfsfind(i, 0, j);
				if (tot == 2) {
					ans++;
				}
			}
		}
		cout << ans << el;
	}
	r0;
}
/*

0 1
5 2
1 2 3 4 5
*/
