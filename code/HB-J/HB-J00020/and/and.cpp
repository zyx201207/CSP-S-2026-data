#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5+10;
int a[N], b[N], cnt = 0;
int n, m, ans = LLONG_MIN;

void dfs (int x) {
	if (x > n+1) return ;
	if (cnt == m) {
		int sum = b[1];
		for (int i = 2; i <= cnt; i++) {
			sum &= b[i];
		}
		//printf("b=");
		//for (int i = 1; i <= cnt; i++)printf("%lld ", b[i]);
		//printf("\nsum=%lld\n", sum);
		ans = max(ans, sum);
		return ;
	}
	b[++cnt] = a[x];
	dfs(x+1);
	cnt--;
	
	dfs(x+1);
}

bool A () {
	for (int i = 1; i <= n; i++) {
		if (pow(2, log(i+1)) != i) {
			return false;
		}
	}
	return true;
}

signed main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	if (m == 1) {
		int mx = LLONG_MIN;
		for (int i = 1; i <= n; i++)
			mx = max(mx, a[i]);
		printf("%lld", mx);
	}
	else if (m == n) {
		int tmp = a[1];
		for (int i = 2; i <= n; i++)
			tmp &= a[i];
		printf("%lld", tmp);
	}
	else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i+1; j <= n; j++) {
				ans = max(ans, a[i]&a[j]);
			}
		}
		printf("%lld", ans);
	}
	else if (m == n-1) {
		int tmp = a[1];
		for (int i = 2; i <= n; i++)
			tmp &= a[i];
		for (int i = 1; i <= n; i++) {
			ans = max(ans, tmp&a[i]);
		}
		printf("%lld", ans);
	}
	else if (A()) {
		printf("0");
	}
	else {
		dfs(1);
		printf("%lld", ans);
	}
	return 0;
}
