#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[500005];
ll s[500005];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
	}
	ll j = 1;
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
        while (j < i && (a[i] * (i - j + 1) - (s[i] - s[j - 1])) > m) {
            j++;
        }
//        cout << i << " " << j << " " << s[i] << "\n";
        ans = max(ans, i - j + 1);
	}
	cout << ans << "\n";
	return 0;
}
/*
a[i]*len-(s[i]-s[j-1])<=m

*/
