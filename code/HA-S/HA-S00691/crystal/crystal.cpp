#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 6e5 + 5;
LL n, m;
LL a[N];
LL res[N];
LL num[N], sum;
LL l = 1, r = 1;
LL ans = 0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) num[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i++) res[i] = res[i - 1] + num[i];
	while (r <= n && l <= n) {
		while (sum + num[r + 1] * (r - l + 1) <= m && r + 1 <= n && l <= n) {
			sum += num[r + 1] * (r - l + 1);
			r++;
		}
		ans = max(ans, r - l + 1);
		sum -= res[r] - res[l];
		l++;
	}
	cout << ans << endl;
	return 0;
}
