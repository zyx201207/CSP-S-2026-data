#include<bits/stdc++.h>
#define ls (x << 1)
#define rs (x << 1 | 1)
#define int ll
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int N = 2e6 + 5;
const db EPS = 1e-6;
const int MOD = 998244353;
const ull P = 33550337;

inline int lowbit(int x) {
	return (x & (-x));
}

ll c, T, n, d, x[N], ans;
ll dist[5005][5005];
int way[5005][5005];

inline void solveA() {
	
	return;
}

inline void solve123456() {
	int J = 2;
	for (int i = 1; i < n; i++) {
		while (x[J] - x[i] <= d) J++;
		for (int j = J; j <= n; j++) {
			if (x[j] - x[i] > 2*d) break;
			int cnt = 0;
			for (int k = i + 1; k < j; k++) {
				if (x[k] - x[i] > d) continue;
				if (x[j] - x[k] > d) continue;
				cnt++;
				if (cnt > 2) break;
			}
			if (cnt == 2) ans++;
		}
	}
	
//	for (int i = 0; i <= n + 3; i++) {
//		for (int j = 0; j <= n + 3; j++) {
//			dist[i][j] = (LLONG_MAX >> 1);
//			if (i == j) dist[i][j] = 0;
//		}
//	}
//	
//	for (int u = 1; u < n; u++) {
//		for (int v = u + 1; v <= n; v++) {
//			if (x[v] - x[u] > d) break;
//			dist[u][v] = x[v] - x[u];
//		}
//	}
//	
//	for (int k = 1; k <= n; k++) {
//		for (int i = 1; i < k; i++) {
//			for (int j = k + 1; j <= n; j++) {
//				int old = dist[i][j];
//				int cur = dist[i][k] + dist[k][j];
//				if (cur < old) {
//					cout << "i == " << i << "; j == " << j << "; k == " << k << "\n";
//					dist[i][j] = cur;
//					way[i][j] = 1;
//					cout << "way[" << i << "][" << j << "] == " << way[i][j] << "\n";
//				} else if (cur == old) {
//					cout << "i == " << i << "; j == " << j << "; k == " << k << "\n";
//					way[i][j]++;
//					cout << "way[" << i << "][" << j << "] == " << way[i][j] << "\n";
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << (dist[i][j] < 1000 ? to_string(dist[i][j]) : "?") << " ";
//		}
//		cout << "\n";
//	}
//	cout << "way\n";
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << (way[i][j] < 1000 ? to_string(way[i][j]) : "?") << " ";
//		}
//		cout << "\n";
//	}
//	for (int i = 1; i < n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			if (way[i][j] == 2) {
//				ans++;
//			}
//		}
//	}
	
	return;
}

signed main() {
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		ans = 0;
		x[0] = x[n + 1] = x[n + 2] 
		= x[n + 3] = x[n + 4] = x[n + 5] 
		= 0;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (c == 11 || c == 12) {
			solveA();
		} else if (0 <= c && c <= 6) {
			solve123456();
		}
		cout << ans << "\n";
	}
	
	return 0;
}
