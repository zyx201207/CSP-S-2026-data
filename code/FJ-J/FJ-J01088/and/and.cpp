#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, a[N], b[35][N], c[N];
bool cmp(int a, int b) {
	return a > b;
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	freopen("and5.in", "r", stdin);
//	freopen("ands.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int tt = 0;
		int op = a[i];
		while (op > 0) {
			b[++tt][i] = op % 2;
			op /= 2;
		}
	}
	bool ok = false;
	int l;
	for (int i = 30; i >= 1 && !ok; i--) {
		l = 0;
		for (int j = 1; j <= n; j++) {
			if (b[i][j] == 1) {
				c[++l] = a[j];
			}
			if (l == m) {
				ok = true;
				break;
			}
		}
	}
	if (!ok) {
		printf("0");
		return 0;
	}
	int ans = c[1];
	for (int i = 2; i <= m; i++) {
		ans = (ans & c[i]);
	}
	printf("%lld", ans);
	return 0;
}
