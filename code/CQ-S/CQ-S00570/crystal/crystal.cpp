#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
const int N = 500100;
int n;
ll m, a[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (sum[i] - sum[i - mid] + m >= a[i] * mid) l = mid;
			else r = mid - 1;
		}
		ans = max(ans, l);
	}
	cout << ans << '\n';
	return 0;
}