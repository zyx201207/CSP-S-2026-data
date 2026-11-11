#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n, ans = 1;
ll a[maxn], m, sum;
int main()  {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2, p = 1; i <= n; ++i) {
		sum += (a[i] - a[i - 1]) * (i - p);
		while (sum > m) {
			sum -= (a[i] - a[p]);
			++p;
		}
		ans = max(i - p + 1, ans);
	}
	cout << ans;
	return 0;
}

