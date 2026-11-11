#include <bits/stdc++.h>
using namespace std;

const int C = 200100;
int n, a[C];
char c[C][3];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%c%c%c", &a[i], &c[i][0], &c[i][1], &c[i][2]);
	int ans = 0;
	for (int i = 1; i < n; ) {
		if (a[i] <= a[n]) {
			if (c[i][1] != c[n][1])
				ans += a[i];
			a[n] -= a[i], a[i] = 0;
		} else {
			if (c[i][1] != c[n][1])
				ans += a[n];
			a[i] -= a[n], a[n] = 0;
		}
		if (!a[i])
			++i;
		else
			--n;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i])
			++cnt;
	if (cnt <= 1)
		printf("%d\n", ans);
	else {
		++ans;
		printf("%d\n", ans);
	}
	return 0;
}
