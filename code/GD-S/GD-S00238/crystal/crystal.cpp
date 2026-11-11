#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 5e5;
int n;
LL m;
LL a[N + 5], s[N + 5];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("cyrstal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j < n && s[j + 1] - s[i - 1] + m >= a[j + 1] * (j - i + 2)) j++;
		ans = max(ans, j - i + 1);
	}
	cout << ans << '\n';
	return 0;
}

