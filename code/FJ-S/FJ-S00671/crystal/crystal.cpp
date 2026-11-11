#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
long long m;
long long a[N];
int ans = 1;

void dfs(int k, long long cnt, long long maxa, int last) {
	if (last == n) {
		ans = max(ans, k);
		return;
	}
	for (int i = last + 1;i <= n;i++) {
		if (a[i] == maxa) dfs(k + 1, cnt, maxa, i);
		else {
			long long newm = (a[i] - maxa) * k + cnt;
			if (newm <= m) dfs(k + 1, newm, a[i], i);
			else dfs(k, cnt, maxa, n);
			dfs(k, cnt, maxa, i);
		}
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1;i <= n;i++) {
		scanf("%lld", a + i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n;i++) {
		dfs(1, 0, a[i], i);
	}
	printf("%d", ans);
	return 0;
}
