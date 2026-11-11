#include <bits/stdc++.h>
#define int long long

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
	
	void write(int x) {
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
const int N = 2e6 + 10, INF = 4e18;

int a[N], n, d;

namespace Sub1{
	void solve() {
		vector<vector<int> > dis(n + 1, vector<int>(n + 1, INF));
		vector<vector<int> > cnt(n + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= n; i++) dis[i][i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] <= d) dis[i][j] = dis[j][i] = 1;
			}
		}
		
		//~ for (int i = 1; i <= n; i++) {
			//~ for (int j = i + 1; j <= n; j++) {
				//~ cout << dis[i][j] << ' ';
				//~ ans += (cnt[i][j] == 2);
			//~ }
			//~ pc('\n');
			//~ puts("");
		//~ }
		
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i == j || j == k) continue;
					int d = dis[i][k] + dis[k][j];
					if (d == dis[i][j]) {
						//~ cerr << i << ' ' << j << ' ' << k << '\n';
						cnt[i][j]++;
					} else if (d < dis[i][j]) {
						cnt[i][j] = 1;
						dis[i][j] = d;
					}
				}
			}
		}
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				//~ cout << dis[i][j] << ' ' << cnt[i][j] << ' ';
				ans += (cnt[i][j] == 2);
			}
			//~ pc('\n');
			//~ puts("");
		}
		write(ans); pc('\n');
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int Case, T;
	read(Case, T);
	while (T--) {
		read(n, d);
		//~ cerr << n << ' ' << d << '\n';
		for (int i = 1; i <= n; i++) {
			read(a[i]);
		}
		//~ a[n + 1] = a[n + 2] = INF;
		Sub1::solve();
	}
	return 0;
}
