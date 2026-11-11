/*The code is from koukilee(luogu@)*/
#include <bits/stdc++.h>

typedef long long i64; typedef int i32;

const i64 MAXN = 1010100, INF = 992010081220091007;

inline void read (i64 &x) {scanf ("%lld", &x);}
inline void print (i64 x) {printf ("%lld", x);}
inline void put (i64 x) {print (x); putchar ('\n');}

/*
	".ans" //freopen 
	希望能进迷惑行为  
	今年高二了，退役了一年回来参加，真的是最后一次了，后面不会再有机会了 
	一路走来还是挺感慨的，即使没有取得特别好的成绩
	但是竞赛真的让我见到了不一样的世界。
	这里有一起学习的伙伴，有数不尽的未知.
	每个人都在低谷中跋涉，希望最终可以取得属于我们自己的亮光。 
	未来，会是什么样子的呢。 
	 
	感觉今年图论不少啊，加油吧，现在开T1 
	感觉像是贪心，序列相当于只能加不能减，然后求构成同一个数字，然后加的数字不能超过 m
	肯定最后加到一个出现过的数字不会比没出现过的更优秀
	所以我们考虑枚举最后加成哪一个数字
	然后后面的不用考虑，直接往前面看，肯定优先填充离自己比较近的
	那么这么做就是 O(n^2)
	我们考虑前缀和之后二分，这样时间复杂度降低到 O(n\log n)
	加油 
	为什么过不了T3 呢？哦我懂了，没改完 
	ok 过了，现在14:42可以的，加油，开下一题
	
	所有题目都打完了，现在分数 \in [0, 263] 也算是圆满了吧。 
*/

i64 n, m, a[MAXN], s[MAXN], ans;

inline i64 check (i64 l, i64 r) {
	return a[r] * (r - l + 1) - (s[r] - s[l - 1]) <= m;
}

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout); 
	read (n), read (m);
	
	for (i32 i = 1; i <= n; i++) read (a[i]);
	
	std::sort (a + 1, a + n + 1);
	
	for (i32 i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	
	for (i32 i = 1; i <= n; i++) {
		i64 l = 1, r = i, pos = i;
		
		while (l <= r) {
			i64 mid = (l + r) >> 1;
			if (check (mid, i) /*这一个位置要考虑*/)
				r = mid - 1, pos = mid;
			else l = mid + 1;
		}
		
		ans = std::max (ans, i - pos + 1);
	}
	
	put (ans);
	return 0;
}
