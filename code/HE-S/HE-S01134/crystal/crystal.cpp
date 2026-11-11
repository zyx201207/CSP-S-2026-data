// T1 crystal
// time: /usr/bin/time -v ./task
// long long. memory. 
// memory ALL 1G 
// 双指针 two pointer 
// 应该 不出意外 是正解吧...
// T1 done. 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 5e5 + 5;
LL n, m, a[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (LL i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	sort (a + 1, a + 1 + n, less<LL>()); // O n log2 n 
	LL l = 1, r = 1; // 1 1不用算。就是n==1  也会被卡掉。 
	LL ans = 1, cost = 0; // cost 表示当前l, r的损耗是多少（超了也有） 
	// n 真的能等于1... 
	while (l <= r) {
		if (r > n || l > n) break;
		// l == r时差恒为0.m最小0 没有关系 肯定成立 所以l 恒<= r 
		// a有负数。
		// 判断就是 如果l或者r超边界（一般只有r超）那么宣布结束 因为没法下去了 没有更小的
		// 从1 开始。就是看：当前损耗cost 
		// 判断现在行不行。不行：l++, 行：r++ 扔给下一个。计算好cost
		// 对 因为先判断这个区间是否结束 结束也扔给下一个
		// a[r-1]变为a[r] ，损耗(r-l)*(a[r]-a[r-1]) cost += this. cost <= m. >m: l++,upd(cost) <=m: ans upd, r++. 
		if (cost <= m) { // 当前方案可以走 
			ans = max(r - l + 1, ans); // 更新 
			r++;
			cost += (r - l) * (a[r] - a[r-1]); // 更新r+1的cost。 如果r过了n怎么办 不是会算新的cost吗：没关系 反正不用 
		}
		else if (cost > m) { // 当前方案不行  
			cost -= (a[r] - a[l]); // 那么：去掉最前面那个 维护状态 对 
			l++;
		}
	}
	cout << ans << "\n";
	return 0;
}
