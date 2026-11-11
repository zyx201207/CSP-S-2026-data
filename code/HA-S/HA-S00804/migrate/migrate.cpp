#include <bits/stdc++.h>
#define fi first
#define se second
#define pq priority_queue

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using db = double;
using pii = pair<int, int>;
//bool m1;
namespace FastIO {
	#ifdef __linux__
	#define gc getchar_unlocked
	#define pc putchar_unlocked
	#else
	#define gc getchar
	#define pc putchar
	#endif
	#define tp template<class T>
	#define tp2 template<class T1, class ...T2>
	inline void read() {}
	tp2 inline void read(T1 &x, T2 &...y) {
		x = 0; bool w = false; char ch = gc();
		for (; ch != EOF && !isdigit(ch); ch = gc()) if (ch == '-') w = true;
		for (; ch != EOF && isdigit(ch); ch = gc()) x = (x << 1) + (x << 3) + (ch ^ 48);
		if (w) x = -x;
		read(y...);
	}
	inline void readstr() {}
	tp2 inline void readstr(T1 *s, T2 *...str) {
		char ch = gc();
		for (; ch != EOF && ch <= ' '; ) ch = gc();
		for (; ch != EOF && ch > ' '; ch = gc()) *s++ = ch;
		*s = 0; readstr(str...);
	}
	inline void read_cstr() {}
	tp2 inline void read_cstr(T1 &s, T2 &...str) {
		s.clear(); char ch = gc();
		for (; ch != EOF && ch <= ' '; ) ch = gc();
		for (; ch != EOF && ch > ' '; ch = gc()) s.push_back(ch);
		read_cstr(str...);
	}
	inline void print() {}
	tp inline void print(T x) {
		bool w = x < 0; int tbuf = 0, buf[50];
		do { buf[++tbuf] = x % 10 < 0 ? -(x % 10) : x % 10; x /= 10; } while (x);
		if (w) pc('-');
		for (; tbuf; ) pc(buf[tbuf--] | 48);
	}
	inline void print_sp() {} tp2 inline void print_sp(const T1 &x, const T2 &...y) { print(x); pc(' '); print_sp(y...); }
	inline void print_ln() {} tp2 inline void print_ln(const T1 &x, const T2 &...y) { print(x); puts(""); print_ln(y...); }
	inline void print_list() {} tp2 inline void print_list(const T1 &x, const T2 &...y) { print_sp(x, y...); puts(""); }
	inline void printstr_ln() {} tp2 inline void printstr_ln(const T1 *s, const T2 *...str) { for (; *s; ) pc(*s++); puts(""); printstr_ln(str...); }
	inline void print_cstr_ln() {} tp2 inline void print_cstr_ln(const T1 &s, const T2 &...str) { for (const char &ch : s) pc(ch); puts(""); print_cstr_ln(str...); }
	#undef gc
	#undef pc
	#undef tp
	#undef tp2
} using namespace FastIO;
//namespace Debug {
//	db Tbegin, Tend;
//	#define M() cerr << (&m2 - &m1) / 1024 / 1024 << "MB " << (&m2 - &m1) / 1024 << "KB\n"
//	#define Tbegin() Tbegin = (db)clock()
//	#define Tend() Tend = (db)clock()
//	#define T() cerr << Tend - Tbegin << "ms " << (Tend - Tbegin) / CLOCKS_PER_SEC << "s\n"
//	#define de(x) cerr << #x << " = " << x << '\n' 
//} using namespace Debug;

constexpr int N = 1100, inf = 0x3f3f3f3f;
int c, test, n, ans;
int f[N][N];
ll d, x[N], cc[N][N];

//bool m2;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	read(c, test);
	for (; test--; ) {
		read(n, d); ans = 0; memset(f, inf, sizeof(f)); memset(cc, 0, sizeof(cc));
		for (int i = 1; i <= n; i++) read(x[i]);
		if (n >= 1000) { puts("0"); continue; }
		for (int i = 1; i <= n; i++) f[i][i] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i - 1; j && x[i] - x[j] <= d; j--) f[j][i] = 1, cc[j][i] = 1;
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++) if (i ^ j) {
					int x = f[i][k] + f[k][j];
					if (x < f[i][j]) { f[i][j] = x; cc[i][j] = cc[i][k] * cc[k][j]; }
					else if (x == f[i][j]) cc[i][j] += cc[i][k] * cc[k][j];
				}
		for (int i = 2; i <= n; i++) 
			for (int j = 1; j < i; j++) if (cc[j][i] == 2) ans++;
		print_ln(ans);
	}
	return 0;
}