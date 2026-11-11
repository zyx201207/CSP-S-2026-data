#include <bits/stdc++.h>
using namespace std;

const int C = 500100;
int n;
long long m, a[C], s[C];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n <= 5000) {
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
			s[i] = s[i - 1] + a[i];
		int ans = 0;
		for (int l = 1; l <= n; l++)
			for (int r = l; r <= n; r++)
				if (a[r] * (r - l) - s[r - 1] + s[l - 1] <= m)
					ans = max(ans, r - l + 1);
		printf("%d\n", ans);
	} else {
		bool ok = true;
		for (int i = 1; i <= n && ok; i++)
			if (a[i] != i)
				ok = false;
		if (ok) {
			int i = 1;
			while (i * (i - 1) <= 2 * m)
				++i;
			--i;
			printf("%d\n", i);
		} else {
			ok = true;
			int x = a[2] - a[1];
			for (int i = 3; i <= n && ok; i++)
				if (a[i] - a[i - 1] != x)
					ok = false;
			if (ok) {
				int i = 1;
				while ((a[i] - a[1]) * (i - 1) - (i - 1) * (i - 2) / 2 * x <= m)
					++i;
				--i;
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
