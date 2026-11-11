#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (int)(b); ++i)
#define per(i, a, b) for (int i = (a); i >= (int)(b); --i)
using LL = long long;
using Pii = pair<int, int>;
#define fst first
#define snd second

namespace gdb7
{
	LL x[2000010], dp[2000010], cnt[2000010];
	signed main(void) {
		freopen("migrate.in", "r", stdin);
		freopen("migrate.out", "w", stdout);
		int c, t;
		scanf("%d%d", &c, &t);
		while (t--) {
			int n;
			LL d;
			scanf("%d%lld", &n, &d);
			rep (i, 1, n) {
				scanf("%lld", x + i);
			}
			if (true) {
				LL ans = 0;
				rep (i, 1, n) {
					deque<int> dq;
					memset(dp, 0x3f, sizeof(dp));
					memset(cnt, 0, sizeof(cnt));
					dp[i] = 0;
					cnt[i] = 1;
					dq.push_back(i);
					rep (j, i + 1, n) {
//						per (k, j, i) {
//							if (x[j] - x[k] > d) break;
//							if (dp[k] + 1 < dp[j]) {
//								dp[j] = dp[k] + 1;
//								cnt[j] = cnt[k];
//							} else if (dp[k] + 1 == dp[j]) {
//								cnt[j] += cnt[k];
//							}
//							if (cnt[j] >= 3) cnt[j] = 3;
//						}
						while (dq.size() && x[j] - x[dq.front()] > d) {
							dq.pop_front();
						}
						if (dq.size()) {
//							cout << j << ": " << k << endl;
							rep (t, 0, dq.size() - 1) {
								int k = dq[t];
								if (dp[k] + 1 < dp[j]) {
									dp[j] = dp[k] + 1;
									cnt[j] = cnt[k];
								} else if (dp[k] + 1 == dp[j]) {
									cnt[j] += cnt[k];
								} else {
									break;
								}
//								cout << j << ": " << k << endl;
							}
							if (cnt[j] >= 3) cnt[j] = 3;
							while (dq.size() && dp[dq.back()] > dp[j]) {
								dq.pop_back();
							}
							dq.push_back(j);
						}
						if (cnt[j] == 2) {
							++ans;
						}
					}
				}
				printf("%lld\n", ans);
			}
		}
		return 0;
	}
};

signed main()
{
	return gdb7::main();
}

