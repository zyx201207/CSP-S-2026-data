#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500000], t;
char s[500000];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld %c", &a[i], &s[i]);
	int l = 0, r = n - 1;
	while (l < r) {
		if (s[l] == s[r]) {
			if (l == r - 1) break;
			if (a[l] == a[r]) l++, r--;
			else if (a[l] < a[r]) a[r] -= a[l], l++;
			else if (a[l] > a[r]) a[l] -= a[r], r--;
			continue;
		}
		if (a[l] == a[r]) {
			t += a[l];
			if (l == r - 1) break;
			l++, r--;
		}
		else if (a[l] < a[r]) t += a[l], a[r] -= a[l], l++;
		else if (a[l] > a[r]) t += a[r], a[l] -= a[r], r--;
	}
	printf("%lld\n", t);
	return 0;
} 
