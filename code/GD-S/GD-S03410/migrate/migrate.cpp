#include <bits/stdc++.h>
#define PII pair<int, int>
#define xf first
#define ys second
#define int long long
using namespace std;
const int N = 3e3 + 5;
const int INF = 1e9;
int x[N];
int f[N][N]; // length
int g[N][N]; // ways
void solve() {
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int len = INF;
			int way = 0;
			queue<PII> q;
			while (!q.empty()) {
				int x
			}
			if (way == 2) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
} 
