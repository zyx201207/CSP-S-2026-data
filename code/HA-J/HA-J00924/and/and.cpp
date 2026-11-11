#include<bits/stdc++.h>
using namespace std;

const int N = 2010;
int n, m;
long long a[N], dp[N][N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	long long ans = a[1];
	if (m == 1) {
		printf("%lld\n", a[n]);
		return 0;
	}
	if (m == n) {
		for (int i = 2; i <= n; i++) {
			ans &= a[i];
		}
		printf("%lld\n", ans);
		return 0;
	}
	return 0;
}
