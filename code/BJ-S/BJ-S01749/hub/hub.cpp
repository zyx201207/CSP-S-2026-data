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
		while (getc() < '0' || c > '9') {}
		x = '0' ^ c;
		while (getc() >= '0' && c <= '9') {
			x = (x << 1) + (x << 3) + ('0' ^ c);
		}
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

#define MAXN 1000005
int T, n, K, dep[MAXN], fa[MAXN], dp[MAXN], high[MAXN], k;
int dpl[MAXN], dpr[MAXN], mink2[MAXN];
vector<int> e[MAXN];
bool block[MAXN];
void dfsl(int u, int fa) { // 求直径，处理 dep fa
	dep[u] = dep[fa] + 1;
	::fa[u] = fa;
	for (int v : e[u]) {
		if (v != fa) {
			dfsl(v, u);
		}
	}
}
void dfsh(int u, int fa, int dep, int &st) { // 最深节点
	// cout << "dfsh " << u << ' ' << fa << ' ' << dep << ' ' << st << endl;
	st = max(st, dep);
	for (int v : e[u]) {
		if (v == fa || block[v]) {
			continue;
		}
		dfsh(v, u, dep + 1, st);
	}
}
int dfsdp(int u, int fa) { // 返回高度，处理 dp
	int h = 0;
	dp[u] = 0;
	for (int v : e[u]) {
		if (v != fa) {
			h = max(h, dfsdp(v, u) + 1);
			dp[u] += dp[v];
		}
	}
	if (h >= k) dp[u]++;
	return h;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	cin >> T >> T;
	while (T--) {
		cin >> n >> K;
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfsl(1, 0);
		int zbgn, zed;
		dfsl(zbgn = max_element(dep + 1, dep + n + 1) - dep, 0);
		zed = max_element(dep + 1, dep + n + 1) - dep;
		vector<int> z;
		for (int i = zed; i; i = fa[i]) {
			z.push_back(i);
			block[i] = 1;
		}
		reverse(z.begin(), z.end());
		int zlen = z.size();
		z.insert(z.begin(), 0);
		z.push_back(0);
		// cout << "直径：";
		for (int i : z) {
			// cout << i << ' ';
			high[i] = 0;
			dfsh(i, 0, 0, high[i]);
		}
		// cout << endl;
		// for (int i : z) {
			// cout << "high[" << i << "] = " << high[i] << endl;
		// }
		int L = 0, R = zlen - 1;
		while (L < R) {
			int mid = (L + R) >> 1;
			// cout << "check " << mid << ":\n";
			k = mid;
			dfsdp(zbgn, 0);
			for (int i = 1; i <= zlen; i++) {
				dpr[i] = max(dp[z[i]], 1);
			}
			dfsdp(zed, 0);
			for (int i = 1; i <= zlen; i++) {
				dpl[i] = max(dp[z[i]], 1);
			}
			int mincost = n;
			mincost = min(mincost, dpr[k + 1]);
			mincost = min(mincost, dpl[zlen - k]);
			// 每个限制形如 lid >= k1 || rid <= k2
			// 处理好所有限制，然后给限制关于 lid 存储下来，求 k1>lid 时的最小 k2。然后就做完了？
			for (int i = 1; i <= zlen; i++) {
				mink2[i] = zlen;
			}
			for (int i = 1; i <= zlen; i++) {
				int k1, k2;
				if (high[z[i]] >= k) {
					k1 = i;
					k2 = i;
				} else {
					k1 = i - (k - high[z[i]]);
					k2 = i + (k - high[z[i]]);
				}
				k1 = max(k1, 1);
				k2 = min(k2, zlen);
				// cout << "high[" << z[i] << "] = " << high[z[i]] << endl;
				// cout << i << " 给出的限制 ：k1=" << k1 << " k2=" << k2 << endl;
				mink2[k1 - 1] = min(mink2[k1 - 1], k2);
			}
			for (int i = zlen - 1; i >= 1; i--) {
				mink2[i] = min(mink2[i], mink2[i + 1]);
			}
			for (int i = 1; i <= zlen; i++) {
				mincost = min(mincost, dpl[i] + dpr[mink2[i]]);
				// cout << dpl[i] << ',' << dpr[i] << ' ';
			}
			// cout << endl;
			for (int i = 1; i <= zlen; i++) {
				mincost = min(mincost, dpl[i] + dpr[mink2[i]]);
				// cout << i << '~' << mink2[i] << ' ';
			}
			// cout << endl;
			// cout << "mincost = " << mincost << endl;
			if (mincost <= K) {
				R = mid;
			} else {
				L = mid + 1;
			}
		}
		ewout << L;
		ewout.putc('\n');
		for (int i = 1; i <= n; i++) {
			e[i].clear();
			block[i] = 0;
		}
	}
	ewout.flush();
	return 0;
}

