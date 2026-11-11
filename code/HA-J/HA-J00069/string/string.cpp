#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, a[N];
char s[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d %c", &a[i], &s[i]);
	ll ans = 0;
	for (int i = 1, j = n; i < j; ) {
		if (a[i] < a[j]) {
			if (s[i] != s[j]) ans += a[i];
			a[j] -= a[i];
			i++;
		} else if (a[i] > a[j]) {
			if (s[i] != s[j]) ans += a[j];
			a[i] -= a[j];
			j--;
		} else {
			if (s[i] != s[j]) ans += a[i];
			a[i] = a[j] = 0;
			i++, j--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}