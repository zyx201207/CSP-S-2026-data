#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int len = n, ans = 0;
	for (int i = 29; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j <= len; j++) {
			if (a[j] & (1 << i)) cnt++;
		}
		if (cnt >= m) {
			ans += (1 << i);
			int t = 0;
			for (int j = 1; j <= len; j++) {
				if (a[j] & (1 << i)) {
					a[++t] = a[j];
				}
			}
			len = t;
		}
	}
	printf("%d\n", ans);
	return 0;
}
