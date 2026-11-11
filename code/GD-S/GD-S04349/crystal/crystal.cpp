#include<bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], s[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n;i++) {
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		int l = 1, r = i, pos = i;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) {
				pos = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(ans, i - pos + 1);
	}
	cout << ans;
	return 0; 
}
