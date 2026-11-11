#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
int n, d, x[2000010], ans;
int dp_small(int ss) {
	vector <int> dp(n + 10), cnt(n + 10), buc(n + 10), q(n + 10);
	int l = ss, head = 1, tail = 1, res = 0;
	cnt[ss] = buc[0] = 1;
	q[1] = ss;
	for (int i = ss + 1; i <= n; i++) {
		while (x[i] - x[l] > d) {
			buc[dp[l]] -= cnt[l];
			l++;
		}
		if (l == i) break;
		while (head <= tail && q[head] < l) head++;
		
		int opt = dp[q[head]];
		dp[i] = opt + 1;
		cnt[i] = buc[opt];
		if (cnt[i] == 2) res++;
		buc[dp[i]] += cnt[i];
		
		while (tail >= head && dp[q[tail]] >= dp[i]) tail--;
		q[++tail] = i;
	}
	return res;
}
void solve_small() {
	for (int i = 1; i < n; i++) ans += dp_small(i);
}
void solve_A() {
	int dis = x[2] - x[1];
	if (dis > d) return;
	vector <int> dp(n + 10), cnt(n + 10), buc(n + 10), q(n + 10);
	int l = 1, head = 1, tail = 1;
	cnt[1] = buc[0] = 1;
	q[1] = 1;
	for (int i = 2; i <= n; i++) {
		while ((i - l) * dis > d) {
			buc[dp[l]] -= cnt[l];
			l++;
		}
		while (head <= tail && q[head] < l) head++;
		
		int opt = dp[q[head]];
		dp[i] = opt + 1;
		cnt[i] = buc[opt];
		buc[dp[i]] += cnt[i];
		
		while (tail >= head && dp[q[tail]] >= dp[i]) tail--;
		q[++tail] = i;
	}
	for (int i = 2; i <= n; i++) if (cnt[i] == 2) ans += n - i + 1;
}
void solve_B() {
	
}
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	
	if (n == 1) {
		cout << "0\n";
		return;
	}
	
	ans = 0;
	if (n <= 5200) solve_small();
	else if (c == 11 || c == 12) solve_A();
	else if (c == 13 || c == 14) solve_B();
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}
