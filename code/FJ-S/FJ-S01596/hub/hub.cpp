//hub
#include <cstdio>
#include <cstring>
using namespace std;

//#define DEBUG

#ifndef DEBUG
char buf[1 << 21], *p1 = buf, *p2 = buf, buf_[1 << 21], *pp = buf_;
#define gc() ((p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)) ? EOF : *p1++)
#define pc(c) (((pp - buf_ == (1 << 21)) ? (fwrite(buf_, 1, 1 << 21, stdout), pp = buf_) : pp), *pp++ = (c))
#define fl() (fwrite(buf_, 1, pp - buf_, stdout), pp = buf_, 0)
#else
#define gc() getchar()
#define pc(c) putchar(c)
#define fl() 0
#endif // DEBUG
template <typename T>
T read() {T x = 0; int f = 1; char c = gc(); while (c < '0' || c > '9') {if (c == '-') f = -1; else if (c == EOF) return 0; c = gc();} while (c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48); c = gc();} return x * f;}
template <typename T>
void write(T x) {if (x < 0) {pc('-'); x = -x;} if (x > 9) write(x / 10); pc('0' + x % 10);}
template <typename T>
void writeln(T x) {write(x); pc('\n');}
template <typename T>
void write(T x, char c) {write(x); pc(c);}
template <typename T>
T min_(T x, T y) {return x < y ? x : y;}
template <typename T>
T max_(T x, T y) {return x < y ? y : x;}

#define N 1000005
int _, n, k, hd[N], vl[N << 1], nx[N << 1], cnt_edge = 1;
void add_edge(int u, int v) {
	vl[++cnt_edge] = v;
	nx[cnt_edge] = hd[u];
	hd[u] = cnt_edge;
}
int S, T;
int fa[N], dep[N];
void init_ST(int u, int f) {
	fa[u] = f; dep[u] = dep[f] + 1;
	for (int i = hd[u]; i; i = nx[i]) {
		int v = vl[i];
		if (v == f) continue;
		init_ST(v, u);
	}
}
int res[N], cnt = 0;
bool vis[N];
int mxdis[N];
void init_dis(int u, int f) {
	mxdis[u] = 0;
	for (int i = hd[u]; i; i = nx[i]) {
		int v = vl[i];
		if (v == f || vis[v]) continue;
		init_dis(v, u);
		mxdis[u] = max_(mxdis[u], mxdis[v] + 1);
	}
}
int le[N], ri[N];
bool check(int X) {
	//pc('X'), pc(':'), writeln(X);
	int num = 0;
	if (X + 1 >= cnt - X) {
		return k >= 1;
	} num = (cnt - X) - (X + 1) + 1;
	for (int i = 1; i <= n; i++) if (!vis[i] && mxdis[i] >= X) num++;
	//writeln(num);
	int p = 1;
	for (int i = 1; i <= cnt; i++) {
		p = max_(p, i);
		while (p < cnt && mxdis[res[p + 1]] + (p + 1 - i) <= X) p++;
		ri[i] = p;
	} p = cnt;
	for (int i = cnt; i >= 1; i--) {
		p = min_(p, i);
		while (p > 1 && mxdis[res[p - 1]] + (i - p + 1) <= X) p--;
		le[i] = p;
	} int y = X + 1;
	//for (int i = 1; i <= cnt; i++) write(le[i], " \n"[i == cnt]);
	//for (int i = 1; i <= cnt; i++) write(ri[i], " \n"[i == cnt]);
	int nm = 0;
	for (int x = X + 1; x <= cnt - X; x++) {
		while (y < cnt - X && le[y + 1] - ri[x] <= 1) y++;
		nm = max_(nm, y - x - 1);
	} return num - nm <= k;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	read<int>(); _ = read<int>(); while (_--) {
		n = read<int>(); k = read<int>();
		memset(hd, 0, sizeof(int) * (n + 1)); cnt_edge = 1;
		for (int i = 1; i < n; i++) {
			int x, y; x = read<int>(); y = read<int>();
			add_edge(x, y); add_edge(y, x); 
		} S = T = 0; init_ST(1, 0);
		int mx = 0;
		for (int i = 1; i <= n; i++) if (mx < dep[i]) mx = dep[i], T = i;
		init_ST(T, 0); mx = 0;
		for (int i = 1; i <= n; i++) if (mx < dep[i]) mx = dep[i], S = i;
		cnt = 0;
		int u = S; memset(vis, false, sizeof(bool) * (n + 1));
		while (u) res[++cnt] = u, vis[u] = true, u = fa[u];
		//for (int i = 1; i <= cnt; i++) write(res[i], " \n"[i == cnt]);
		for (int i = 1; i <= cnt; i++) init_dis(res[i], 0);
		//for (int i = 1; i <= n; i++) write(mxdis[i], " \n"[i == n]);
		int L = 0, R = n;
		int mid, ans = -1;
		while (L <= R) {
			mid = (L + R) >> 1;
			if (check(mid)) ans = mid, R = mid - 1;
			else L = mid + 1;
		} writeln(ans);
	}
	
	return fl();
}
