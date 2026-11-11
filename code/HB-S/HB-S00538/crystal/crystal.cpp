/*
[00:02]题目已经解压了，看了一眼第一题感觉题面好短，不知道难度怎么样。

[00:04]差点忘记输入输出同步流怎么关了，还是vscode自动补全救了一命……

[00:08]第一遍毫无头绪……再看看吧。

[00:12~00:21]合并不会影响水晶的能量值……可以考虑二分答案？
对于一个标准std属于a[i]，所能合并的水晶数即为所有a[i]<=std的个数
说std是合法的，当且仅当对于所有a[i]<=std满足sum(std-a[i])<=m
可以先预处理前缀和sum[i]，然后从i=1~n枚举
计算diff=i*a[i]-sum[i]
diff<=m即成立
O(n)，似乎不需要优化，先试试。

[00:24]差点忘了排序……这样的话就是O(nlogn)了，也还行。

[00:29]貌似发现处理前缀和时能顺带把答案算出来？还有差点忘记开long long……
n*max(a[i]) <= 5*10^5 * 10^12 = 5*10^17 正好！

[01:02]一个小时了？！发现思路有点不对……不一定要取最小一直到某一个std，可以是l~r，也可以是中断的……不过可以证明连续相较中断更优，所以从原来的考虑[1,i]到[l,r]就行
（这种方法何尝不是一种部分分）

[01:10～01：18]为了方便，每次考虑(l, r]，要使得满足条件的(l, r]中r-l差值最小
滑动窗口！！！！
等我回顾一下（辛亏复习了）
窗口状态满足两条性质：
1.若(left, right)不满足状态，则(left, right+1..end)也不满足状态 l++
2.若(left, right)满足状态，则(left+1..right, right)也满足状态  r++
这个问题满足性质吗？
1.若(l, r)的当前diff0>m，则(l, r+i)的diff>=diff0>m，即也不满足状态 l++
2.若(l, r)的当前diff0<=m，则(l+i, r)的diff<=diff0<=m，即也满足状态 r++
很好，那么这应该就是正解了

[01:27]大样例过了，开心^^  100pts应该有了，再检查一下while循环条件，01:35就读第二题
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
long long m;
long long a[N], s[N], diff;
// long long b[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i-1] + a[i];
	}
	int l=0, r=1, ans=0;  // (l, r]
	while (l < r && r <= n) {
		diff = (r-l)*a[r]-s[r]+s[l];
		if (diff <= m) {
			ans = max(ans, r-l);
			r++;
		} else {
			l++;
		}
	}
	cout << ans;
	// diff = i*a[i]-s;
	// 	printf("[%lld] %lld %lld %lld %lld\n", i, a[i], s, diff, m);
	// 	if (diff > m) {
	// 		cout << i-1;
	// 		return 0;
	// 	}
	// cout << n;
	return 0;
}
