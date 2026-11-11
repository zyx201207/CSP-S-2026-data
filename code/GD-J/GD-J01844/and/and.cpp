#include <bits/stdc++.h>
using namespace std;
int n, m, a[201000], dp[2010][2010], val = 0, c[210], v[50];
inline void solve(int x) {
	if (x == n + 1) {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += c[i];
		if (cnt != m)
			return;
		
		int t = 0;
		for (int i = 1; i <= n; i++)
			if (c[i]) {
				if (t == 0)
					t = a[i];
				else
					t = t & a[i];
			}
		val = max(val, t);
		return;
	}
	c[x] = 1;
	solve(x + 1);
	c[x] = 0;
	solve(x + 1);
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (m == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
		printf("%d\n", ans);
		return 0;
	}
	else if (m == 2 && n <= 2000) {
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				ans = max(ans, a[i] & a[j]);
			}
		printf("%d\n", ans);
		return 0;
	}
	else if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++)
			ans = ans & a[i];
		printf("%d\n", ans);
		return 0;
	}
	else if (n <= 20) {
		solve(1);
		printf("%d\n", val);
	}
	else if (n == n - 1) {
		int t = a[1];
		for (int i = 2; i <= n; i++)
			t = t & a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 30; j++) {
				if (!(a[i] & (1 << j)))
					v[j]++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int h = t;
			for (int j = 1; j <= 30; j++) {
				if (a[i] & (1 << j))
					continue;
				h += (1 << j);
			}
			ans = max(ans, h);
		}
		printf("%d\n", ans);
		return 0;
	}
	bool flag = true;
	for (int i = 1; i <= n && flag; i++) 
		if (a[i] >= 4)
			flag = false;
	if (flag) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] == 1)
				cnt1++;
			else if (a[i] == 2)
				cnt2++;
			else if (a[i] == 3)
				cnt3++;
		if (cnt3 >= m)
			printf("3\n");
		else if (cnt3 + cnt2 >= m)
			printf("2\n");
		else if (cnt3 + cnt2 + cnt1 >= m)
			printf("1\n");
		else
			printf("0\n");
		return 0;
	}
	sort(a + 1, a + n + 1);
	printf("%d\n", a[n - m + 1]);
	return 0;
}
