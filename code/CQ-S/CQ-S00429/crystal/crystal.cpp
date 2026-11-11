#include <bits/stdc++.h>
#define int long long
#define pii std::pair< int, int >
const int N = 5e5 + 5;
int n, m, a[N], sum[N];
signed main() {
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i - 1, A = i;
		while (l <= r) {
			int mi = (l + r) >> 1;
			if ((i - mi) * a[i] - (sum[i - 1] - sum[mi - 1]) <= m) 
				A = mi, r = mi - 1;
			else l = mi + 1;
		}
		ans = std::max(ans, i - A + 1);
	}
	std::cout << ans << "\n";
	return 0;
}
/*
去年上了迷惑行为大赏，今年才不要上呢 
洛谷关注 uid 731704 谢谢喵！
抖音关注小儿娃谢谢喵！
哦对了还有 ljx dyt 99 喵！ 
*/
/*
显然最后所有水晶都会调整到一个高度，且调整的水晶在排序后是一段区间。
那么考虑对于所有的 r 都二分一个 l 使得 [l, r] 的所有水晶都调整到 r 的代价不多于 m。
求 r - l + 1 的最大值即可。 

总分 271，估计应该可以进 NOIP（  
*/
