#include<bits/stdc++.h>
#define LL long long
#define PII pair <LL, LL>
using namespace std;
bool bbb;
const LL N = 5e5 + 5;
LL n, m, ans;
LL a[N], s[N];
bool eee;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cerr << abs(&bbb - &eee) / 1024.0 / 1024 << '\n';
	cin >> n >> m;
	for(LL i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(LL i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
	for(LL i = 1; i <= n; i ++ ) {
		LL l = 1, r = i, res = i;
		while(l <= r) {
			LL mid = l + r >> 1;
			if(a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) {
				res = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << '\n';
	return 0;
}

