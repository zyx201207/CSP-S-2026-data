#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
constexpr int N = 5e5+3;
int n, ans = -1;
ll m, a[N], s[N];
int lgfind (int k) {
	int l = 1, r = k, mid = (l + r) >> 1, tans = k;
	while (l <= r) {
		if (a[k+1] * (k - mid + 1) - s[k] + s[mid-1] <= m) {
			tans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
		mid = (l + r) >> 1;
	}
	return tans;
}
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i) scanf ("%lld", &a[i]);
	sort (a+1, a+1+n);
	for (int i = 1; i <= n; ++i) s[i] = a[i] + s[i-1];
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			ans = max (ans, 1);
			continue;
		}
		int tk = lgfind (i-1);
		if (tk == -1) {
			ans = max (ans, 1);
			continue;
		} else {
			ans = max (ans, i-tk+1); 
		}
	}
	printf ("%d", ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
想上迷惑行为大赏
luogu UID:1030133
高二了，最后一个赛季说是
15:11 通过T1全部大样例，并被东鹏特饮瓶盖单杀
15:12 单杀东鹏特饮瓶盖
这T1大样例咋这么小，我咋不会写对拍代码 
怎么又没考DS
我咋啥也不会
这T1估计是橙~下位黄 
15:18 严肃愣神
我这二分查找没写挂吧
应该没挂吧 
*/ 
