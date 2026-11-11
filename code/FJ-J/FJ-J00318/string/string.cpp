#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n, a[N], c[N];
ll ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
	    scanf("%d %c", &a[i], &c[i]);
	    c[i] -= 96;
	}
	
	int l = 1, r = n;
	while (l < r) {
		if (a[l] >= a[r]) {
			if (c[l] != c[r]) {
				ans += a[r];
			}
			a[l] -= a[r];
			r--;
		} else {
			if (c[l] != c[r]) {
				ans += a[l];
			}
			a[r] -= a[l];
			l++;
		}
	} 
	
	printf("%lld\n", ans);
	return 0;
}
