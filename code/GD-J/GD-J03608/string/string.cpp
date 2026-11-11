#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

char c[N];
int n, a[N];
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> c[i];
	int i = 1, j = n;
	while (i < j) {
		int x = min(a[i], a[j]);
		a[i] -= x, a[j] -= x, ans += x * (c[i] != c[j]);
		i += !a[i], j -= !a[j];
	}
	return cout << ans, 0;
}
