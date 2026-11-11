#include <iostream>
#include <cctype>
#include <vector>
#define gc getchar
#define pc putchar
#define int long long
using namespace std;
const int N = 500005;
int n, m, a[N], pos[N], /*portal[N]*/ root[N], siz[N];
//bool predone[N];
vector <int> g[N];
inline void rd(int &x) {
	int sum = 0, f = 1, c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
	for (; isdigit(c); c = gc()) sum = sum * 10 + c - '0';
	x = sum * f;
}
inline void wt(int x) {
	if (x > 9) wt(x/10);
	pc(x%10+'0');
}
void dfs(int x) {
	siz[x] = 1;
	for (int v : g[x]) {
		dfs(v);
		siz[x] += siz[v];
	}
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	rd(n); rd(m);
	for (int i = 1; i <= n; i++) {
		rd(a[i]);
	}
//	for (int i = 1; i <= n; i++) { // every round
//		if (predone[i]) continue;
//		for (int j = 1; j <= m; j++) { // init
//			pos[j] = 0;
//		}
//		for (int j = 1; j <= n; j++) {
//			portal[j] = 0;
//		}
//		for (int j = i; j <= n; j++) { // show a card
//			if (pos[a[j]]) {
//				for (int k = pos[a[j]]; k < j; k++) {
//					if (portal[k]) k = portal[k];
//					pos[a[k]] = 0;
//				}
//				portal[pos[a[j]]] = j;
//				if (pos[a[j]] == i)
//			}
//		}
//	}
	for (int i = n; i; i--) {
		if (pos[a[i]]) {
			g[pos[a[i]]].push_back(i);
//			wt(pos[a[i]]);pc('>');wt(i);pc('\n');
		}
		else {
			// get result from the last one
			root[a[i]] = i;
			g[i+1].push_back(i);
		}
		pos[a[i]] = i;
	}
	dfs(n);
	for (int i = 1; i <= m; i++) {
		wt(siz[root[i]]); pc(' ');
	}
	return 0;
}
