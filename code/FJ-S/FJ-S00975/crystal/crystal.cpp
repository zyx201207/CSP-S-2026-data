//75
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;;

int n;
long long m, a[N], f[5005][5005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	long long x = a[2] - a[1];
	bool flag = true;
	for (int i = 3; i <= n; i++)
		if (a[i] - a[i - 1] != x) flag = false;
	if (flag == true) {
		long long y = m / x;
		long long sum = 0;
		flag = true;
		for (int i = 1; i <= n; i++) {
			if (sum > y) {
				printf("%d", i - 1);
				flag = false;
				break;
			}
			sum += i;
		}
		if (flag == true)
			printf("%d", n);
		return 0;
	}
	if (n <= 5000) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				if (j == 1)
					f[i][j] = 0;
				else
					f[i][j] = f[i - 1][j - 1] + (j - 1) * (a[i] - a[i - 1]);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				if (f[i][j] <= m)
					ans = max(ans, j);
		printf("%d", ans);
		return 0;
	}
}
