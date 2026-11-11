#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[200010];
char s[200010][5];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%s", &a[i], s[i]);
	}
	ll ans = 0;
	for (int i = 1, j = n; i < j; ) {
		if (s[i][0] == s[j][0]) {
			if (a[i] < a[j]) {
				a[j] -= a[i]; i++;
			} else if (a[i] > a[j]) {
				a[i] -= a[j]; j--;
			} else {
				i++; j--;
			}
		} else {
			ans += min(a[i], a[j]);
			if (a[i] < a[j]) {
				a[j] -= a[i]; i++;
			} else if (a[i] > a[j]) {
				a[i] -= a[j]; j--;
			} else {
				i++; j--;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

