// Code by Happy-David_3367 on 2026 CSP-S2 competition.
// Problem: T2_subway 地铁(subway)
// 1524.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, 6, 7
// 1621.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, 6, 7
// 1629.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, 6, 7
// 1650.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, 6, 7
// 1656.cpp Wrong Answer on Sample 2, 3, 4, 5, 6, 7
// 1700.cpp Wrong Answer on Sample 2, 3, 4, 5, 6, 7
// 1702.cpp Wrong Answer on Sample 2, 3, 4, 5, 6, 7
// 1717.cpp Wrong Answer on Sample 2, 3, 4, 5, 6, 7
// 1729.cpp Wrong Answer on Sample 3, 4, 5, 6, 7
// 1735.cpp ?
#include <bits/stdc++.h>
using namespace std;
// #define MULTI_TEST
/*
The problem looks really hard, but it's actually really ez, at least I think...
First, we can figure out that the problem only needs us to calcuate the walking time.
That means, we don't have to calculate the time we spend on the subway line.
So we can assume, we can instantly teleport to the station where we have the same subway line passed.
Then it's easy to find that we can make every line number a 'station' number, for example, -line.
If two stations 'a', 'b' both have subway 'line' passed, we can link ('a', '-line', 0) and ('b', '-line', 0).
(NOTE: (u, v, w) means that we have an undirected edge between 'u' and 'v', and de distance is 'w'.)
Review the problem, and we can find out that we don't have to consider the station.
Because of the 'teleportation', we don't have to know which station we are,
we can change this problem into the switches between the subway lines.
Since there are multi edges, we just need the edge that has minimum distance.
Therefore, we can solve this problem with O(N^2) time and memory complexity.
Since n <= 500, we can pass this problem.
1. Build a 2D-array to show the edges between subway lines.
2. Build a vector array to show the station ---> line connection.
3. Pre-calculate the distance of lines, which may cost... O(N^3)?! n <= 500, hope iters speed is 10^9 per sec...
4. For each query, O(D^2) brute-force the inital lines, and O(1) to calculate.
5. REMINDER: Don't forget to add the time between the extrance and line, line and exit!!!
Not sure why d <= 20...
*/
// N <= 500, M <= sumK <= 5 * 10^5, D <= 20, Q <= 10^5.
int c, n, m, d, q; // n: lines; m: stations
long long w[500100]; // Distance between the entrance/exit and the station.
int k[555]; // Station cnt on the subway line.
vector<int> a[555]; // Stations number that will be passed by a subway line #index.
vector<long long> t[555]; // Distance between the station and the subway line.
long long lines[555][555], dp[555][555][555];
vector<pair<int, long long>> station2lines[500100]; // first: line#; second: time between
inline void solve() {
	scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			lines[i][j] = 1LL << 61LL;
			dp[0][i][j] = 1LL << 61LL;
		}
	}
	for (int i = 1; i <= m; ++i) {
		station2lines[i].clear ();
	}
	for (int i = 1; i <= m; ++i) {
		scanf ("%lld", &w[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &k[i]);
		a[i].clear ();
		t[i].clear ();
		a[i].resize (k[i] + 2);
		t[i].resize (k[i] + 2);
		for (int j = 1; j <= k[i]; ++j) {
			scanf ("%d%lld", &a[i][j], &t[i][j]);
			station2lines[a[i][j]].push_back ({i, t[i][j]});
			#ifdef Happy_David_3367_FLAG
				fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <building station2lines] station %d pushed a connection to line %d, cost %lld to walk.\n", a[i][j], i, t[i][j]);
			#endif // Debug Snippet
		}
	}
	for (int i = 1; i <= m; ++i) {
		int sz = station2lines[i].size ();
		for (int u = 0; u < sz; ++u) {
			for (int v = u + 1; v < sz; ++v) {
				#ifdef Happy_David_3367_FLAG
					fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <before ckmin>] lines[%d][%d] = %lld.\n", station2lines[i][u].first, station2lines[i][v].first, lines[station2lines[i][u].first][station2lines[i][v].first]);
					fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <before ckmin>] lines[%d][%d] = %lld.\n", station2lines[i][v].first, station2lines[i][u].first, lines[station2lines[i][v].first][station2lines[i][u].first]);
					fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <initing dist>] station %d checking, between line %d and %d, which costs %lld + %lld.\n", i, station2lines[i][u].first, station2lines[i][v].first, station2lines[i][u].second, station2lines[i][v].second);
				#endif // Debug Snippet
				lines[station2lines[i][u].first][station2lines[i][v].first] = min (lines[station2lines[i][u].first][station2lines[i][v].first], station2lines[i][u].second + station2lines[i][v].second);
				lines[station2lines[i][v].first][station2lines[i][u].first] = min (lines[station2lines[i][v].first][station2lines[i][u].first], station2lines[i][v].second + station2lines[i][u].second);
				dp[0][station2lines[i][u].first][station2lines[i][v].first] = lines[station2lines[i][u].first][station2lines[i][v].first];
				dp[0][station2lines[i][v].first][station2lines[i][u].first] = lines[station2lines[i][v].first][station2lines[i][u].first];
				#ifdef Happy_David_3367_FLAG
					fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <inital distance>] lines[%d][%d] = %lld.\n", station2lines[i][u].first, station2lines[i][v].first, lines[station2lines[i][u].first][station2lines[i][v].first]);
					fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <inital distance>] lines[%d][%d] = %lld.\n", station2lines[i][v].first, station2lines[i][u].first, lines[station2lines[i][v].first][station2lines[i][u].first]);
				#endif // Debug Snippet
			}
		}
	}
	for (int m = 1; m <= n; ++m) {
		for (int s = 1; s <= n; ++s) {
			for (int e = s + 1; e <= n; ++e) {
				dp[m][s][e] = min (dp[m - 1][s][e], dp[m - 1][s][m] + dp[m - 1][m][e]);
				dp[m][e][s] = min (dp[m - 1][e][s], dp[m - 1][e][m] + dp[m - 1][m][s]);
			}
		}
	} // Floyd, hope it's right...
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			lines[i][j] = dp[n][i][j];
			#ifdef Happy_David_3367_FLAG
				fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <floyd distance>] lines[%d][%d] = %lld.\n", i, j, lines[i][j]);
			#endif // Debug Snippet
		}
	}
	for (int _ = 1; _ <= q; ++_) {
		int x, y;
		scanf ("%d%d", &x, &y);
		int szx = station2lines[x].size (), szy = station2lines[y].size ();
		#ifdef Happy_David_3367_FLAG
			fprintf (stderr, "[Happy_David_3367_FLAG] [Flag Query#%d] Station %d, %d each have %d, %d lines.\n", _, x, y, szx, szy);
		#endif // Debug Snippet
		long long ans = 1LL << 62LL;
		for (int i = 0; i < szx; ++i) {
			for (int j = 0; j < szy; ++j) {
				long long res = w[x] + station2lines[x][i].second + lines[station2lines[x][i].first][station2lines[y][j].first] + station2lines[y][j].second + w[y];
				ans = min (ans, res);
				#ifdef Happy_David_3367_FLAG
					fprintf (stderr, "[Happy_David_3367_FLAG] [Flag Query#%d] Distance using Line %d and %d is %lld.\n", _, station2lines[x][i].first, station2lines[y][j].first, res);
					fprintf (stderr, "[Happy_David_3367_FLAG] [Flag Query#%d] %lld = %lld + %lld + %lld + %lld + %lld\n", _, res, w[x], station2lines[x][i].second, lines[station2lines[x][i].first][station2lines[y][j].first], station2lines[y][j].second, w[y]);
				#endif // Debug Snippet
			}
		}
		printf ("%lld\n", ans);
	}
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
	const string prob_name = "subway";
	#ifndef Happy_David_3367_FLAG
		freopen ((prob_name + ".in").c_str (), "r", stdin);
		freopen ((prob_name + ".out").c_str (), "w", stdout);
		main0 ();
	#else
		const int samples_cnt = 7;
		const string program_prefix = "1735";
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
/*
csps@ubuntu:~/Desktop/BJ-S02205/T2_subway$ diff 1729.cpp 1735.cpp
11c11,12
< // 1729.cpp ?
---
> // 1729.cpp Wrong Answer on Sample 3, 4, 5, 6, 7
> // 1735.cpp ?
48a50
>                       dp[0][i][j] = 1LL << 61LL;
149c151
<               const string program_prefix = "1729";
---
>               const string program_prefix = "1735";
*/
/*
csps@ubuntu:~/Desktop/BJ-S02205/T2_subway$ diff 1717.cpp 1729.cpp
10c10,11
< // 1717.cpp ?
---
> // 1717.cpp Wrong Answer on Sample 2, 3, 4, 5, 6, 7
> // 1729.cpp ?
116c117
<                               long long res = w[x] + station2lines[x][i].second + lines[station2lines[x][i].first][station2lines[y][j].first] + station2lines[y][i].second + w[y];
---
>                               long long res = w[x] + station2lines[x][i].second + lines[station2lines[x][i].first][station2lines[y][j].first] + station2lines[y][j].second + w[y];
120c121
<                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag Query#%d] %lld = %lld + %lld + %lld + %lld + %lld\n", _, res, w[x], station2lines[x][i].second, lines[station2lines[x][i].first][station2lines[y][j].first], station2lines[y][i].second, w[y]);
---
>                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag Query#%d] %lld = %lld + %lld + %lld + %lld + %lld\n", _, res, w[x], station2lines[x][i].second, lines[station2lines[x][i].first][station2lines[y][j].first], station2lines[y][j].second, w[y]);
148c149
<               const string program_prefix = "1717";
---
>               const string program_prefix = "1729";
*/
/*
csps@ubuntu:~/Desktop/BJ-S02205/T2_subway$ diff 1702.cpp 1717.cpp
9c9,10
< // 1702.cpp ?
---
> // 1702.cpp Wrong Answer on Sample 2, 3, 4, 5, 6, 7
> // 1717.cpp ?
118a120
>                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag Query#%d] %lld = %lld + %lld + %lld + %lld + %lld\n", _, res, w[x], station2lines[x][i].second, lines[station2lines[x][i].first][station2lines[y][j].first], station2lines[y][i].second, w[y]);
146c148
<               const string program_prefix = "1702";
---
>               const string program_prefix = "1717";
*/
/*
csps@ubuntu:~/Desktop/BJ-S02205/T2_subway$ diff 1700.cpp 1702.cpp
8c8,9
< // 1700.cpp ?
---
> // 1700.cpp Wrong Answer on Sample 2, 3, 4, 5, 6, 7
> // 1702.cpp ?
64c65
<                               fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <building station2lines] station %d pushed a connection to line %d, cost %d to walk.\n", a[i][j], i, t[i][j]);
---
>                               fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <building station2lines] station %d pushed a connection to line %d, cost %lld to walk.\n", a[i][j], i, t[i][j]);
107a109,111
>               #ifdef Happy_David_3367_FLAG
>                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag Query#%d] Station %d, %d each have %d, %d lines.\n", _, x, y, szx, szy);
>               #endif // Debug Snippet
111c115
<                               long long res = station2lines[x][i].second + lines[station2lines[x][i].first][station2lines[y][j].first] + station2lines[y][i].second;
---
>                               long long res = w[x] + station2lines[x][i].second + lines[station2lines[x][i].first][station2lines[y][j].first] + station2lines[y][i].second + w[y];
114c118
<                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag Query#%d] i = %d, j = %d, res = %lld, ans = %lld.\n", _, i, j, res, ans);
---
>                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag Query#%d] Distance using Line %d and %d is %lld.\n", _, station2lines[x][i].first, station2lines[y][j].first, res);
118,119d121
<               ans += w[x];
<               ans += w[y];
144c146
<               const string program_prefix = "1700";
---
>               const string program_prefix = "1702";
*/
/*
csps@ubuntu:~/Desktop/BJ-S02205/T2_subway$ diff 1656.cpp 1700.cpp
7c7,8
< // 1656.cpp ?
---
> // 1656.cpp Wrong Answer on Sample 2, 3, 4, 5, 6, 7
> // 1700.cpp ?
54a56,57
>               a[i].clear ();
>               t[i].clear ();
141c144
<               const string program_prefix = "1656";
---
>               const string program_prefix = "1700";
*/
/*
csps@ubuntu:~/Desktop/BJ-S02205/T2_subway$ diff 1650.cpp 1656.cpp
6c6,7
< // 1650.cpp ?
---
> // 1650.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, 6, 7
> // 1656.cpp ?
39a41
>       scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
48d49
<       scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
140c141
<               const string program_prefix = "1650";
---
>               const string program_prefix = "1656";
*/
/*
csps@ubuntu:~/Desktop/BJ-S02205/T2_subway$ diff 1629.cpp 1650.cpp
5c5,6
< // 1629.cpp ?
---
> // 1629.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, 6, 7
> // 1650.cpp ?
59c60
<                               fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <building station--->line] station %d pushed a connection to line %d, cost %d to walk.\n", a[i][j], i, t[i][j]);
---
>                               fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <building station2lines] station %d pushed a connection to line %d, cost %d to walk.\n", a[i][j], i, t[i][j]);
66a68,72
>                               #ifdef Happy_David_3367_FLAG
>                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <before ckmin>] lines[%d][%d] = %lld.\n", station2lines[i][u].first, station2lines[i][v].first, lines[station2lines[i][u].first][station2lines[i][v].first]);
>                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <before ckmin>] lines[%d][%d] = %lld.\n", station2lines[i][v].first, station2lines[i][u].first, lines[station2lines[i][v].first][station2lines[i][u].first]);
>                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <initing dist>] station %d checking, between line %d and %d, which costs %lld + %lld.\n", i, station2lines[i][u].first, station2lines[i][v].first, station2lines[i][u].second, station2lines[i][v].second);
>                               #endif // Debug Snippet
134c140
<               const string program_prefix = "1629";
---
>               const string program_prefix = "1650";
*/
/*
csps@ubuntu:~/Desktop/BJ-S02205/T2_subway$ diff 1621.cpp 1629.cpp
4c4,5
< // 1621.cpp ?
---
> // 1621.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, 6, 7
> // 1629.cpp ?
56a58,60
>                       #ifdef Happy_David_3367_FLAG
>                               fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <building station--->line] station %d pushed a connection to line %d, cost %d to walk.\n", a[i][j], i, t[i][j]);
>                       #endif // Debug Snippet
130c134
<               const string program_prefix = "1621";
---
>               const string program_prefix = "1629";
*/
/*
csps@ubuntu:~/Desktop/BJ-S02205/T2_subway$ diff 1524.cpp 1621.cpp
3c3,4
< // 1524.cpp ?
---
> // 1524.cpp Wrong Answer on Sample 1, 2, 3, 4, 5, 6, 7
> // 1621.cpp ?
65a67,70
>                               #ifdef Happy_David_3367_FLAG
>                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <inital distance>] lines[%d][%d] = %lld.\n", station2lines[i][u].first, station2lines[i][v].first, lines[station2lines[i][u].first][station2lines[i][v].first]);
>                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <inital distance>] lines[%d][%d] = %lld.\n", station2lines[i][v].first, station2lines[i][u].first, lines[station2lines[i][v].first][station2lines[i][u].first]);
>                               #endif // Debug Snippet
79a85,87
>                       #ifdef Happy_David_3367_FLAG
>                               fprintf (stderr, "[Happy_David_3367_FLAG] [Flag <floyd distance>] lines[%d][%d] = %lld.\n", i, j, lines[i][j]);
>                       #endif // Debug Snippet
82c90
<       for (int i = 1; i <= q; ++i) {
---
>       for (int _ = 1; _ <= q; ++_) {
90a99,101
>                               #ifdef Happy_David_3367_FLAG
>                                       fprintf (stderr, "[Happy_David_3367_FLAG] [Flag Query#%d] i = %d, j = %d, res = %lld, ans = %lld.\n", _, i, j, res, ans);
>                               #endif // Debug Snippet
119c130
<               const string program_prefix = "1524";
---
>               const string program_prefix = "1621";
*/