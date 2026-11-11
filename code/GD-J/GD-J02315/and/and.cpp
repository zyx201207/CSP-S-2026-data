#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, a[200005], b[40], cnt, pl = 1;
struct Node {
	int c[32], id;
	bool operator < (const Node& A) const {
		return c[pl] > A.c[pl];
	}
} d[200005];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 30; j++)
			d[i].c[j] = 0;
	if (m == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
		printf("%d", ans);
		return 0;
	}
	if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++)
			ans &= a[i];
		printf("%d", ans);
		return 0;
	}
	if (n <= 2000 && m == 2) {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j)
					ans = max(ans, a[i] & a[j]);
		printf("%d", ans);
		return 0;
	}
	if (n <= 20) {
		int res = 0;
		for (int i = 0; i < (1 << n); i++) {
			int ccc = 0, ans = (1ll << 31) - 1;
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1) {
					ccc++;
					ans &= a[j + 1];
				}
			if (ccc == m)
				res = max(res, ans);
		}
		printf("%d", res);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int k = a[i];
		cnt = 0;
		for (int j = 0; j <= 30; j++)
			b[j] = 0;
		while (k) {
			b[++cnt] = k % 2;
			k /= 2;
		}
		for (int j = 30; j >= 1; j--)
			d[i].c[30 - j + 1] = b[j];
		d[i].id = i;
	}
	sort(d + 1, d + n + 1);
	int l = 1, r = n;
	for (int i = 2; i <= 30; i++) {
		int tot = 0, j = l;
		for (; j <= n; j++)
			if (d[j].c[pl] == 1)
				tot++;
			else
				break;
		pl = i;
		if (tot >= m)
			r = j - 1;
		sort(d + l, d + r + 1);
	}
	int ans = a[d[1].id];
	for (int i = 2; i <= m; i++)
		ans &= a[d[i].id];
	printf("%d", ans);
	return 0;
}
