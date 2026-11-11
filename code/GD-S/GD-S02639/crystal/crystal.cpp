#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], r;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
		r += a[i];
	}
	if(r * 2 == n *(n + 1)) {
	for(long long w = 1; ; w ++) {
		if(w * (w + 1) > m) {
			printf("%lld", w+ 1);
			return 0;
		}
	}
	} else {
		printf("%lld", n - 1);
	}
	return 0;
}
