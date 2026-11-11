#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
int n;
ll a[N], m, s[N];
struct whz {
	ll val;
	int tot, pos;
} b[N];

ll sum(int l, int r) {
	if(l > r) return 0;
	return s[r]-s[l-1];
}

int bs(ll val, int pos) {
// 从原数组 pos 开始往前走，可以走到的最小的下标 
	int l = 1, r = pos, mid, ret = pos;
	while(l <= r) {
		mid = (l+r)>>1;
		if((pos-mid)*val-sum(mid, pos-1) <= m)
			r = mid-1, ret = mid;
		else l = mid+1;
	}
	return ret;
}

int main() {
//	freopen("C:\\Users\\XDFZ\\Desktop\\crystal\\crystal3.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i=1; i<=n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	int cnt = 0;
	for(int i=1; i<=n; ++i) {
		s[i] = s[i-1]+a[i];
		if(i!=1 && a[i]==a[i-1]) {
			++b[cnt].tot;
			continue;
		} 
		b[++cnt] = {a[i], 1, i};
	}
	int ans = 0;
	for(int i=1; i<=cnt; ++i) {
		int res = bs(b[i].val, b[i].pos);
//		cout<<b[i].val<<' '<<res<<' ';
		res = b[i].pos-res;
//		cout<<res<<' '<<b[i].tot+res<<endl;
		ans = max(ans, b[i].tot+res); // 总数+新增的个数 
	}
	printf("%d\n", ans);
	return 0;
} /*
想到了一个 nlogn 的做法
真的不会爆 long long 吗？计算了一下并不会。 
1. 排升序 去重
2. 二分求：val 变成 b[i]，最少可以到哪个下标（最小的 mid） 
		这里是原数组的下标，不是去重后的。 
	然后计算到这个下标的代价。 
	单调性：随着 mid 减小，代价一定递增。 

大样例没过。可是我觉得我写的很正当啊?! 

5 3
1 2 2 3 6

5 3
1 3 2 2 6

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

机房好热 
15:30 T1 100
有点尿急，厕所坑位被抢了 心态--
T2 是绕口令吗，心态--，先去做 T3 
16:30 T3 10
16:50 T3 20
17:40 T4 [5,15]
*/
