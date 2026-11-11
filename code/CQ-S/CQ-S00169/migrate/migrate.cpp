/*The code is from koukilee(luogu@)*/
#include <bits/stdc++.h>

typedef long long i64; typedef int i32;

const i64 MAXN = 1010100, INF = 992010081220091007;

inline void read (i64 &x) {scanf ("%lld", &x);}
inline void print (i64 x) {printf ("%lld", x);}
inline void put (i64 x) {print (x); putchar ('\n');}

/*
	感觉t2复杂度有点问题，先继续做吧
	不对啊，算错了好像，不管不管，现在两百分，加油
	这个有点难度感觉，计数题，并且数据范围还不小，感觉只能 O(n) 左右做
	想要路径最短，那么毋庸置疑，肯定是每次都飞的最远才可能实现
	考虑n^2怎么做考虑什么时候会产生且仅产生一个所谓双路径岛屿
	当且仅当存在 a b c d，然后a -> c -> d，a -> b -> d 是两个合法方案
	这个时候，左右两端可以拼接不存在这样情况的岛屿了
	那么 O(n^2) 的做法就极其明了了，选出一个这样的长度为 4 的序列，然后考虑往后面加，直到不合法
	前面同理，然后两个相乘即可
	我再手摸样例看看，欸等等哪里这么简单，这个只是长度为 2 的情况
	发现长度大于 2 的时候，若一个点能到达的数量大于 2，那么这样首先肯定是不合法的
	其次我们其实是想要保证这一段区间内的所有数连的边数 \le 2 
	并且一定是临近的那几个，发现归因过来，还是刚刚d = 2 的情况，然后往外面添散点 
	不对啊，他其实只看你最长链，如果多接了其他更慢的
	可能最长路径会被替代，这样可以看成一个散点组
	可以接入一个对的上面，，，
	这就很麻烦了，我感觉在想一会吧，想不出来得快点打暴力了
	考虑暴力吧，应该没那么简单
	O(n^2)考虑怎么做
	考虑左端点固定，右端点加入一个数
	从左边转移，假设不考虑方案数的情况向左边枚举能到达这个点的点
	且距离最小，如果可以方案数累加，最后如果这个点方案数是2 就加入贡献
	复杂度 O(n^3) 24 分可以先打打 ok这一部分拿到了
	考虑如何优化到 n^2
	发现这一步，无疑是先找前面一段区间内的最小值，这一部分可以滑动窗口，于是肯定是可以做到 O(n^2)
	那么我们先鸽一会，看看后面的部分分
	ABC 的部分分也是很丰厚的
	考虑等差数列,这种情况我预计超过一定长度的区间一定不行
	首先，d大于三的时候就一定不可能了，很好说明 
	那么考虑 d = 2 的情况，但是其实也不是这样
	应该是说只要有能往后面连接超过三个点的都一定不行
	那么考虑最多连接两个点的呢？长度为 4 可以，可以且仅可以这样
	长度为 1 呢？一定不可能，行那就先写写看 
	完全没研究清楚，还是把suba打完把 
	完了，存在一个前面清除后面不清除的问题啊 
	估计40 分到手没啥问题了，但是还是把前面的简单部分代码放进来保险点 
	真力竭了，40分，现在17：30必须打T4了 
	现在18：00
	这个8分到底能不能打出来啊，，，
	wk好像可以打表找规律啊，又来了八分 
	真力竭了，感觉不太可能对，只是样例水了一点而已。
	哎 
*/

i64 c, T, n, d, a[MAXN], dl[MAXN], p[MAXN], ans, q[MAXN];
std::unordered_map <i64, i64> pre;

inline void SUB_30 ()  {
	read (T);
	
	while (T--) {
		read (n), read (d);
		
		for (i32 i = 1; i <= n; i++)
			read (a[i]);
		
		for (i32 l = 1; l <= n; l++) {
			for (i32 r = l; r <= n; r++)
				dl[r]/*最小长度*/ = INF, p[r]/*方案数*/ = 0;
			
			dl[l] = 1, p[l] = 1;
			
			for (i32 r = l + 1; r <= n; r++) {
				for (i32 k = r - 1; k >= l && a[r] - a[k] <= d; k--) 
					dl[r] = std::min (dl[r], dl[k] + 1);
				for (i32 k = r - 1; k >= l && a[r] - a[k] <= d; k--) 
					if (dl[r] == dl[k] + 1)
						p[r] += p[k];
				
				ans += p[r] == 2;
			}
		}
		
		put (ans);
		
		ans = 0;
		
		for (i32 i = 1; i <= n; i++)
			dl[i] = p[i] = 0;
	}
}

inline void SUB_A () {
	read (T);
	
	while (T--) {
		read (n), read (d);
		
		for (i32 i = 1; i <= n; i++)
			read (a[i]);
		
		for (i32 l = 1; l <= n; l++) {
			for (i32 r = l; r <= n; r++)
				dl[r]/*最小长度*/ = INF, p[r]/*方案数*/ = 0;
			
			dl[l] = 1, p[l] = 1;
			
			i64 hd = 1, tl = 0; q[++tl] = l; pre.clear ();
			pre[1]++;
			
			i64 kd = l;
			
			for (i32 r = l + 1; r <= n; r++) {
//				for (i32 k = r - 1; k >= l && a[r] - a[k] <= d; k--) 
//					dl[r] = std::min (dl[r], dl[k] + 1);
				while (hd <= tl && a[r] - a[q[hd]] > d)
					hd++;
					
				if (hd > tl) break; 
				
				for (i32 i = kd; i < q[hd]; i++)
					pre[dl[i]] -= p[i];
				kd = q[hd];
				
//				for (i32 k = r - 1; k >= l && a[r] - a[k] <= d; k--) 
//					if (dl[r] == dl[k] + 1)
//						p[r] += p[k];
				

				dl[r] = dl[q[hd]] + 1, p[r] = pre[dl[q[hd]]];
//				printf ("%d %d %lld | L %lld r %lld | q[hd] %lld\n", l, r, pre[dl[q[hd]]], hd, tl, dl[q[hd]]);	
//				printf ("%d %d DL %lld PR %lld\n", l, r, dl[r], p[r]);	
//				printf ("5 %lld %lld %lld\n", p[q[2]], p[q[3]], pre[2]);
				ans += (p[r] == 2);
				pre[dl[r]] += p[r];
				
//				printf ("%lld %lld\n", p[r], pre[dl[r]]);
				
//				put (p[r]);
				
				while (hd <= tl && dl[r] < dl[q[tl]])
					tl--;
				q[++tl] = r;
			}
		}
		
		put (ans);
		
		ans = 0;
		
		for (i32 i = 1; i <= n; i++)
			dl[i] = p[i] = 0;
	}
}

inline void SUB_B ()  {
	read (T);
	
	while (T--) {
		read (n), read (d);
		
		for (i32 i = 1; i <= n; i++)
			read (a[i]);
		
		i64 mx = 0;
		for (i32 i = 2; i <= n; i++)
			if (a[i] - a[1] <= d) mx = i;
		
		if (mx <= 2) put (0);
		else put ((n - mx * 2 + 3) > 0 ? n - mx * 2 + 3 : 0);
	}
}

int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
	read (c);
//	SUB_A ();
//	if (c <= 10) 
//	else if (c == 11 || c == 12) SUB_B ();
	
	if (c <= 6) SUB_30 ();
	else if (c <= 10) SUB_A ();
	else SUB_B ();
	return 0;
}
