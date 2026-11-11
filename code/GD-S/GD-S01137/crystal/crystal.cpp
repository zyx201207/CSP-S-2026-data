#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 1;
int a[MAXN];
long long s[MAXN];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m, ans = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	long long tans = 1;
	for (int i = 1; i <= n; i++) {
		int l = -1, r = i - 1;
		int mid = (l + r) / 2;
		while (l <= r) {
			mid = (l + r) / 2;
			if (m >= ((i - 1 - mid) * a[i]) - (s[i - 1] - s[mid])) {
				r = mid - 1;
				tans = i - mid;
			}else l = mid + 1;
		}
		if (ans < tans) ans = tans;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
