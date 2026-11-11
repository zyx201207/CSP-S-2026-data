/*
9:12 开始写 T4，能 AK 吗？

发现可以倒着处理，要维护上一个相同数字 pre，离当前点最近的后面的数字 

这样子是 O(m^2) 有 71pts。

这好像可以优化，先写完暴力再说 

啊啊啊啊啊啊啊啊啊啊啊啊啊啊，我做法假了

考虑倒序模拟，发现可以继承很多信息

但是有拿牌，会有信息撤回，这可以用神秘的 1010101010101 这样的东西卡满

我好像想到正解了。

发现在 last[a[i]] 回合对答案的贡献和在第 i 回合一样，本质不同的贡献只有 m 种

好像还能优化，先写着 

本质不同的贡献其实也可以继承，这样是 O(n) 的。

能 AC 吗？ 大样例过了！！！！！！！！！！！！！！！！！！ 

AK 成功了……吗？ 
*/
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m, a[N], pre[N], t[M];
int last[N], w[N], to[N], ans[M];

signed main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m; // fc card.out card.ans 
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = t[a[i]];
		t[a[i]] = i;	
	} 
	for(int i = n; i >= 1; i--) {
		w[i] = 1;
		if(last[a[i]]) to[i] = last[a[i]];
		else to[i] = i + 1;
		last[a[i]] = i;
	} 
	for(int i = 1; i <= n; i++) {
		if(t[a[i]] == i) ans[a[i]] += w[i];
		w[to[i]] += w[i];
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
} 
/*
我第二次考 csp，上一次，我拿到 0pts 之上最低分 30pts（我都不知道我怎么做到的），这一世，我要夺回我的一切（

我蚌埠住了 
*/
