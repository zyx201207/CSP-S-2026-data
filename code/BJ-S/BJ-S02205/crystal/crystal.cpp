// Code by Happy-David_3367 on 2026 CSP-S2 competition.
// Problem: T1_crystal 能量水晶(crystal)
// 1447.cpp ?
#include <bits/stdc++.h>
using namespace std;
// #define MULTI_TEST
int n, L, R, ans;
long long m, a[500100], need;
priority_queue<pair<long long, int>> mx; // first: value, second: index
inline void solve() {
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf ("%lld", &a[i]);
	}
	sort (a + 1, a + n + 1);
	L = 1;
	R = 1;
	ans = 0;
	need = 0;
	while (!mx.empty ()) {
		mx.pop ();
	}
	mx.push ({a[1], 1});
	// loop L, find maximum R
	for (; L <= n; ++L) {
		while (mx.top ().second < L) {
			mx.pop ();
		}
		while (R <= n && need <= m) {
			++R;
			long long recent_top = mx.top ().first;
			mx.push ({a[R], R});
			if (recent_top < mx.top ().first) {
				int cnt = R - L;
				long long delta = a[R] - recent_top;
				need += (delta * 1LL * cnt);
			} else {
				need += (recent_top - a[R]);
			}
		}
		ans = max (ans, R - L); // We can't use such R bacause R is the minimum index that does not satisfy the condition.
		#ifdef Happy_David_3367_FLAG
			printf ("[Happy_David_3367_FLAG] [Flag <two-pointers>] L = %d, R = %d, res = %d, ans = %d.\n", L, R, R - L, ans);
		#endif // Debug Snippet
		if (mx.top ().second == L) {
			long long recent_top = mx.top ().first;
			mx.pop ();
			int cnt = R - L;
			long long delta = recent_top - mx.top ().first;
			need -= (delta * 1LL * cnt);
		}
		long long delta = max (0LL, mx.top ().first - a[L]);
		need -= delta;
		// ++L; (written in the 'for' statement)
	}
	printf ("%d\n", ans);
}
inline void main0(long start_clock = 0) {
	int T = 1;
	#ifdef MULTI_TEST
		scanf ("%d", &T);
	#endif
	while (T--) {
		// Remember to restore vars!!!
		solve ();
	}
	#ifdef Happy_David_3367_FLAG
		printf ("[Happy_David_3367_FLAG] Running Time Used: %.6Lf sec.\n", (clock () - start_clock) * (long double) 1 / CLOCKS_PER_SEC);
	#endif
}
int main() {
	const string prob_name = "crystal";
	#ifndef Happy_David_3367_FLAG
		freopen ((prob_name + ".in").c_str (), "r", stdin);
		freopen ((prob_name + ".out").c_str (), "w", stdout);
		main0 ();
	#else
		const int samples_cnt = 4;
		const string program_prefix = "1447";
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