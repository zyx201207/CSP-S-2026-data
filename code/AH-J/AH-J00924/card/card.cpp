#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
long long n, m, a[N], ans[N], num[N], rest[M];
bool flag1, flag2;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	flag1 = flag2 = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i + 1]) flag1 = 0;
		if (a[i] < a[i + 1]) flag2 = 0;
	}
	if (flag1 || flag2) {
		for (int i = 1; i <= m; i++) cout << n << " ";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		memset(num, 0, sizeof(num));
		memset(rest, 0, sizeof(rest));
		long long len = 0;
		for (int j = i; j <= n; j++) {
			if (rest[a[j]] == 0 || rest[a[j]] > len) {
				rest[a[j]] = ++len;
				num[len] = a[j];
			} else len = rest[a[j]];
		}
	    for (int j = 1; j <= len; j++) ans[num[j]]++;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	return 0;
}
