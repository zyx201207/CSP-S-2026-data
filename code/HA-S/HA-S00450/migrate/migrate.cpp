#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int T;
int n;
int res[N];
ll d, a[N];

inline 
void init() {
	
}

inline 
int dfs1(int x, int y) {
	while (y --) {
		int to = 0;
		for (to = x; to <= n && a[to] - a[x] <= n; to ++);
		x = to - 1;
	}
	return x;
}

int dfs2(int x, int y, int sum) {
	if (sum == 0) return 1;
	int cnt = 0;
	for (int i = x + 1; i <= n && a[i] - a[x] <= d; i ++) {
		cnt += dfs2(i, y, sum - 1);
		if (cnt > 2) return 114514;
	}
	return cnt;
}

inline 
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		bool flag = 0;
		for (int j = 1; j <= n; j ++) {
			int lst = dfs1(i, j);
			int nd = dfs2(i, lst, j);
			if (nd == 2) {
				flag = 1;
				break;
			}
			if (lst == n) break;
		}
//		for (int j = i + 1; j <= n; j ++) {
//			memset(res, 0, sizeof res);
//			int nd = dfs1(i, j); // O(n)
//			dfs2(i, nd);
//			for (int k = 1; k <= n; k ++) if (res[k] == 2) {
//				flag = 1;
//				break;
//			}
//			if (flag) break;
//		}
		ans += flag;
	}
	cout << ans - 1 << "\n";
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> T >> T;
	while (T --) init(), solve();
	
	return 0;
}

