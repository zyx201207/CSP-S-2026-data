#include <bits/stdc++.h>
using namespace std;
const int p = 2e5 + 1;
int n;
char c[p];
long long ans, a[p];
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld %c", &a[i], &c[i]);
	int l = 1, r = n;
	for (; l <= r; ) {
		if (a[l] == a[r] && c[l] == c[r]) r--, l++;
		else if (a[l] == a[r]) {
			ans += a[l], r--, l++;
		} else {
			if (a[l] > a[r]) {
				a[l] -= a[r];
				if (c[l] != c[r]) ans += a[r];
				r--;
			} else {
				a[r] -= a[l];
				if (c[l] != c[r]) ans += a[l];
				l++;
			}
		}
	}
	printf("%lld", ans);
}
