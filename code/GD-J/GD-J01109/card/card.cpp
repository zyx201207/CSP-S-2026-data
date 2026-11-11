#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], b[N], s, t, ans[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		s = t = 1;
		b[s] = a[i];
		for (int j = i + 1; j <= n; ++j) {
			for (int k = s; k <= t; ++k) {
				if (b[k] == a[j]) {
					t = k - 1;
					break;
				}
			}
			b[++t] = a[j];
		}
		for (int j = s; j <= t; ++j) ans[b[j]]++;
	}
	for (int i = 1; i <= m; ++i) printf("%d ", ans[i]);
	return 0;
}
