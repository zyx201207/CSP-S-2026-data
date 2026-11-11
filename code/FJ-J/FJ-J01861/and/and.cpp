#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, cnt, ans, sum;
int a[N], p[N];
bool st[35][N], b[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int maxn = 1;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		int al = a[i];
		cnt = 0;
		while (al) {
			st[cnt][i] = al % 2;
			al /= 2;
			cnt ++ ;
		}
		maxn = max(maxn, cnt);
	}
	p[0] = 1;
	for (int i = 1; i <= 30; i ++ ) {
		p[i] = p[i - 1] * 2;
	}
	memset(b, 1, sizeof b);
	for (int i = 30; i >= 0; i -- ) {
		sum = 0;
		for (int j = 1; j <= n; j ++ ) {
			if (st[i][j] && b[j]) sum ++ ;
		}
		if (sum >= m) {
			ans += p[i];
			for (int j = 1; j <= n; j ++ ) {
				if (st[i][j] && b[j]) continue;
				else b[j] = 0;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
