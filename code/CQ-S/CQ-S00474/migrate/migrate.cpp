#include <bits/stdc++.h>
using namespace std;
const int S = 1 << 20;
char buf[S], *p1, *p2;
#define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, S, stdin), p1 == p2) ? EOF : *p1++)
template <typename T> inline void rd(T &x) {
	x = 0; char c = 0; bool f = 0;
	while (c < '0' || c > '9') f |= (c = gc) == '-';
	while (c >= '0' && c <= '9') x = x * 10 - '0' + c, c = gc;
	if (f) x = -x;
}
namespace WorldMachine {
	typedef long long ll;
	#define MP make_pair
	const int N = 2e6 + 5;
	int c, T, n, pre[N], nxt[N], l[N], r[N], c0[N], c1[N];
	ll d, a[N], ans;
	basic_string<int> G[N], vec[N];
	inline int qry(int l, int r, int x) {
		return upper_bound(vec[x].begin(), vec[x].end(), r) - lower_bound(vec[x].begin(), vec[x].end(), l);
	}
	void dfs(int u) {
		if (G[u].empty()) {
			c0[u] = 1, c1[u] = 0;
			return;
		}
		c0[u] = c1[u] = 0;
		for (int v : G[u]) {
			dfs(v);
			c0[u] += c0[v], c1[u] += c1[v];
		}
//		cerr << u << " : " << c0[u] << ' ' << c1[u] << '\n';
		// j == u
		for (int v : G[u]) {
			if (l[v] == r[v]) {
				ans += c1[v];
				continue;
			}
			for (int w : G[v]) {
//				if (l[v] == r[v]) ans += c1[w];
				if (l[v] == r[v] - 1) {
					if (w == 1 || a[v - 1] - a[w - 1] > d)
						ans += c0[w];
					else ans++;
				}
			}
		}
//		cerr << "qvq " << u << " : " << ans << '\n';
		// j == u + 1
		if (nxt[u] > u + 1) {
			if (pre[u + 1] == u) ans += c1[u];
			else if (pre[u + 1] == u - 1) {
				for (int v : G[u]) {
					if (v == 1 || a[u - 1] - a[v - 1] > d)
						ans += c0[v];
					else ans++;
				}
			}
		}
//		cerr << "pvp " << u << " : " << ans << '\n';
		// j >= u + 2
		if (nxt[u] > u + 2) {
			ll cnt1 = qry(u + 2, nxt[u] - 1, r[u]);
			ll cnt0 = qry(u + 2, nxt[u] - 1, r[u] - 1);
			ans += c1[u] * cnt1;
			for (int v : G[u]) {
				if (v == 1 || a[u - 1] - a[v - 1] > d)
					ans += c0[v] * cnt0;
				else ans += cnt0;
			}
		}
//		cerr << "TvT " << u << " : " << ans << '\n';
		// update
		if (l[u] == r[u] - 1) c1[u] = c0[u], c0[u] = 0;
		else if (l[u] < r[u] - 1) c0[u] = c1[u] = 0;
		c0[u]++;
//		cerr << "  " << u << " : " << c0[u] << ' ' << c1[u] << '\n';
		return;
	}
	void Solve(int n, ll a[]) {
		if (n < 3) return;
		pre[1] = 1;
		for (int i = 2; i <= n; i++) {
			pre[i] = pre[i - 1];
			while (a[i] - a[pre[i]] > d) pre[i]++;
		}
		nxt[n] = n;
		for (int i = n - 1; i; i--) {
			nxt[i] = nxt[i + 1];
			while (a[nxt[i]] - a[i] > d) nxt[i]--;
		}
		for (int i = 1; i <= n; i++)
			l[i] = pre[nxt[i]], r[i] = nxt[pre[i]];
//		for (int i = 1; i <= n; i++) cerr << pre[i] << ' ' << nxt[i] << ' ' << l[i] << ' ' << r[i] << '\n';
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i < n; i++) G[nxt[i]] += i;
		for (int i = 1; i <= n; i++) vec[i].clear();
		for (int i = 2; i <= n; i++) vec[pre[i]] += i;
		dfs(n);
	}
	void solve() {
		rd(n), rd(d), ans = 0;
		int l = 1;
		for (int i = 1; i <= n; i++) {
			rd(a[i]);
			if (i > 1 && a[i] - a[i - 1] > d)
				Solve(i - l, a + l - 1), l = i;
		}
		Solve(n - l + 1, a + l - 1);
		cout << ans << '\n';
	}
	void main() {
		rd(c), rd(T);
		while (T--) solve();
	}
	#undef int
	#undef MP
}
int main() {
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
//	ios::sync_with_stdio(0), cin.tie(0);
	return WorldMachine::main(), 0;
}
/*
首先把距离 > d 的作为分段点，每段分别来做
恰好 有两条最短路，这个限制很奇怪
首先最短路一定不会走回头路，那么什么时候会有多条最短路呢？
一个最简单的例子：四个点，相邻点距离为 1，一次只能跳 2 的距离
这时候从 1 跳到 4 就有两种方法：1 -> 2 -> 4 和 1 -> 3 -> 4
先考虑如何判断，一个想法是，先求出 i -> j 贪心跳的最短路，再求出 j -> i 贪心跳的最短路
再判断它们是否是“相邻”的？需要刻画什么叫“相邻”
好吧我们直接猜！(i, j) 是好的，当且仅当 i -> j 贪心跳的最短路上恰好存在一个 i < k < j，使得：
pre(k) < k-1 && dis(k-1, nxt(k)) <= d && (dis(k-2, nxt(k)) >= d || pre(k) == k-2)
感觉上是很对的？然后这个 nxt(k) 几乎是和 j 的选取无关的，除了 nxt(k) == j 的情况，但是 i 可能决定 pre(k)
但是落在 pre(k) 上的限制是比较松的，只需要考虑 pre(k) < k-2，pre(k) == k-2 和 pre(k) == k-1 的情况
是不是可以考虑按照 k 从左往右扫描线，同时维护每个起点 i 对应的 k？
对于那些 old_pre(k) 仍然能直达 k 的 i，无需更新；否则更新成 k-1 就好啦喵
似乎不用写数据结构，直接用队列维护就行！这样就能得到每个 i 的 pre(k) 的分布啦喵
然后考虑 nxt(k) 的限制，设 k 往右能一步跳到最远的点是 ori_nxt(k)
对于那些 j >= ori_nxt(k)，限制都是一样的；否则 nxt(k) = j
注意到 恰好 两个字还躺在限制里面啊喵，该怎么处理呢？
j 应该是有单调性的，我们现在站在 k，又该怎么确定最远能合法的 j 呢
换而言之，j 之前不能够有另外一个 k' 也能调整，否则违背了恰好两条的限制
我们只能知道 k 对于一个范围内的 j 是合法的，要么是棍木，要么是一段区间
能不能考虑在 k 这里撤回 之前的 k' 的多余贡献？
应该做复杂了，我们应该忽视了很多比较明显的单调性，比如说对 i 来说合法的 j 也是一段区间
设 L(i) 表示最小的到 i 至少有 2 条最短路的 j，R(i) 表示最小的至少有 3 条的 j，合法的就是 [L(i), R(i))
引入 3 就更烦了，难道还要我支持莫队状维护区间最短路条数？？
草啊怎么只剩 3h 了，我哭
这个时候，如果是 Gemini 的话会怎么做呢（误）
现在有两条路要选择，一个是延续之前以 k 为核心的计算，另一个是考虑维护别的一些诡异的东西
看起来像是绕道什么死胡同里面了，先看看 T4 换个脑子吧 qvq

我回来了，T4 读错题了可还行
先观察一下 pre(k) 的性质，不是这玩意真的有性质吗
干脆推翻重来吧要不……qvq
猜测一下，从 i 贪心跳到 j，再从 j 贪心跳回 i，如果恰好有一个位置不同且刚好相差 1 就合法？
感觉是不是挺对的，然后你 i 向 pre 和 nxt 连边这样得到两棵树
然后对于 i 到它的某个祖先 x，考虑 [x, nxt[x]) 这一段里面的 j
考虑 j 跳到它的祖先 y，满足 y >= i > pre[y]，这样的两条祖先链
这样可以得到一个 O(n^2) 的暴力，然后呢？
考虑 i 从大到小枚举，维护每个 j 对应的祖先链的路径
有一些 j 的路径会伸长，具体地说，恰好是 i 在 pre 树上子树内的那些点
那么 [x, nxt[x]) 在 pre 树上又对应什么？首先肯定有 pre[nxt[x]] = x ←这个是假的！
那么这在 pre 树上也对应一条边的跨越区间，有什么用？
呃我草我是不是弱智了，我好像把这个 pre 和上面的 pre 有点搞混了
对于一个 k，以它作为 pre 的点一定是一段区间吧？
对于一个 k，它能调整的余裕就是 [pre[nxt[k]], nxt[pre[k]]]
呜啊我真要吐了，我怎么这么弱智
不行不行不行，振作起来喵！qvq

那么 i -> j 合法的条件就是，i 跳到 j 的路径上，所有点的余裕（不含 i, j）之和恰好为 1？
这个充要吗？
没有退路了。
考虑如何维护，考虑 nxt 树上，i 的一条祖先链 i -> x，对于 [x, nxt[x]) 的这一段
j = x 容易判，j = x+1 需要特别处理？也不难判
然后 [x+2, nxt[x]) 就比较自由了，应该可以做？ 
不妨考虑换个角度，从 x 的角度看，就是选择 nxt 子树里面的 i
记录子树里面 i -> x 余裕和为 0 和 1 的 i 个数
注意不要把端点 i 算进去了……这个怎么搞？
哦这个挺好搞的其实。。

等下，还有一个问题！实际上当前 u 可调整到的左端点的余裕也是受到 j 制约的，而这个并不能简单地归结到 l[u] 上
真正要考虑的，其实应该是 pre[j]？能调整到的范围应该是 [pre[j], r[u]]
要做的其实是查询区间内某个数的出现次数……二分一下可以搞到 O(n log n)
这次会对吗？
没有退路了。

没过大样例 qvq

0 1
10 21
0 7 14 21 28 35 42 49 56 63

你发现这样算多了，我们没有考虑到可以通过调整 u 之前的跳跃得到更多方案的情况
也就是说不一定要调整 u。就算 u 只有 1 的余裕，也可以给前面的人用
日啊感觉假完了……
考虑能不能救，也就是说还要限定这个余裕是不能给 u 的儿子使用的
那就枚举 u 的儿子 v，换而言之枚举最后跳 nxt 的一步
对于 j，余裕必须要恰好能给 u 用，并且不能给 v 用
我发现这个东西似乎是可以判断的……

这次答案偏小了。
是因为算漏了 v -> u -> j？
又偏大了，j == u 也要这么搞？

我草了啊，这我怎么调啊
死了
*/
