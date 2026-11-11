#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
ll n, len[MAXN], ridx, ans, tot, sum[MAXN];
char a[MAXN];
ll find (ll num) {
	ll l = 1, r = n;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (sum[mid] == num) return mid;
		else if (sum[mid] > num) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}	
int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> len[i] >> a[i], tot += len[i], sum[i] = tot;
	}
	ll mid = (1 + tot) >> 1, lidx, ridx;
	if (mid * 2 == tot) lidx = mid, ridx = mid + 1;
	else {
		lidx = ridx = mid;
		lidx --, ridx ++;
	}
	ll l = find (lidx);
	ll r = find (ridx);
	while (l >= 1 && r <= n) {
		bool flag = !(a[l] == a[r]);
		if (lidx - sum[l - 1] <= sum[r] - ridx + 1) ans = ans + flag * (lidx - sum[l - 1]), ridx = ridx + (lidx - sum[l - 1]), lidx = sum[l - 1], l --, r = r + (ridx - 1 == sum[r]);
		else ans = ans + flag * (sum[r] - ridx + 1), lidx = lidx - (sum[r] - ridx + 1), ridx = sum[r] + 1, r ++;
	}
	cout << ans;
	return 0;
}
