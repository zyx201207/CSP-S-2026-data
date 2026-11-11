// Code by Happy-David_3367 on 2026 CSP-J2 competition.
// Problem: T4 card
// 1132.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, Time Limit Exceeded on Sample 6
// 1149.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, Time Limit Exceeded on Sample 6
// 1154.cpp ?
#include <bits/stdc++.h>
using namespace std;
// #define MULTI_TEST
int n, m, a[500100], ans[300100];
bool now[300100], dt[300100];
inline void solve() {
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		now[i] = false;
		ans[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		now[a[i]] ^= 1;
	}
	for (int i = 1; i <= m; ++i) {
		dt[i] = now[i];
		if (now[i]) {
			++ans[i];
		}
	}
	for (int i = 2; i <= m; ++i) {
		dt[a[i - 1]] ^= 1;
		for (int j = 1; j <= m; ++j) {
			now[j] ^= dt[j];
			ans[j] += now[j];
		}
		// How to minimize the time complexity here??
		// We need a solution, probably lowers the complexity from O(M^2) to O(M).
		// ... I'll test and submit this solution first. At least I can get 76%
	}
	for (int i = 1; i <= m; ++i) {
		printf ("%d ", ans[i]);
	}
	printf ("\n");
}
inline void main0(long long start_clock = 0) {
	int T = 1;
	#ifdef MULTI_TEST
		scanf ("%d", &T);
	#endif
	while (T--) {
		solve ();
	}
	long long ret = clock () - start_clock;
	#ifdef Happy_David_3367_FLAG
		printf ("Run time: %.6Lf sec.\n", ret * (long double) 1 / CLOCKS_PER_SEC);
	#endif
}
int main() {
	const string prob = "card";
	#ifndef Happy_David_3367_FLAG
		freopen ((prob + ".in").c_str (), "r", stdin);
		freopen ((prob + ".out").c_str (), "w", stdout);
		main0 ();
	#else
		const int samples = 6;
		const string filename = "1154";
		for (int t = 1; t <= samples; ++t) {
			printf ("Running Sample %d...\n", t);
			freopen ((prob + to_string (t) + ".in").c_str (), "r", stdin);
			freopen ((filename + '.' + prob + to_string (t) + ".out").c_str (), "w", stdout);
			main0 (clock ());
			fclose (stdin);
			fclose (stdout);
		}
		printf ("Completed all %d samples.\n", samples);
	#endif
	return 0;
}
// Head Snippet
/*
cspj@bnu-virtual-machine:~/Desktop/BJ-J02217/card$ diff 1149.cpp 1154.cpp
4c4,5
< // 1149.cpp ?
---
> // 1149.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, Time Limit Exceeded on Sample 6
> // 1154.cpp ?
8c9
< int n, m, a[500100], ans, out[300100];
---
> int n, m, a[500100], ans[300100];
14c15
<               out[i] = 0;
---
>               ans[i] = 0;
20d20
<       ans = 0;
22d21
<               ans += now[i];
23a23,25
>               if (now[i]) {
>                       ++ans[i];
>               }
25d26
<       ++out[ans];
28d28
<               ans = 0;
31c31
<                       ans += now[j];
---
>                       ans[j] += now[j];
33d32
<               ++out[ans];
39c38
<               printf ("%d ", out[i]);
---
>               printf ("%d ", ans[i]);
64c63
<               const string filename = "1149";
---
>               const string filename = "1154";
*/
/*
cspj@bnu-virtual-machine:~/Desktop/BJ-J02217/card$ diff 1132.cpp 1149.cpp
3c3,4
< // 1132.cpp ?
---
> // 1132.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, Time Limit Exceeded on Sample 6
> // 1149.cpp ?
7,8c8,9
< int n, m, a[500100], ans;
< bool now[500100], dt[500100];
---
> int n, m, a[500100], ans, out[300100];
> bool now[300100], dt[300100];
12a14
>               out[i] = 0;
23c25
<       printf ("%d ", ans);
---
>       ++out[ans];
31c33
<               printf ("%d ", ans);
---
>               ++out[ans];
35a38,40
>       for (int i = 1; i <= m; ++i) {
>               printf ("%d ", out[i]);
>       }
59c64
<               const string filename = "1132";
---
>               const string filename = "1149";
*/