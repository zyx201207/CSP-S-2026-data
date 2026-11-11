# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n;
ll m;
ll s[N], b[N];
int q[N];
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> s[i];
	sort(s + 1, s + n + 1);
	int hh = 1, tt = 0;
	ll sum = 0, cnt = 0, ans = 0;
	for (int i = 1; i <= n; i ++) {
		sum += (tt - hh + 1) * (s[i] - s[i - 1]);
		q[++ tt] = i;
		cnt ++;
		while (hh <= tt && sum > m) {
			sum -= s[i] - s[q[hh ++]];
			cnt --;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
