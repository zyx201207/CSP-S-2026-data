#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 5e5 + 1;
int n;
long long m;
long long a[MAXN];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.ans", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	int res = 0;
	bool flag_A = true;
	for (int i = 1; i <= n; ++i)
		if (a[i] != i) {
			flag_A = false;
			break;
		}
	bool flag_B = (!flag_A ? true : false);
	for (int i = 1; i < n; ++i)
		if (a[i] - a[i - 1] != a[1] - a[0]) {
			flag_B = false;
			break;
		}
	if (flag_A) {
		if (m >= (n * (n + 1)) / 2) res = n;
		else {
			for (int i = 1; i < n; ++i)
				if ((i + 1) * (i + 2) / 2 > m) {
					res = i;
					break;
				}
		}
	} else if (flag_B) {
		if (m >= (n * (a[n - 1] + a[0])) / 2) res = n;
		else {
			for (int i = 1; i < n; ++i)
				if ((a[i + 1]) * (a[i + 2]) / 2 > m) {
					res = i;
					break;
				}
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			int j = i - 1, cnt = 0;
			long long x = m;
			for (int k = i; k < n; ++k)
				if (a[k] == a[i]) ++cnt;
				else break;
			while (x >= 0 && j >= 0) {
				if (a[i] - a[j] <= x) {
					x -= a[i] - a[i - j];
					++cnt;
				}
				--j;
			}
			res = max(res, cnt);
		}
	}
	printf("%d\n", res);
	fclose(stdin); fclose(stdout);
	return 0;
}
