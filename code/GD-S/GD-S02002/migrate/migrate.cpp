#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, r[N], l[N], cr[N], cl[N];
long long a[N], d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T;
	scanf("%d%d", &C, &T);
	while (T--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		int tr = 1, tl = n;
		a[n + 1] = 1LL << 62, a[0] = -1LL << 62;
		for (int i = 1; i <= n; i++) {
			tr = max(tr, i);
			while (a[i] + d >= a[tr + 1]) tr++;
			r[i] = tr;
		}
		for (int i = n; i >= 1; i--) {
			tl = min(tl, i);
			while (a[i] - d <= a[tl - 1]) tl--;
			l[i] = tl;
		}
		for (int i = 1; i <= n; i++) cl[i] = cr[i] = 0;
		for (int i = 1; i <= n; i++) {
			cl[i]++;
			if (r[i] != i) cl[r[i]] += cl[i];
		}
		for (int i = n; i >= 1; i--) {
			cr[i]++;
			if (l[i] != i) cr[l[i]] += cr[i];
		}
		long long ans = 0;
		for (int i = 2; i + 2 <= n; i++) {
			int x = i, y = i + 1;
			tl = l[y], tr = r[x];
			int tl2 = min(l[y + 1], x - 1), tr2 = max(r[x - 1], y + 1);
			if (l[y + 1] == tl || tr == r[x - 1] || l[y] > x - 1 || r[x] < y + 1) continue;
			ans += 1LL * (tl2 - tl + cl[tl]) * (tr - tr2 + cr[tr]);
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
