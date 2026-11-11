#include <bits/stdc++.h>
using namespace std;
struct fis {
	unsigned pos = 1 << 20;
	char c, buf[1 << 20];
	char &getc() {
		if (pos == (1 << 20)) {
			fread(buf, 1, 1 << 20, stdin);
			pos = 0;
		}
		return c = buf[pos++];
	}
	template<typename T>
	fis &operator>>(T &x) {
		while ((getc() < '0' || c > '9') && c != '-') {}
		bool f = c == '-';
		if (c != '-') x = '0' ^ c;
		else x = 0;
		while (getc() >= '0' && c <= '9') {
			x = (x << 1) + (x << 3) + ('0' ^ c);
		}
		if (f) x = -x;
		// cout << "\t\tread " << x << endl;
		return *this;
	}
} ewin;
#define cin ewin
struct fos {
	unsigned pos;
	char buf[1 << 20];
	void flush() {
		fwrite(buf, 1, pos, stdout);
		pos = 0;
	}
	void putc(char x) {
		if (pos == (1 << 20)) {
			flush();
		}
		buf[pos++] = x;
	}
	template<typename T>
	fos &operator<<(T x) {
		if (x > 9) {
			*this << x / 10;
		}
		putc('0' ^ (x % 10));
		return *this;
	}
} ewout;
// #define cout ewout
#define int long long
#define MAXN 2000005
int T, n, d, a[MAXN], l_reach[MAXN], r_reach[MAXN], l_expand[MAXN], r_expand[MAXN];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	cin >> T >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			// cout << "a[" << i << "] = " << a[i] << endl;
		}
		a[0] = -3000000000000000001ll;
		a[n + 1] = 3000000000000000001ll;
		int j = 1;
		for (int i = 1; i <= n; i++) {
			while (a[i] - a[j] > d) {
				// cout << __LINE__ << ' ' << i << ' ' << j << endl;
				j++;
			}
			l_reach[i] = j;
		}
		j = n;
		for (int i = n; i >= 1; i--) {
			while (a[j] - a[i] > d) {
				// cout << __LINE__ << ' ' << i << ' ' << j << endl;
				j--;
			}
			r_reach[i] = j;
		}
		for (int i = 1; i <= n; i++) {
			bool flag = 0;
			if (l_reach[i] != i && r_reach[l_reach[i]] == i) {
				// cout << "match " << i << ' ' << l_reach[i] << endl;
				l_expand[i] = l_expand[l_reach[i]] + 1;
				flag = 1;
			} else {
				l_expand[i] = 1;
			}
			l_expand[i] += max<int>(0, l_reach[i + 1] - l_reach[i] - flag);
		}
		for (int i = n; i >= 1; i--) {
			bool flag = 0;
			if (r_reach[i] != i && l_reach[r_reach[i]] == i) {
				// cout << "match " << i << ' ' << r_reach[i] << endl;
				r_expand[i] = r_expand[r_reach[i]] + 1;
				flag = 1;
			} else {
				r_expand[i] = 1;
			}
			r_expand[i] += max<int>(0, r_reach[i] - r_reach[i - 1] - flag);
		}
		// for (int i = 1; i <= n; i++) {
			// cout << i << ' ' << l_reach[i] << ' ' << r_reach[i] << ' ' << l_expand[i] << ' ' << r_expand[i] << endl;
		// }
		int ans = 0;
		for (int i = 2; i + 1 < n; i++) {
			if (a[i + 1] - a[i] >= d) continue;
			// 如果往左或右够到的点不一样，u 和 v 是直接的左侧或右侧点也可以。
			if (l_reach[i + 1] == i || r_reach[i] == i + 1) continue;
			// cout << "solve " << i << ":\n";
			int lcnt = 0, rcnt = 0;
			bool flag = 0;
			if (r_reach[l_reach[i]] == i + 1) {
				lcnt += l_expand[l_reach[i]];
				flag = 1;
				// cout << "type 1 lcnt += " << l_expand[l_reach[i]] << endl;
			}
			// >l_reach[i] 也能不到 i+2 的
			lcnt += max<int>(0, l_reach[i + 2] - l_reach[i + 1] - flag);
			// cout << "type 2 lcnt += " << max<int>(0, l_reach[i + 2] - l_reach[i + 1] - flag) << endl;
			flag = 0;
			if (l_reach[r_reach[i + 1]] == i) {
				rcnt += r_expand[r_reach[i + 1]];
				flag = 1;
				// cout << "type 3 rcnt += " << r_expand[r_reach[i + 1]] << endl;
			}
			rcnt += max<int>(0, r_reach[i] - r_reach[i - 1] - flag);
			// cout << "type 4 rcnt += " << max<int>(0, r_reach[i] - r_reach[i - 1] - flag) << endl;
			ans += lcnt * rcnt;
			/*
			int ll = l_reach[i + 1], rr = r_reach[i];
			cout << "solve " << i << "   " << ll << ' ' << rr << endl;
			if (ll == i || rr == i + 1) continue;
			if (r_reach[ll] != i + 1 || l_reach[rr] != i) continue;
			ans += l_expand[ll] * r_expand[rr];
			*/
		}
		ewout << ans;
		ewout.putc('\n');
	}
	ewout.flush();
	return 0;
}

/*

8min 写 A 过 A。
20min 写 B 被卡常。
10min 写满级快读。
10min 思考 C。
30min 思考 D。

C:
声称只有左右贪心前后缀重合而且中间只有一个不一样的单步点相邻才行。
枚举中间那个相邻的。i i+1
要求 i+1 最右侧能够到的 i 也能够到，而且 i 左侧同理。
从左右够到的两个点开始继续向两侧拓展。
如果 i 右侧够 j 而且 j 左侧够 i 就建立一个“可扩展”关系。
然后知道两侧可扩展的方案数即可。

D:
k 非常烦人，如果 k 比较小可以二分+DP，不过还得维护子树内的最高的 1。
考虑从连通块入手。肯定是有一条边分开，两侧各有一个连通块管。
如果能解决一个连通块，还能换根就解决了。
定根是好解决的。
但是到连通块中选连通块就不好解决了。解决了这个还得换根。
如果把换根加载前面？
如果用点分治？用点分治可以快速处理一个连通块，但是不好推广，而且复杂度有点高。
感觉二分不能少了，所以就得把后面的 DP 大力干下线性。
找到直径中点，如果两个连通块都在一侧，不如给中点点一下。
所以中点要不然就点了，要不然两个连通块在两个子树内。
在两个子树内肯定是两个直径子树，
或者考虑剥叶子？
单个连通块剥叶子似乎是正确的。
考虑推广。也就是随时可以选择一条边切开分别剥叶子。
如果只有一个连通块，好实现。而且也碰直径。
否则可以证明两个连通块都碰直径。二分。随便拉出一条直径，然后两侧分别树形 DP，之后找出每个端点如果不在某一侧，需要的左侧最左和右侧最右，这至少需要满足一个，之后双指针即可？

*/
