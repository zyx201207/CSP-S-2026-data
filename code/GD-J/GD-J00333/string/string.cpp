#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
ll a[maxn];
char c[maxn];
ll solve(int n) {
	ll s1 = 0, s2 = 0;
	ll ans = 0;
	for (int i = 1, j = n; i <= n; i++) {
		if (s1 < s2 && c[i] != c[j]) {
//			cout << "1 " << i << " " << j << " " << s1 << " " << s2 << endl;
			if (s1 + a[i] > s2) ans += s2 - s1;
			else ans += a[i];
		}
		s1 += a[i];
		while (j >= 1 && s2 < s1) {
//			if (s1 == s2 + a[j]) {
//				s2 += a[j];
//				break;	
//			}
			if (c[i] != c[j]) {
//				cout << "2 " << i << " " << j << " " << s1 << " " << s2 << endl;
				if (s2 + a[j] > s1) ans += s1 - s2;
				else ans += a[j];
			}
			s2 += a[j];
			j--;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i], sum += a[i];
	if (sum <= 1e8) {
		string s;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= a[i]; j++) s += c[i];
		ll ans = 0;
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) ans += (s[i] != s[j]);
		cout << ans << "\n";
		exit(0);
	}
	ll ans1 = solve(n) / 2;
	reverse(a + 1, a + n + 1); reverse(c + 1, c + n + 1);
	ll ans2 = solve(n) / 2;
	cout << min(ans1, ans2) << "\n";
	return 0;
}

