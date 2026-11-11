#include <bits/stdc++.h>
using namespace std;
int n, m;
int stk[500006], ans[300006], kards[500006];
void solve1() {
	for (int i = 1; i <= n; i++) {
		int top = 0;
		vector<bool> instk(m + 1, false);
		for (int st = i; st <= n; st++) {
			if (!instk[kards[st]])
				stk[++top] = kards[st], instk[kards[st]] = true;
			else {
				int num = 0;
				do {
					num = stk[top--], instk[num] = false;
				} while(num != kards[st]);
				stk[++top] = kards[st], instk[kards[st]] = true;
			}
		}
		while (top > 0)
			ans[stk[top--]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	bool flag = false;
	for (int i = 1; i <= n; i++)
		cin >> kards[i], flag = flag || (kards[i] < kards[i - 1]);
	if (flag)
		solve1();
	else {
		vector<int> cnt(m + 1, 0);
		for (int i = 1; i <= n; i++)
			cnt[kards[i]] = i;
		for (int i = 1; i <= m; i++)
			cout << cnt[i] << ' ';
	}
	return 0;
}
