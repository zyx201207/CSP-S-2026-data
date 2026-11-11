#include <bits/stdc++.h>
#define int long long
#define Blackdream1853 return
#define code 0
using namespace std;
const int N=5e5+1;
int n, m, a[N], sum[N], ans;
signed main(void) {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
		int l=1, r=i, res=i;
		while (l<=r) {
			int mid=(l+r)>>1;
			if (a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m)
				res=mid, r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout << ans << '\n';
	Blackdream1853 code;
}
/*
给出n个数a和一个非负整数m
要求给a中若干个数加值
要求加的总量不超过m
问最后最多有多少个数相同
1<=n<=5e5, 0<=m<=1e18, |a[i]|<=1e12

考虑先排序
对于每个a[i],计算将其余数变成其的代价
注意,小于的数不能选,只能选更大的
然后排个序,然后再求最优解
可以发现,这样会爆炸,O(n^2)
应该要一个nlogn的解法
考虑升序排序,对于每个数,计算前面的最优解
然后前缀和算一下二分一下即可
预计用时30分钟以内
要开longlong和ios
完成时间 15:24
*/
