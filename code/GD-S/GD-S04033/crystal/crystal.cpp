#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
ll n, m;
ll a[N], s[N];
ll ans;

bool check(int mid, int i) {
	ll x = s[i - 1] - s[mid - 1];
	ll v = i - mid;
	return (x + m) / v >= a[i];
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i;
		while (l + 1 < r) {
			int mid = l + (r - l) / 2;
			if (check(mid, i)) r = mid;
			else l = mid;
		}
		ans = max(ans, 0LL + i - r + 1);
	}
	cout << ans << '\n';
	return 0;
}
