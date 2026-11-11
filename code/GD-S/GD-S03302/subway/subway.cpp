#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 500 + 10;
constexpr int M = 5e5 + 10;
constexpr int iinf = 1e9;
constexpr ll linf = 2e18;

namespace fast_io {
	struct reader {
		template <typename T> reader &operator>> (T &x) {
			static int f;
			static char ch;
			x = 0;
			f = 1;
			ch = getchar();
			while (!isdigit(ch)) {
				if (ch == '-')
					f = -1;
				ch = getchar();
			}
			while (isdigit(ch)) {
				x = x * 10 + ch - '0';
				ch = getchar();
			}
			x *= f;
			return *this;
		}
	} cin;
	struct writer {
		static const int SIZE = 60;
		template <typename T> writer &operator<< (T x) {
			static char str[60];
			static int cnt;
			
			if (x == 0) {
				putchar('0');
				return *this;
			}
			if (x < 0) {
				x = -x;
				putchar('-');
			}
			
			cnt = 0;
			while (x) {
				str[cnt++] = x % 10 + '0';
				x /= 10;
			}
			while (cnt) {
				putchar(str[--cnt]);
			}
			return *this;
		}
		writer &operator<< (char ch) {
			putchar(ch);
			return *this;
		}
	} cout;
	const char endl = '\n';
}

#define cin fast_io::cin
#define cout fast_io::cout
#define endl fast_io::endl

// n: 地铁线路数
// m: 地铁站数
// d: 每个地铁站最多被几条线路经过
// q: 出行计划数
int n, m, d, q;
int w[M];
//int k[N];

vector<pii> vc[M];// 站去线 
ll dis[N][N];

void ini() {
	for (int i = 1; i <= n; i++) {
		fill(dis[i]+1, dis[i]+n+1, linf);
		dis[i][i] = 0;
	}
	
	int u, v;
	for (int i = 1; i <= m; i++) {
//		for (int j = 0; j < sz; j++) {
//			for (int k = j + 1; k < sz; k++) {
		for (pii j: vc[i]) {
			for (pii k: vc[i]) {
				if ((u = j.second) == (v = k.second))
					continue;
				dis[u][v] = min<ll>(dis[u][v], j.first + k.first);
			}
		}
	}
	
	// 翻转dis 
//	for (int i = 1; i <= n; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			dis[j][i] = dis[i][j];
//		}
//	}
	
//	cerr <<"dis: \n";
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cerr << dis[i][j] <<' ';
//		}
//		cerr <<'\n';
//	}
	
	// floyd
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (k == j) continue;
				dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	int tm, to, len;
	for (int i = 1; i <= n; i++) {
		cin >> len;
		for (int j = 1; j <= len; j++) {
			// {first, second} = {time, to}
			cin >> to >> tm;
			vc[to].push_back({tm, i});
		}
	}
	
	ini();
	
	int u, v;
	for (int i = 1; i <= q; i++) {
		cin >> u >> v;
		
		ll ans = linf;
		for (pii j: vc[u]) {
			for (pii k: vc[v]) {
//				(u = j.second)
//				(v = k.second)
				ans = min(ans, j.first + k.first + dis[j.second][k.second]);
//				cerr << j.first <<' '<< k.first <<' '<< dis[j.second][k.second] <<'\n';
			}
		}
		
		cout << (ans + w[u] + w[v]) <<'\n';
//		cerr << (ans + w[u] + w[v]) <<" ans: "<< ans <<" w[u]: "<< w[u] <<" w[v]: "<< w[v] <<'\n';
	}
	return 0;
}
