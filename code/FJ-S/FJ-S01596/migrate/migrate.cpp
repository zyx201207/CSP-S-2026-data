//migrate
#include <cstdio>
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

#define N 2000005
#define ll long long
int _, n; ll d, xx[N];
int las[N], pre[N];
int num[N], num_[N];
int le[N], ri[N];
int le_[N], ri_[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	read<int>(); _ = read<int>(); while (_--) {
		n = read<int>(); d = read<ll>();
		for (int i = 1; i <= n; i++) xx[i] = read<ll>();
		for (int i = 1; i <= n; i++) le[i] = le_[i] = n + 1, ri[i] = ri_[i] = 0;
		int ps = 1;
		for (int i = 1; i <= n; i++) {
			while (ps < n && xx[ps + 1] - xx[i] <= d) ps++;
			las[i] = ps;// write(las[i], " \n"[i == n]);
			le[ps] = min_(le[ps], i); ri[ps] = max_(ri[ps], i);
		} ps = 1;
		for (int i = 1; i <= n; i++) {
			while (ps < i && xx[i] - xx[ps] > d) ps++;
			pre[i] = ps;// write(pre[i], " \n"[i == n]);
			le_[ps] = min_(le_[ps], i); ri_[ps] = max_(ri_[ps], i);
		} num[1] = 0;
		for (int i = 2; i <= n; i++) {
			num[i] = 0;
			if (las[pre[i]] == i) num[i] += num[pre[i]] + 1;
			int L = max_(pre[i] + 1, le[i]), R = min_(i - 1, ri[i]);
			if (L <= R) num[i] += R - L + 1;
		} num_[n] = 0;
		for (int i = n - 1; i >= 1; i--) {
			num_[i] = 0;
			if (pre[las[i]] == i) num_[i] += num_[las[i]] + 1;
			int L = max_(i + 1, le_[i]), R = min_(las[i] - 1, ri_[i]);
			if (L <= R) num_[i] += R - L + 1;
		} ll ans = 0;
		//for (int i = 1; i <= n; i++) write(num[i], " \n"[i == n]);
		//for (int i = 1; i <= n; i++) write(num_[i], " \n"[i == n]);
		for (int p = 1; p <= n; p++) {
			if (las[p] == p || las[las[p]] == las[p]) continue;
			int q = las[p], r = las[las[p]];
			if (pre[r] == q - 1 && pre[q - 1] == p && p < q - 1 && q < r) {
				ans += (ll)num[p] * num_[r];
				//write(p, ' '); writeln(r);
			}
		} for (int p = 1; p <= n; p++) {
			if (las[p] <= p + 1) continue;
			int q = las[p], q_ = las[p] - 1;
			if (pre[q_] != p) continue;
			int L = max_(q + 1, le_[q_]), R = min_(las[q], ri_[q_]);
			if (L <= R) ans += (ll)(R - L + 1) * num[p]/*, write(p, ' '), write(L, ','), writeln(R)*/;
		} for (int r = 1; r <= n; r++) {
			if (pre[r] >= r - 1) continue;
			int q_ = pre[r], q = pre[r] + 1;
			if (las[q] != r) continue;
			int L = max_(pre[q_], le[q]), R = min_(q_ - 1, ri[q]);
			if (L <= R) ans += (ll)(R - L + 1) * num_[r]/*, write(L, ','), write(R, ' '), writeln(r)*/;
		} for (int q = 2; q <= n; q++) {
			int L = max_(pre[q - 1], le[q]), R = min_(q - 2, ri[q]);
			int L_ = max_(q + 1, le_[q - 1]), R_ = min_(las[q], ri_[q - 1]);
			if (L <= R && L_ <= R_) ans += (ll)(R - L + 1) * (R_ - L_ + 1)/*, write(L, ','), write(R, ' '), write(L_, ','), writeln(R_)*/;
		} writeln(ans);
	}
	
	return fl();
}
