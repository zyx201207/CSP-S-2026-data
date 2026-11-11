#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int n, ans;
ll a[N], sum[N], m;
pair<int, ll> cnt[N];
ll checkAB() {
	for (int i = 3; i <= n; i++)
		if (a[i]-a[i-1] != a[i-1]-a[i-2])
			return 0;
	return a[2]-a[1];
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (checkAB()) {
		cout << m / checkAB();
	} else {
		sort(a+1, a+n+1);
		for (int i = 1; i <= n; i++) {
			ll cnt = 0;
			int j;
			for (j = i-1; j >= 1; j--) {
				if (cnt + (a[i]-a[j]) <= m)
					cnt += (a[i]-a[j]);
				else
					break;
			}
			ans = max(ans, i-j);
		}
		cout << ans;
	}
	return 0;
}
