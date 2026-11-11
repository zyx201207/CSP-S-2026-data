#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 1000;

//struct Node {
//	vector<int> l;
//} nodes[kMaxN];

int c, n, m, d, q;
long long s[kMaxN][kMaxN], a[kMaxN];
//int sl[kMaxN][kMaxN];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= m; j ++) s[i][j] = 1e9;
	}
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
//		printf("\nx:%d\n", x);
		int prey = -1, prev = -1;
		for (int j = 1; j <= x; j ++) {
			long long y, v;
			cin >> y >> v;
			if (j != 1) {
//				if (sl[prey][y] == 0) sl[prey][y] = prev + v;
//				if (sl[prey][y] != 0 && s[prey][y] > prev+v) {
//					sl[prey][y] += v;
//				}
				s[prey][y] = min(s[prey][y], prev + v);
				s[y][prey] = min(s[y][prey], prev + v);
//				s[prey][y] = min(s[prey][y], (long long)sl[prey][y]);
//				s[y][prey] = min(s[y][prey], (long long)sl[prey][y]);
			}
			prey = y;
			prev = v;
		}
	}
//	for (int i = 1; i <= m; i ++) {
//		for (int j = 1; j <= m; j ++) {
//			cout << s[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "--------------------\n";
	int route = -1;
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (s[j][i] == 1e9 || i == j) continue;
			for (int k = 1; k <= m; k ++) {
				if (s[i][k] == 1e9 || j == k) continue;
				if (s[j][k] > s[j][i] + s[i][k]) {
					s[j][k] = s[j][i] + s[i][k];
//					if (sl[j][i] != s[i][k]) {
//						cout << "Change!\n";
//					}
//					s[j][j] = s[j][i] + s[i][k];	
				}
			}
		}
	}
//	cout << "Dis\n";
//	for (int i = 1; i <= m; i ++) cout << a[i] << " ";
//	cout << "-------------------\n";
//	for (int i = 1; i <= m; i ++) {
//		for (int j = 1; j <= m; j ++) {
//			cout << s[i][j] << " ";
//		}
//		cout << "\n";
//	}
	for (int i = 1; i <= q; i ++) {
		long long x, y;
		cin >> x >> y;
		cout << s[x][y] + a[x] + a[y] << "\n";
	}
	return 0;
}
