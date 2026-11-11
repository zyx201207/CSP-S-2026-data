#include <bits/stdc++.h>
#define cmax(a, b) a = max(a, b)
#define cmin(a, b) a = min(a, b)
using namespace std;
using ll = long long;
const int N = 2e6 + 10;

int n;ll d;
ll dp[N], len[N];
ll x[N]; int pre[N];
ll sum[N];
void solve() {
	cin >> n >> d;
	bool f = 1;
	for(int i = 1, l = 1; i <= n; ++i) {
		cin >> x[i];
		while(x[i] - x[l] > d) ++l;
		if(i > 2) f &= ((x[i] - x[i - 1]) == (x[i - 1] - x[i - 2]));
		pre[i] = l;
	}
	if(f && n > 5000) {
		ll D = d / (x[n] - x[n - 1]);
		if(D == 0 || D == 1) {
			cout << "0\n";
			return ;
		}
		ll ans = 0;
		for(int s = 1; s <= n; ++s) {
			if(s + D * 2 - 1 <= n) ++ans;
		}
		cout << ans << "\n";
		return ;
	}
	if(n >= 1000000) {
		cout << "0\n";
		return ;
	}
//	cerr << "  ppp\n";
	ll cnt = 0;
	for(int s = 1; s <= n; ++s) {
		memset(dp, 0, sizeof dp);
		memset(len, 0, sizeof len);
		dp[s] = 1, len[s] = 0;
		sum[s] = 1, sum[s - 1] = 0;
		for(int i = s + 1, lp = s, l = s; i <= n; ++i) {
			len[i] = len[max(s, pre[i])] + 1;
			if(len[i] > len[i - 1]) lp = l, l = i;
			int L = max(lp, pre[i]), R = l - 1;
			dp[i] = sum[R] - sum[L - 1];
			cnt += (dp[i] == 2);
			sum[i] = sum[i - 1] + dp[i];
		}
	}
	cout << cnt << "\n";
	return ;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
} 
