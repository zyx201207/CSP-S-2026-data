// Code by Happy-David_3367 on 2026 CSP-J2 competition.
// Problem: T2 string
// 0918.cpp ?
#include <bits/stdc++.h>
using namespace std;
// #define MULTI_TEST
/*
I'll list my thoughts here
I think there are exactly (or less?) 3 possible choices
1. change the chars in the tail half to the head half
2. same as 1, but reverse it
3. wait
There are actually exact 1 solution
just use L and R pointer and loop once
ok I understand...
*/
int n, Lp, Rp, Lleft, Rleft;
vector<pair<char, int>> s;
long long ans;
inline void solve() {
	scanf ("%d", &n);
	s.resize (n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d %c", &s[i].second, &s[i].first);
	}
	Lp = 1;
	Rp = n;
	Lleft = s[1].second;
	Rleft = s[n].second;
	ans = 0;
	for (int t = 1; Lp < Rp; ++t) {
		int nowc = min (Lleft, Rleft);
		if (s[Lp].first != s[Rp].first) {
			ans += nowc;
		}
		Lleft -= nowc;
		Rleft -= nowc;
		#ifdef Happy_David_3367_FLAG
			printf ("[Happy_David_3367_FLAG] [Flag %d] Lp = %d, Rp = %d, nowc = %d, Lleft = %d, Rleft = %d, ans = %lld\n", t, Lp, Rp, nowc, Lleft, Rleft, ans);
		#endif // Debug Snippet
		if (!Lleft) {
			++Lp;
			Lleft = s[Lp].second;
		}
		if (!Rleft) {
			--Rp;
			Rleft = s[Rp].second;
		}
	}
	printf ("%lld\n", ans);
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
		printf ("Run time: %.3Lf sec.\n", ret * (long double) 1 / CLOCKS_PER_SEC);
	#endif
}
int main() {
	const string prob = "string";
	#ifndef Happy_David_3367_FLAG
		freopen ((prob + ".in").c_str (), "r", stdin);
		freopen ((prob + ".out").c_str (), "w", stdout);
		main0 ();
	#else
		const int samples = 6;
		const string filename = "0918";
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