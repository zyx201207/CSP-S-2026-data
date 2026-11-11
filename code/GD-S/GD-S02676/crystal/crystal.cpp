#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
long long c[N];

bool check(int x, int n, long long m) {
	int num = 0;
	for (int i = 1; i <= x; i++)
		num += c[x] - c[i];
	if (num <= m) return 1;
	for (int i = x + 1; i <= n; i++) {
		num -= (c[i - 1] - c[i - x]);
		num += x * (c[i] - c[i - 1]);
		if (num <= m) return 1;
	} return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	sort(c + 1, c + n + 1);
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid, n, m)) l = mid;
		else r = mid - 1;
	} cout << l << '\n';
	return 0;
}
