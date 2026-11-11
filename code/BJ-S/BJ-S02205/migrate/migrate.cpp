// Code by Happy-David_3367 on 2026 CSP-S2 competition.
// Problem: T3_migrate 迁徙(migrate)
// 1741.cpp ?
#include <bits/stdc++.h>
using namespace std;
#define MULTI_TEST
int n;
long long d, x[2001000], ans;
inline void solve(long sc) {
	scanf ("%d%lld", &n, &d);
	for (int i = 1; i <= n; ++i) {
		scanf ("%lld", &x[i]);
	}
	#ifdef Happy_David_3367_FLAG
		if (n >= 32768) {
			printf ("[Happy_David_3367_FLAG] N is too large and maybe crash the system. Auto testing skipped for this sample.\n");
			return;
		}
	#endif
	vector<vector<vector<pair<long long, long long>>>> dp (n + 2, vector<vector<pair<long long, long long>>> (n + 2, vector<pair<long long, long long>> (n + 2, {1LL << 61LL, 0LL}))); // first: dist; second: cnt
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			dp[0][i][j].first = x[j] - x[i];
			dp[0][i][j].second = 1LL;
		}
		#ifdef Happy_David_3367_FLAG
			if ((clock () - sc) > CLOCKS_PER_SEC * 1.5) {
				printf ("[Happy_David_3367_FLAG] Time Limit Exceeded.\n");
				return;
			}
		#endif
	}
	for (int m = 1; m <= n; ++m) {
		for (int s = 1; s <= m - 1; ++s) {
			for (int e = m + 1; e <= n; ++e) {
				long long res = dp[m - 1][s][m].first + dp[m - 1][m][e].first;
				if (dp[m][s][e].first == res) {
					dp[m][s][e].second += (dp[m - 1][s][m].second * dp[m - 1][m][e].second);
				} else if (dp[m][s][e].first > res) {
					dp[m][s][e].first = res;
					dp[m][s][e].second = (dp[m - 1][s][m].second * dp[m - 1][m][e].second);
				}
			}
			#ifdef Happy_David_3367_FLAG
				if ((clock () - sc) > CLOCKS_PER_SEC * 1.5) {
					printf ("[Happy_David_3367_FLAG] Time Limit Exceeded.\n");
					return;
				}
			#endif
		}
	} // Floyd
	ans = 0;
	for (int u = 1; u <= n; ++u) {
		for (int v = u + 1; v <= n; ++v) {
			if (dp[n][u][v].second == 2) {
				++ans;
			}
		}
		#ifdef Happy_David_3367_FLAG
			if ((clock () - sc) > CLOCKS_PER_SEC * 1.5) {
				printf ("[Happy_David_3367_FLAG] Time Limit Exceeded.\n");
				return;
			}
		#endif
	}
	printf ("%lld\n", ans);
}
inline void main0(long start_clock = 0) {
	int c;
	scanf ("%d", &c);
	int T = 1;
	#ifdef MULTI_TEST
		scanf ("%d", &T);
	#endif
	while (T--) {
		// Remember to restore vars!!!
		solve (start_clock);
	}
	#ifdef Happy_David_3367_FLAG
		printf ("[Happy_David_3367_FLAG] Running Time Used: %.6Lf sec.\n", (clock () - start_clock) * (long double) 1 / CLOCKS_PER_SEC);
	#endif
}
int main() {
	const string prob_name = "migrate";
	#ifndef Happy_David_3367_FLAG
		freopen ((prob_name + ".in").c_str (), "r", stdin);
		freopen ((prob_name + ".out").c_str (), "w", stdout);
		main0 ();
	#else
		const int samples_cnt = 6;
		const string program_prefix = "1741";
		for (int sample = 1; sample <= samples_cnt; ++sample) {
			freopen ((prob_name + to_string (sample) + ".in").c_str (), "r", stdin);
			freopen ((program_prefix + '.' + prob_name + to_string (sample) + ".out").c_str (), "w", stdout);
			freopen ((program_prefix + '.' + prob_name + to_string (sample) + ".err").c_str (), "w", stderr);
			main0 (clock ());
			fclose (stdin);
			fclose (stdout);
			fclose (stderr);
		}
	#endif
	return 0;
}
// Head Snippet