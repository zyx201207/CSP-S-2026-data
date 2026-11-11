#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)
#define per(i, a, b) for (int i = (a); i >= int(b); --i)
#define pb push_back
#define fst first
#define snd second
typedef long long LL;
typedef unsigned long long ULL;
typedef __int128 LLL;
typedef pair<int, int> Pii;

// a & b <= min(a, b)

namespace gdb7 {
	int n, m, tot = 1;
	unsigned a[200010];
	void insert(unsigned a, vector<array<int, 2> > &trie, vector<int> &cnt) {
		int now = 1;
		++cnt[now];
		per (i, 30, 0) {
			unsigned cbit = ((a >> i) & 1);
			if (trie[now][cbit] != 0) {
				now = trie[now][cbit];
			} else {
				trie[now][cbit] = (++tot);
				now = trie[now][cbit];
			}
			++cnt[now];
		}
	}
	unsigned dfs(int u, int w, vector<array<int, 2> > &trie, vector<int> &cnt) {
		if (trie[u][0] == 0 && trie[u][1] == 0 && w == -1) {
			return 0;
		}
		if (trie[u][1] == 0) {
			return dfs(trie[u][0], w - 1, trie, cnt);
		}
		if (cnt[trie[u][1]] >= m) {
			return dfs(trie[u][1], w - 1, trie, cnt) | (1 << w);
		}
		return dfs(trie[u][0], w - 1, trie, cnt) & dfs(trie[u][1], w - 1, trie, cnt);
	}
	signed main(void) {
		freopen("and.in", "r", stdin);
		freopen("and.out", "w", stdout);
		scanf("%d%d", &n, &m);
		unsigned maxa = 0;
		bool flg = true;
		rep (i, 1, n) {
			scanf("%u", &a[i]);
			maxa = max(maxa, a[i]);
			if (flg && __builtin_popcount(a[i] + 1) != 1) {
				flg = false;
			}
		}
		if (0 && 1LL * maxa * n <= 70000000) {
			for (unsigned i = maxa; i >= 1; --i) {
				int cnt = 0;
				rep (j, 1, n) {
					if ((a[j] & i) == i) {
						++cnt;
					}
				}
				if (cnt >= m) {
					printf("%u", i);
					return 0;
				}
			}
			printf("0");
		} else if (1LL * n * m <= 70000000) {
			vector<vector<unsigned> > dp(n + 1, vector<unsigned>(m + 1, 0));
			dp[0][0] = 0xffffffff;
			rep (i, 1, n) {
				dp[i][0] = 0xffffffff;
				rep (j, 1, min(m, i)) {
					if (i >= j + 1) {
						dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - 1] & a[i]));
					} else {
						dp[i][j] = (dp[i - 1][j - 1] & a[i]);
					}
				}
			}
			printf("%u", dp[n][m]);
		} else if (flg) {
			sort(a + 1, a + 1 + n);
			printf("%u", a[n - m + 1]);
		} else {
			vector<array<int, 2> > trie(60 * n + 1);
			vector<int> cnt(60 * n + 1);
			rep (i, 1, n) {
				insert(a[i], trie, cnt);
			}
			printf("%u", dfs(1, 30, trie, cnt));
		}
		return 0;
	}
};

signed main(void) {
	return gdb7::main();
}


