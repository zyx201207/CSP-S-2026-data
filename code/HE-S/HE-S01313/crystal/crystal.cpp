//rp+=INF
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m, ans, t, num;
int a[500010], tmp[500010];

int calc(int x) {
	int cnt = 0, pos = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] == x) {
			pos = i;
			break;
		}
	}
	for (int i = pos; i >= 1; i--) {
		cnt += x - a[i];
		if (cnt > m)
			return pos - i;
	}
	return pos;
}

int qwq(int x) {
	return ((x & 1) ? ((x + 1) / 2 * x) : (x / 2 * (x + 1)));
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	num = a[2] - a[1];
	bool flag = true;
	for (int i = 1; i < n; i++)
		if (num != a[i + 1] - a[i])
			flag = false;
	if (flag) {
		if (num == 0)
			printf("%d\n", n);
		else {
			for (int i = 1; i <= n; i++) {
				int val = qwq(i - 1) * num;
				if (val > m) {
					printf("%d\n", i - 1);
					return 0;
				}
			}
			printf("%d\n", n);
			return 0;
		}
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		tmp[i] = a[i];
	t = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for (int i = 1; i <= t; i++)
		ans = max(ans, calc(tmp[i]));
	printf("%d\n", ans);
	return 0;
}

