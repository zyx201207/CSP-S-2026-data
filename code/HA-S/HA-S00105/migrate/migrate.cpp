#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5, M = 3005, inf = 1e18;
int C, T, n, d, a[N], sum[N], dp[N], lst[N], cnt[N], res, ans;
void solve(){
	cin >> n >> d;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	ans = 0;
	for (int i = 1; i <= n; ++i){
		int l = i;
		sum[i] = 1, sum[i - 1] = 0, dp[i] = 0, cnt[i] = 1;
		for (int j = i + 1; j <= n; ++j){
			while (a[j] - a[l] > d)++l;
			if (l == j){
				break;
			}
			dp[j] = dp[l] + 1;
			if (dp[j] > dp[j - 1]){
				lst[dp[j]] = j;
			}
			cnt[j] = sum[lst[dp[l] + 1] - 1] - sum[l - 1];
			sum[j] = sum[j - 1] + cnt[j];
			if (cnt[j] == 2){
				++ans;
			} 
		}
	}
	cout << ans << "\n";
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while (T--){
		solve();
	}
	return 0;
} 
/*
1 1
11 4
0 1 2 3 5 6 9 10 11 12 15
太困难。已放弃。

遗憾离场。

我常常追忆过去。

生命瞬间定格在脑海。我将背后的时间裁剪、折叠、蜷曲，揉捻成天上朵朵白云。

云朵之间亦有分别：积云厚重，而卷云飘渺。生命里震撼的场景掠过我的思绪便一生无法忘怀，而普通平常的记忆在时间的冲刷下只留下些许残骸。追忆宛如入梦，太过清晰则无法逾越我的幻想，过分模糊却又坠入虚无。只有薄雾间的山水，面纱下的女子，那恰到好处的朦胧，才能满足我对美的苛求。

没时间了，只能写到这了。

我该在哪里停留？我问我自己。 
*/ 
