#include <bits/stdc++.h>

using namespace std;

const int N = 201000;

int n, m, a[N];
int b[N], tot1;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	tot1 = n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 30; i >= 0 && tot1 > m; i--) {
		int sum = 0, tot2 = 0;
		for (int j = 1; j <= tot1; j++) {
			int t = (a[j] >> i) & 1;
			if (t) {
				sum++;
				b[++tot2] = a[j];
			}
		}
		if (sum >= m) {
			tot1 = tot2;
			for (int j = 1; j <= tot1; j++) a[j] = b[j];
		}
	}
	for (int i = 1; i <= tot1; i++) a[1] &= a[i];
	printf("%d\n", a[1]);
	return 0;
}
