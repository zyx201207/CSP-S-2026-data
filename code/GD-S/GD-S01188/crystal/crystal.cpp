#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], ans, cnt, b[N];

void merge_sort(int l, int r) {
	if (l == r) return ;
	int mid = (l + r) >> 1;
	merge_sort(l, mid), merge_sort(mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r) {
		if (a[i] > a[j]) b[++k] = a[i++];
		else b[++k] = a[j++];
	}
	while (i <= mid) b[++k] = a[i++];
	while (j <= r) b[++k] = a[j++];
	for (i = 1; i <= k; ++i) a[i + l - 1] = b[i];
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	merge_sort(1, n);
	for (int i = 1, j = 0; i <= n && j < n; ++i) {
		while (m >= a[i] - a[j + 1] && j + 1 <= n) m -= a[i] - a[j + 1], cnt++, j++;
		ans = max(ans, cnt);
		cnt--;
		m += (a[i] - a[i + 1]) * cnt;
	}
	printf("%lld", ans);
	return 0;
}
