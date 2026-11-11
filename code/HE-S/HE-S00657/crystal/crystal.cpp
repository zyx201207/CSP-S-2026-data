#include <bits/stdc++.h>
using std::cin; using std::cout;

#define LL long long

const int N = 5e5 + 10;

int n, m;
LL a[N];
LL dif[N], sum[N], sum2[N];
LL ans = 0;

int main()
{
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) dif[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; ++ i) sum[i] = sum[i - 1] + dif[i];
	for (int i = 1; i <= n; ++ i) sum2[i] = sum2[i - 1] + sum[i];
	for (int i = 1; i <= n; ++ i) {
		LL L = 1, R = i;
		LL done = i;
		while (L <= R) {
			LL mid = (L + R) >> 1; 
			LL pol = 1LL * (i - mid) * sum[i] - (sum2[i - 1] - sum2[mid - 1]);
			if (pol <= m) {
				done = mid; R = mid - 1;
			} else L = mid + 1;
		}
		ans = std::max(ans, (i - done + 1));
	}
	
	cout << ans << '\n';
	
	
	return 0;
}

/*

坐标 HE 高二了  马上就退役了

在正赛上倒开的感觉就是爽 

１５：５０刚刚把 T1 大样例调出来  上厕所呼吸新鲜空气 

17 : 30　刚刚把　Ｔ４　纯按题意模拟代码打出来 

17 : 50 写了一个第一题的对拍  真的燃尽了啊？！ 上厕所呼吸新鲜空气2.0 

18 : 10 T3 暴力调不出来了 就这样吧 结束了 

no time

我是不是要 完吉儿吧蛋 了
最后一舞了

ｌｕｏｇｕ＿ｉｄ：ｌｉｑｕｅ００  一个 只有绿勾 的 蒟蒻 

我要进 HE 迷惑行为 ！！！  

*/
