//subway
#include <cstdio>
#include <vector>
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

#define N 505
#define M 500005
#define ll long long
int n, m, q, w[M];
struct node {
	int i, t;
	node () {}
	node (int i, int t): i(i), t(t) {}
};
vector<node> vc[M];
ll g[N][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	read<int>(); n = read<int>(); m = read<int>(); read<int>(); q = read<int>();
	for (int i = 1; i <= m; i++) w[i] = read<int>();
	for (int i = 1; i <= n; i++) {
		int k = read<int>();
		for (int j = 1; j <= k; j++) {
			int a, t; a = read<int>(); t = read<int>();
			vc[a].push_back(node(i, t));
		}
	} memset(g, 0x3f, sizeof(g));
	for (int i = 1; i <= n; i++) g[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < (int)vc[i].size(); j++) {
			for (int k = j + 1; k < (int)vc[i].size(); k++) {
				int x = vc[i][j].i, y = vc[i][k].i, z = vc[i][j].t + vc[i][k].t;
				g[x][y] = g[y][x] = min_(g[x][y], (ll)z);
			}
		}
	} for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min_(g[i][j], g[i][k] + g[k][j]);
			}
		}
	} while (q--) {
		int x, y; x = read<int>(); y = read<int>();
		ll ans = 0x3f3f3f3f3f3f3f3fLL;
		for (int i = 0; i < (int)vc[x].size(); i++) {
			for (int j = 0; j < (int)vc[y].size(); j++) {
				ans = min_(ans, vc[x][i].t + vc[y][j].t + g[vc[x][i].i][vc[y][j].i]);
			}
		} writeln(ans + w[x] + w[y]);
	}
	
	return fl();
}