/*

找一个随便的直径，记录下来。
记录每个点深下去的最远的点的距离。
二分答案。
分别从两个直径端点开始树形 DP。然后放在链上。链左右补滚木哨兵。
双指针。

好像不用滚木哨兵

*/








/*

8min 写 A 过 A。
20min 写 B 被卡常。
10min 写满级快读。
10min 思考 C。
30min 思考 D。
80min 写 C 拍调。
50min 写 D 调完。

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










C force

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 2000005
int T, n, d, a[MAXN], l_reach[MAXN], r_reach[MAXN], l_expand[MAXN], r_expand[MAXN];
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.ans", "w", stdout);
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
		int ans = 0;
		for (int u = 1; u <= n; u++) {
			for (int v = u + 1; v <= n; v++) {
				if (0) {
					IMP:
					continue;
				}
				vector<int> g1{u}, g2{v};
				int lst = u;
				// cout << u << ' ' << v << " :\n";
				for (int i = u + 1; i <= v; i++) {
					// cout << i << ' ' << lst << ' ' << a[i + 1] - a[lst] << ' ' << d << endl;
					if (i == v || a[i + 1] - a[lst] > d) {
						// cout << lst << " must => " << i << endl;
						lst = i;
						g1.push_back(i);
					}
					if (a[i] - a[i - 1] > d) {
						goto IMP;
					}
				}
				lst = v;
				for (int i = v - 1; i >= u; i--) {
					// cout << i << ' ' << lst << ' ' << a[lst] - a[i - 1] << ' ' << d << endl;
					if (i == u || a[lst] - a[i - 1] > d) {
						// cout << lst << " must => " << i << endl;
						lst = i;
						g2.push_back(i);
					}
				}
				reverse(g2.begin(), g2.end());
				assert(g1.size() == g2.size());
				int diff = 0;
				for (int i = 0; i < g1.size(); i++) {
					assert(g1[i] >= g2[i]);
					diff += g1[i] - g2[i];
					// cout << g1[i] << ' ' << g2[i] << endl;
				}
				if (diff == 1) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}



C gen


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 2000005
int T, n, d, a[MAXN], l_reach[MAXN], r_reach[MAXN], l_expand[MAXN], r_expand[MAXN];
signed main() {
	freopen("migrate.in", "w", stdout);
	// freopen("migrate.ans", "w", stdout);
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	int T = 1000;
	cout << "0 " << T << endl;
	srand(time(0) ^ clock());
	while (T--) {
	int n = rand() % 15 + 1, d = rand() % 8;
	cout << n << ' ' << d << endl;
	set<int> st;
	while (st.size() < n) {
		st.insert(rand() % 50 + 1);
	}
	for (int i : st) {
		cout << i << ' ';
	}
	cout << endl;
	}
	return 0;
}



C pai

#include <bits/stdc++.h>
using namespace std;
signed main() {
	int T = 0;
	while (1) {
		cout << ++T << endl;
		system("./gen");
		system("./migrate_force");
		system("./migrate");
		if (system("diff migrate.out migrate.ans")) return 1;
	}
	return 0;
}


judge

#include <bits/stdc++.h>
using namespace std;
int main() {
	string name = "hub";
	int num = 5;
	system(("g++ " + name + ".cpp -o " + name + " -std=c++14 -O2 -static -Wall").c_str());
	for (int i = 1; i <= num; i++) {
		system(("cp " + name + to_string(i) + ".in " + name + ".in").c_str());
		system(("time ./" + name).c_str());
		if (system(("diff " + name + ".out " + name + to_string(i) + ".ans").c_str())) {
			return 1;
		}
		system(("cat " + name + ".out").c_str());
		system(("cat " + name + to_string(i) + ".ans").c_str());
	}
	return 0;
}



*/
