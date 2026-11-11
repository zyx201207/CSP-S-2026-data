#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 500005;
int n;
ll m, a[MAXN], p[MAXN];

int binarys(int id, ll x) {
	int l = 1, r = id, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if(p[mid - 1] - mid * 1LL * a[id] <= x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] + a[i];
	}
	ll x = 0;
	int l = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i + 1]) {
			x = m + p[i - 1] - i * 1LL * a[i];
			// ×îÐ¡£¬p[l - 1] - l * a[i] <= x
			l = binarys(i, x);
			if (1 <= l && l <= i)
				ans = max(ans, i - l + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}
