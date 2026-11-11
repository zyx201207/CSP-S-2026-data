#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 2;
const int M = 3e1 + 2;
const int INF = 0x3f3f3f3f;
int n, m, a[N], b[M], ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j <= 30; j++) {
			if (a[i] & (1 << j)) {
				b[j]++;
			}
		}
	}
	for (int j = 0; j <= 30; j++) {
		if (b[j] < m) {
			for (int i = 1; i <= n; i++) {
				if (a[i] & (1 << j)) {
					a[i] -= (1 << j);
				}
			}
		}
	}
	sort(a + 1, a + n + 1, greater<int>());
	ans = a[1];
	for (int i = 2; i <= m; i++) {
		ans &= a[i];
	}
	printf("%d", ans);
	return 0;
}
