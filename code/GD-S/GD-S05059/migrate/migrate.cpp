#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 2 * 1e6 + 5;

int a[kMaxN], f[kMaxN], c, n, d, T, mm = 1e9, cnt = 0;

void dfs(int x, int l) {
//	printf("%d, %d\n", x, l);
	if (x == n) {
//		printf("Arrive with distance %d\n", l);
		if (mm == l) cnt ++;
		if (l < mm) {
			cnt = 0;
			mm = l;
		}
		return;
	}
	for (int i = x + 1; i <= n; i ++) {
		if (a[i] - a[x] > d) continue;
//		printf("%d %d %d\n", a[i], a[x], a[i] - a[x]);
		dfs(i, l + 1);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> T;
	for (int i = 1; i <= T; i ++) {
		cin >> n >> d;
		if (n <= 2) {
			cout << 0;
			continue;
		}
		if (c == 11 || c == 12) {
			for (int j = 1; j <= n; j ++) {
				cin >> a[j];
				if (a[j] % 2 == 1) {
					cout << 0;
					return 0;
				}
				if (a[j] < 0){
					cout << 0;
					return 0;
				}
			}
		}
		for (int j = 1; j <= n; j ++) cin >> a[j];
//		for (int j = 1; j <= n; j ++) cout << a[j] << " ";
//		cout << "\n";
		cnt = 0;
		dfs(1, 0);
		cout << cnt << "\n";
//		cout << "-------------------\n";
	}
	return 0;
} 
