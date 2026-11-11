#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
const int N = 2000100;
int n;
ll d, x[N], ans;
ll f[N], g[N], sum[N];
int dis[N], cnt[N];
void solveB(int l, int r) {
	for (int i = l; i + 1 < r; i++) {
		int c = upper_bound(x + l, x + r + 1, x[i] + d) - x - 1;
		int b = c - 1;
		int jr = upper_bound(x + l, x + r + 1, x[b] + d) - x - 1;
		jr = min(jr, r);
		int jl = upper_bound(x + l, x + r + 1, x[b - 1] + d) - x;
		jl = max(jl, c + 1);
		if (jl > jr) continue;
		ans += jr - jl + 1;
	}
}
void solve10(int l, int r) {
	for (int i = l; i <= r; i++) {
		int p = i;
		dis[i] = 0, cnt[i] = 1;
		for (int j = i + 1; j <= r; j++) {
			while (x[p] + d < x[j]) p++;
			dis[j] = dis[p] + 1, cnt[j] = cnt[p];
			if (p + 1 < j && dis[p + 1] == dis[p]) cnt[j] += cnt[p + 1];
			if (p + 2 < j && dis[p + 2] == dis[p]) cnt[j] += cnt[p + 2];
			cnt[j] = min(cnt[j], 3), ans += (cnt[j] == 2);
		}
	}
}
void solve3() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	int lst = 1;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] - x[i - 1] > d) solveB(lst, i - 1), lst = i;
	}
	solveB(lst, n);
	cout << ans << '\n';
}
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	int lst = 1;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] - x[i - 1] > d) solve10(lst, i - 1), lst = i;
	}
	solve10(lst, n);
	cout << ans << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, T;
	cin >> c >> T;
	while (T--) {
		if (c <= 10) solve();
		else solve3();
	}
	return 0;
}

/*
很难下手
答案=至多两条最短路点对-只有一条最短路点对
不好统计
考虑枚举左端点
右端点=区间合并，dis++
没前途
结构
哦对了
考虑f为i以前，到i有1条路径，到i+1走的路更长
g反过来
找到a,b,c,d满足那个结构，答案就是，(fc-1)*(gb-1)
如果间隔太远就拆一下
应该是对的吧
哦过小样例了，我无疑是兴奋的
哦大样例错了
0 1
6 12
-10 -6 -2 2 6 10
根本没有这样的结构
哦等一下
好像不需要那个结构
对吗，我想一下
先去看D
D 40pts got
定下 a 后，d对应一段区间
f,g如何去重，答案如何去重？
*/