#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N], mask[N];
int g[N][50], vis[50];
int n, m, mx;

void check () {
	for (int i = 1;i <= n;i ++) {
		cout << vis[i] << " ";
	}
	cout << endl;
}

int main () {
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	for (int i = 1;i <= n;i ++) {
		long long x = a[i];
		int w = 1;
		while (x > 0) {
			if (x & 1 == 1) {
				g[i][w] = 1;
			} else {
				g[i][w] = 0;
			}
			w ++;
			x >>= 1;
		}
		mx = max(mx, w);
	}
//	for (int i = 1;i <= n;i ++) {
//		for (int j = 1;j <= mx;j ++) {
//			cout << g[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
	for (int i = mx;i >= 1;i --) {
		int s = 0;
		vector<int> v(n + 5);
		for (int j = n;j >= 1;j --) {
			if (vis[j]) continue;
			if (g[j][i] == 1) {
				s ++;
				v[j] = 1;
			}
		}
		if (s >= m) {
			for (int j = 1;j <= n;j ++) {
				if (v[j]) continue;
				vis[j] = 1;
			}
			//check();
		}
		if (s == m) break;
	}
	int ans = -1, s = 0;
	for (int i = n;i >= 1;i --) {
		if (!vis[i]) {
			s ++;
			if (ans == -1) ans = a[i];
			else ans &= a[i];
			if (s == m) break;
		}
	}
	if (ans == -1) ans = 0;
	cout << ans << endl;
	
	return 0;
} 
/*
12 6
68 458 15625 45896 458842 6548 245 3315 4962 468743 2645 1578
*/
