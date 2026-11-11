#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n, a[500005], m, s[500005], ans = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		s[i] = s[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	ll i = 1, j = 2;
	while (j <= n) {
		//cout << s[j] - (s[i] + (a[j] - a[i]) * (i - 1)) << " ";
		if (s[j] - (s[i] + (a[j] - a[i]) * (i - 1)) > m) {
			i++;
			if (i == j) {
				j++;
			}
		} else {
			//cout << i << " " << j << "\n";
			ans = max(j - i + 1, ans);
			j++;
		}
	}
	cout << ans;
	return 0;
}
