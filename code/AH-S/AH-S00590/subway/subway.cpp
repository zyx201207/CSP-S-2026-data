#include <bits/stdc++.h>
using ll = long long;
//~ #define int long long
namespace IO {
	#define gc getchar_unlocked
	#define pc putchar_unlocked
	#define isdigit(ch) (ch >= '0' && ch <= '9')
	inline int read() {
		bool f = 0;
		char ch = gc();
		while (!isdigit(ch)) {
			if (ch == '-') f = 1;
			ch = gc();
		}
		
		int x = 0;
		while (isdigit(ch)) {
			x = (x << 1) + (x << 3) + (ch ^ 48);
			ch = gc();
		}
		
		if (f) return -x;
		return x;
	}
	inline void read(int &a) {a = read();}
	inline void read(int &a, int &b) {a = read(); b = read();}
	inline void read(int &a, int &b, int &c) {a = read(); b = read(); c = read();}
	
	void write(ll x) {
		if (x < 0) {
			pc('-');
			x = -x;
		}
		if (x > 9) write(x / 10);
		pc(x % 10 + 48);
	}
}

using namespace IO;
using namespace std;
const int N = 510, M = 5e5 + 10;

struct Rail{
	int x, t;
};

int c, n, m, d, q;
int w[M];
ll dis[N][N];
vector<int> bel[M]; 
unordered_map<int, ll> rail[N];

//~ void test() {
	//~ for (int i = 1; i <= n; i++) {
		//~ for (int j = 1; j <= n; j++) {
			//~ cout << dis[i][j] << ' ';
		//~ }
		//~ cout << '\n';
	//~ }
//~ }

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	//~ cerr << sizeof(int) << '\n';
	//~ cerr << sizeof(bel) / 1024 << '\n';
	read(c, n, m); read(d, q);
	for (int i = 1; i <= m; i++) {
		read(w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int k;
		read(k);
		while (k--) {
			int x, t;
			read(x, t);
			rail[i][x] = t;
			bel[x].push_back(i);
		}
	}
	
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < bel[i].size(); j++) {
			for (int k = 0; k < bel[i].size(); k++) {
				int u = bel[i][j], v = bel[i][k];
				dis[v][u] = dis[u][v] = min(dis[u][v], rail[u][i] + rail[v][i]);
			}
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	//~ test();
	
	int u, v;
	while (q--) {
		read(u, v);
		ll ans = 0x3f3f3f3f3f3f3f3f;
		for (int i = 0; i < bel[u].size(); i++) {
			for (int j = 0; j < bel[v].size(); j++) {
				int x = bel[u][i], y = bel[v][j];
				//~ int d = dis[x][y] + rail[x][u] + rail[y][v] + w[u] + w[v];
				//~ cout << i << ' ' << j << ' ' << x << ' ' << y << ' ' << d << '\n';
				ans = min(ans, dis[x][y] + rail[x][u] + rail[y][v] + w[u] + w[v]);
			}
		}
		write(ans); pc('\n');
	}
	
	//~ cerr << (sizeof(w) + sizeof(dis) + sizeof(bel) + sizeof(rail)) / 1024;
	return 0;
}
