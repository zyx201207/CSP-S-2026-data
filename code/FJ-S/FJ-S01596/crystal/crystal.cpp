//crystal
#include <cstdio>
#include <algorithm>
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

#define N 500005
#define ll long long
int n; ll m, a[N], s[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read<int>(); m = read<ll>();
	for (int i = 1; i <= n; i++) a[i] = read<ll>();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int L = 0, R = i;
		int mid, res = -1;
		while (L <= R) {
			mid = (L + R) >> 1;
			if (mid * a[i] + s[i - mid] <= s[i] + m) res = mid, L = mid + 1;
			else R = mid - 1;
		} ans = max_(ans, res);
	} writeln(ans);
	
	return fl();
}
