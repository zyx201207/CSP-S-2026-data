#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, m, a[N];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	int ans = (1 << 31) - 1, ans2 = (1 << 31) - 1;
	for (int i = 1; i <= m; i++) ans &= a[i];
	for (int i = 2; i <= m + 1; i++) ans2 &= a[i];
	if (m == 2 && n <= 2001) {
		int ans3 = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < i; j++)
				ans3 = max(ans3, a[i] & a[j]);
		ans = max(ans, ans3);
	}
	cout << max(ans, ans2);
	return 0;
}
