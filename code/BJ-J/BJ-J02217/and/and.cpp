// Code by Happy-David_3367 on 2026 CSP-J2 competition.
// Problem: T3 and
// 0945.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
// 1023.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
// 1025.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
// 1036.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
// 1053.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
// 1056.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
// 1113.cpp Wrong Answer on Sample 2, 5
// 1120.cpp Wrong Answer on Sample 2
// 1123.cpp ?
#include <bits/stdc++.h>
using namespace std;
// #define MULTI_TEST
/*
Here's my thought
Build a 01Trie??
That might work...
High digit first
Building part is ez
For query part...
0. We are now on vertex f, our left(0) child is l, right(1) is r.
1. if size[r] >= m, go to right.
2. if size[l] >= m, go to left.
3. What if we me a situation where two conditions both false??
...
... We should go up to the father vertex, right?
Is this time complexity right???
Wait... It might really be the correct solution
Let me write
*/
struct Trie01 {
	struct Trie01Node {
		int cnt, nxt[2];
		vector<int> end;
		Trie01Node() {
			cnt = 0;
			end.clear ();
			nxt[0] = 0;
			nxt[1] = 0;
		}
		void newend(int p) {
			++cnt;
			end.push_back (p);
		}
	};
	vector<Trie01Node> nodes;
	int cnt;
	Trie01() {
		nodes.clear ();
		nodes.push_back (Trie01Node ());
		cnt = 0;
	}
	void clear() {
		*this = Trie01 ();
	}
	void insert(int x, int idx = 0) {
		int p = 0;
		for (int i = 31; i >= 0; --i) {
			int now = (x >> i) & 1;
			++nodes[p].cnt;
			if (!nodes[p].nxt[now]) {
				nodes[p].nxt[now] = ++cnt;
				nodes.push_back (Trie01Node ());
			}
			p = nodes[p].nxt[now];
		}
		nodes[p].newend (idx);
		nodes[0].cnt = -1;
		#ifdef Happy_David_3367_FLAG
			// printf ("[Happy_David_3367_FLAG] [Flag <01trie insertion>] %d (idx #%d) inserted, end pos %d.\n", x, idx, p);
		#endif // Debug Snippet
	}
} trie;
int n, m, a[200100];
long long sclock;
int getans(int level2, int tpos) {
	#ifdef Happy_David_3367_FLAG
		if (clock () - sclock > CLOCKS_PER_SEC * 1.5) {
			return -1;
		}
	#endif
	if (level2 < 0) {
		return 0;
	}
	#ifdef Happy_David_3367_FLAG
		printf ("[Happy_David_3367_FLAG] [Flag getans (level2 = %d, tpos = %d)] Now tPos status: cnt = %d, nxt[0] = %d, nxt[1] = %d\n", level2, tpos, trie.nodes[tpos].cnt, trie.nodes[tpos].nxt[0], trie.nodes[tpos].nxt[1]);
		printf ("[Happy_David_3367_FLAG] [Flag getans (level2 = %d, tpos = %d)] Now 0son status: cnt = %d, nxt[0] = %d, nxt[1] = %d\n", level2, tpos, trie.nodes[trie.nodes[tpos].nxt[0]].cnt, trie.nodes[trie.nodes[tpos].nxt[0]].nxt[0], trie.nodes[trie.nodes[tpos].nxt[0]].nxt[1]);
		printf ("[Happy_David_3367_FLAG] [Flag getans (level2 = %d, tpos = %d)] Now 1son status: cnt = %d, nxt[0] = %d, nxt[1] = %d\n", level2, tpos, trie.nodes[trie.nodes[tpos].nxt[1]].cnt, trie.nodes[trie.nodes[tpos].nxt[1]].nxt[0], trie.nodes[trie.nodes[tpos].nxt[1]].nxt[1]);
	#endif // Debug Snippet
	if (trie.nodes[tpos].nxt[1] && trie.nodes[trie.nodes[tpos].nxt[1]].cnt >= m) {
		return getans (level2 - 1, trie.nodes[tpos].nxt[1]) + (1 << level2);
	}
	int res = 0;
	if (trie.nodes[tpos].nxt[0] && trie.nodes[trie.nodes[tpos].nxt[0]].cnt) {
		res = max (res, getans (level2 - 1, trie.nodes[tpos].nxt[0]));
	}
	if (trie.nodes[tpos].nxt[1] && trie.nodes[trie.nodes[tpos].nxt[1]].cnt) {
		res = max (res, getans (level2 - 1, trie.nodes[tpos].nxt[1]));
	}
	return res;
}
inline void solve() {
	trie.clear ();
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i]);
		trie.insert (a[i], i);
	}
	printf ("%d\n", getans (31, 0));
}
inline void main0(long long start_clock = 0) {
	int T = 1;
	#ifdef MULTI_TEST
		scanf ("%d", &T);
	#endif
	while (T--) {
		sclock = start_clock;
		solve ();
	}
	long long ret = clock () - start_clock;
	#ifdef Happy_David_3367_FLAG
		printf ("Run time: %.6Lf sec.\n", ret * (long double) 1 / CLOCKS_PER_SEC);
	#endif
}
int main() {
	const string prob = "and";
	#ifndef Happy_David_3367_FLAG
		freopen ((prob + ".in").c_str (), "r", stdin);
		freopen ((prob + ".out").c_str (), "w", stdout);
		main0 ();
	#else
		const int samples = 5;
		const string filename = "1123";
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
cspj@bnu-virtual-machine:~/Desktop/BJ-J02217/and$ diff 1120.cpp 1123.cpp
10c10,11
< // 1120.cpp ?
---
> // 1120.cpp Wrong Answer on Sample 2
> // 1123.cpp ?
90c91
<       if (trie.nodes[trie.nodes[tpos].nxt[1]].cnt >= m) {
---
>       if (trie.nodes[tpos].nxt[1] && trie.nodes[trie.nodes[tpos].nxt[1]].cnt >= m) {
133c134
<               const string filename = "1120";
---
>               const string filename = "1123";
*/
/*
cspj@bnu-virtual-machine:~/Desktop/BJ-J02217/and$ diff 1113.cpp 1120.cpp
9c9,10
< // 1113.cpp ?
---
> // 1113.cpp Wrong Answer on Sample 2, 5
> // 1120.cpp ?
51a53,55
>       void clear() {
>               *this = Trie01 ();
>       }
98a103
>       trie.clear ();
128c133
<               const string filename = "1113";
---
>               const string filename = "1120";
*/
/*
cspj@bnu-virtual-machine:~/Desktop/BJ-J02217/and$ diff 1056.cpp 1113.cpp
8c8,9
< // 1056.cpp ?
---
> // 1056.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
> // 1113.cpp ?
89c90
<       if (trie.nodes[trie.nodes[tpos].nxt[0]].cnt) {
---
>       if (trie.nodes[tpos].nxt[0] && trie.nodes[trie.nodes[tpos].nxt[0]].cnt) {
92c93
<       if (trie.nodes[trie.nodes[tpos].nxt[1]].cnt) {
---
>       if (trie.nodes[tpos].nxt[1] && trie.nodes[trie.nodes[tpos].nxt[1]].cnt) {
127c128
<               const string filename = "1056";
---
>               const string filename = "1113";
*/
/*
cspj@bnu-virtual-machine:~/Desktop/BJ-J02217/and$ diff 1053.cpp 1056.cpp
7c7,8
< // 1053.cpp ?
---
> // 1053.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
> // 1056.cpp ?
61a63
>               nodes[0].cnt = -1;
67a70
> long long sclock;
68a72,76
>       #ifdef Happy_David_3367_FLAG
>               if (clock () - sclock > CLOCKS_PER_SEC * 1.5) {
>                       return -1;
>               }
>       #endif
73a82,83
>               printf ("[Happy_David_3367_FLAG] [Flag getans (level2 = %d, tpos = %d)] Now 0son status: cnt = %d, nxt[0] = %d, nxt[1] = %d\n", level2, tpos, trie.nodes[trie.nodes[tpos].nxt[0]].cnt, trie.nodes[trie.nodes[tpos].nxt[0]].nxt[0], trie.nodes[trie.nodes[tpos].nxt[0]].nxt[1]);
>               printf ("[Happy_David_3367_FLAG] [Flag getans (level2 = %d, tpos = %d)] Now 1son status: cnt = %d, nxt[0] = %d, nxt[1] = %d\n", level2, tpos, trie.nodes[trie.nodes[tpos].nxt[1]].cnt, trie.nodes[trie.nodes[tpos].nxt[1]].nxt[0], trie.nodes[trie.nodes[tpos].nxt[1]].nxt[1]);
100a111
>               sclock = start_clock;
116c127
<               const string filename = "1053";
---
>               const string filename = "1056";
*/
/*
cspj@bnu-virtual-machine:~/Desktop/BJ-J02217/and$ diff 1036.cpp 1053.cpp
3c3
< // 0945.cpp Wrong Answer on Sample 1, 2, 3,ds, 5
---
> // 0945.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
6c6,7
< // 1036.cpp ?
---
> // 1036.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
> // 1053.cpp ?
77,78c78,80
<       if (trie.nodes[trie.nodes[tpos].nxt[0]].cnt >= m) {
<               return getans (level2 - 1, trie.nodes[tpos].nxt[0]);
---
>       int res = 0;
>       if (trie.nodes[trie.nodes[tpos].nxt[0]].cnt) {
>               res = max (res, getans (level2 - 1, trie.nodes[tpos].nxt[0]));
80c82,85
<       return 0;
---
>       if (trie.nodes[trie.nodes[tpos].nxt[1]].cnt) {
>               res = max (res, getans (level2 - 1, trie.nodes[tpos].nxt[1]));
>       }
>       return res;
111c116
<               const string filename = "1036";
---
>               const string filename = "1053";
*/
/*
cspj@bnu-virtual-machine:~/Desktop/BJ-J02217/and$ diff 1025.cpp 1036.cpp
3c3
< // 0945.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
---
> // 0945.cpp Wrong Answer on Sample 1, 2, 3,ds, 5
5c5,6
< // 1025.cpp ?
---
> // 1025.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
> // 1036.cpp ?
69a71,73
>       #ifdef Happy_David_3367_FLAG
>               printf ("[Happy_David_3367_FLAG] [Flag getans (level2 = %d, tpos = %d)] Now tPos status: cnt = %d, nxt[0] = %d, nxt[1] = %d\n", level2, tpos, trie.nodes[tpos].cnt, trie.nodes[tpos].nxt[0], trie.nodes[tpos].nxt[1]);
>       #endif // Debug Snippet
107c111
<               const string filename = "1025";
---
>               const string filename = "1036";
140,146d143
< 119c120,161
< < // Head Snippet
< \ 文件尾没有换行符
< ---
< > // Head Snippet
< > (added two diff comments, I won't copy them due to the conflicts)
< \ 文件尾没有换行符
*/
/*
cspj@bnu-virtual-machine:~/Desktop/BJ-J02217/and$ diff 1023.cpp 1025.cpp
4c4,5
< // 1023.cpp ?
---
> // 1023.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
> // 1025.cpp ?
83c84
<       printf ("%d\n", getans (32, 0));
---
>       printf ("%d\n", getans (31, 0));
95c96
<               printf ("Run time: %.3Lf sec.\n", ret * (long double) 1 / CLOCKS_PER_SEC);
---
>               printf ("Run time: %.6Lf sec.\n", ret * (long double) 1 / CLOCKS_PER_SEC);
106c107
<               const string filename = "1023";
---
>               const string filename = "1025";
*/
/*
cspj@bnu-virtual-machine:~/Desktop/BJ-J02217/and$ diff 0945.cpp 1023.cpp
3c3,4
< // 0945.cpp ?
---
> // 0945.cpp Wrong Answer on Sample 1, 2, 3, 4, 5
> // 1023.cpp ?
49a51
>                       ++nodes[p].cnt;
58c60
<                       printf ("[Happy_David_3367_FLAG] [Flag <01trie insertion>] %d (idx #%d) inserted, end pos %d.\n", x, idx, p);
---
>                       // printf ("[Happy_David_3367_FLAG] [Flag <01trie insertion>] %d (idx #%d) inserted, end pos %d.\n", x, idx, p);
104c106
<               const string filename = "0945";
---
>               const string filename = "1023";
*/