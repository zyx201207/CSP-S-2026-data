#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int maxn = 5e5;
int n;
LL m, a[maxn + 10], sum[maxn + 10];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i-1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i; 
		while (l < r) {
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << "\n";
	return 0;
}

