#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, edans;
bool nd[200006];
int num[200006], dp[200006];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	bool Aflag = true;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		bool rdy = false;
		for (int j = 0; j <= 30; j++)
			if (num[i] & (1 << j)) rdy = true;
			else if (rdy) Aflag = false;
	}
	if (!Aflag && n * m <= 99999900) {
		dp[0] = 0x7fffffff;
		for (int i = 1; i <= n; i++) {
			for (int j = m; j >= 1; j--)
				dp[j] = max(dp[j], dp[j - 1] & num[i]);
		}
		cout << dp[m];
	}
	else {
		if (Aflag) {
			sort(num + 1, num + n + 1);
			cout << num[n - m + 1];
		}
		else {
			vector< pair<int, int> > cnt(n + 1);
			for (int i = 1; i <= n; i++) {
				int tmp = 0;
				for (int j = 0; j <= 30; j++)
					if (num[i] & (1 << j)) tmp++;
				cnt[i] = {tmp, i};
			}
			sort(cnt.begin() + 1, cnt.end());
			edans = 0x7fffffff;
			for (int i = n; i >= n - m + 1; i--)
				edans &= num[cnt[i].second];
			cout << edans;
		}
	}
	return 0;
}
