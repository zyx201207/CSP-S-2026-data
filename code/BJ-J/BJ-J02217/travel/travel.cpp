// Code by Happy-David_3367 on 2026 CSP-J2 competition.
// Problem: T1 travel
// 0901.cpp ?
#include <bits/stdc++.h>
using namespace std;
// #define MULTI_TEST
int c1, c2;
char s1[5], s2[5];
inline bool same_side(char a, char b) {
	if (a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C') {
		return true;
	}
	if ((a == 'D' && a == 'F') || (b == 'D' && b == 'F')) {
		return true;
	}
	return false;
}
inline bool adj(char a, char b) {
	if (a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C' && abs (a - b) == 1) {
		return true;
	}
	if (min (a, b) == 'D' && max (a, b) == 'F') {
		return true;
	}
	return false;
}
inline void solve() {
	scanf ("%d %s %d %s", &c1, s1 + 1, &c2, s2 + 1);
	if (c1 != c2) {
		printf ("0000\n");
	} else {
		printf ("1");
		if (!(s1[1] == s2[1] && s1[2] == s2[2])) {
			printf ("000\n");
		} else {
			printf ("1");
			if (!((s1[3] >= 'A' && s1[3] <= 'C' && s2[3] >= 'A' && s2[3] <= 'C') || ((s1[3] == 'D' && s1[3] == 'F') || (s2[3] == 'D' && s2[3] == 'F')))) {
				printf ("00\n");
			} else {
				printf ("1");
				if (!((s1[3] >= 'A' && s1[3] <= 'C' && s2[3] >= 'A' && s2[3] <= 'C' && abs (s1[3] - s2[3]) == 1) || (min (s1[3], s2[3]) == 'D' && max (s1[3], s2[3]) == 'F'))) {
					printf ("0\n");
				} else {
					printf ("1\n");
				}
			}
		}
	}
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
	const string prob = "travel";
	#ifndef Happy_David_3367_FLAG
		freopen ((prob + ".in").c_str (), "r", stdin);
		freopen ((prob + ".out").c_str (), "w", stdout);
		main0 ();
	#else
		const int samples = 5;
		for (int t = 1; t <= samples; ++t) {
			printf ("Running Sample %d...\n", t);
			freopen ((prob + to_string (t) + ".in").c_str (), "r", stdin);
			freopen ((prob + to_string (t) + ".out").c_str (), "w", stdout);
			main0 (clock ());
			fclose (stdin);
			fclose (stdout);
		}
		printf ("Completed all %d samples.\n", samples);
	#endif
	return 0;
}
// Head Snippet