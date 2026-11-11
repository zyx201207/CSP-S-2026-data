#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 5;
ll a[N], sum[N], m;
int n, ans = 1;

bool check(int x, int l) {
	return a[x] * (x - l) - (sum[x - 1] - sum[l - 1]) <= m;
}

int solve(int x) {
	int l = 1, r = x - 1, res = 1;
	while (l <= r) { // ¶þ·Öi
		int mid = (l + r) / 2;
		if (check(x, mid)) {
			r = mid - 1;
			res = x - mid + 1;
		} else l = mid + 1;
	}
	return res;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 2; i <= n; i++)
		ans = max(ans, solve(i));
	printf("%d\n", ans);
	return 0;
}
/*
n = 5e5
O (n * log n)
*/
