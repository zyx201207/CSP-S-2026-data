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
	inline void print() {}
	tp inline void print(T x) {
		bool w = x < 0; int tbuf = 0, buf[50];
		do { buf[++tbuf] = x % 10 < 0 ? -(x % 10) : x % 10; x /= 10; } while (x);
		if (w) pc('-');
		for (; tbuf; ) pc(buf[tbuf--] | 48);
	}
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
constexpr int N = 510, M = 500010;
constexpr ll Inf = 1LL << 60;
int c, n, m, d, Q;
int w[M];
ll f[N][N];
vector<pii> bel[M];

//bool m2;

inline ll Query(int x, int y) {
	ll res = Inf;
	for (const pii &j : bel[x])
		for (const pii &k : bel[y]) res = min(res, f[j.first][k.first] + j.second + k.second);
	return res;
}

int main() {
//	Tbegin();
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(c, n, m, d, Q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) f[i][j] = Inf;
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int i = 1; i <= m; i++) read(w[i]);
	for (int i = 1; i <= n; i++) {
		int k; read(k);
		for (; k--; ) {
			int idx, t; read(idx, t);
			for (const pii &j : bel[idx]) f[j.first][i] = f[i][j.first] = min(f[j.first][i], 0LL + j.second + t);
			bel[idx].push_back({i, t});
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) if (i ^ j) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for (; Q--; ) {
		int u, v; read(u, v);
		print(Query(u, v) + w[u] + w[v]), puts("");
	}
//	Tend(); T();
	return 0;
}