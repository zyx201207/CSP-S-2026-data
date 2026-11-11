#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], sum[N], sumlast[N], l, r, mid;
bool check(long long x) {
	long long num = sum[x];
	if (num <= m) return 1;
	for (int i = x + 1; i <= n; i++) {
		num -= sumlast[i - 1] - sumlast[i - x];
		num += (sumlast[i] - sumlast[i - 1]) * (x - 1);
		if (num <= m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		sum[i] = (a[i] - a[i - 1]) * (i - 1);
		sumlast[i] = sumlast[i - 1] + (a[i] - a[i - 1]);
	}
	for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	l = 1;
	r = n;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1;
	return 0;
}
