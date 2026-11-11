#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;
int mian(); int main() { return mian(); }

#define ll long long
#define fi first
#define se second
#define ppt pair<int, int>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define pb push_back

#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define gch ch = getchar()
void read(ll & x) { x = 0; bool f = 0; char gch; while(!isdigit(ch)) f |= (ch == '-'), gch; while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), gch; if(f) x = -x; }
void read(int & x) { x = 0; bool f = 0; char gch; while(!isdigit(ch)) f |= (ch == '-'), gch; while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), gch; if(f) x = -x; }
int stk_write[40], top_write;
void write(int x) {
	if(!x) return putchar('0'), void();
	if(x < 0) putchar('-'), x = -x;
	while(x) stk_write[++top_write] = x % 10, x /= 10;
	while(top_write) putchar('0' + stk_write[top_write]), top_write--;
}
const int N = 2e6 + 26;
int Case, n, _;
ll x[N], d;

int to[N];
void init_to() {
	int pt = n;
	for(int i = n; i >= 1; --i) {
		while(pt > i and x[pt] - x[i] > d) pt--;
		to[i] = pt;
	}
}
int cm[N];
void init_cm() {
	int pt = 1;
	FOR(i, 1, n) {
		while(pt < i and x[i] - x[pt] > d) pt++;
		cm[i] = pt;
	}
}
int c[N], rc[N];
void init_c() {
	FOR(u, 1, n) rc[u] = 0, c[u] = 0;
	for(int u = n; u >= 1; --u) {
		c[u]++; rc[u]++;
		if(u != cm[u]) {
			c[ cm[u] ] += rc[u];
			if( cm[cm[u]] != cm[u] ) {
				if(cm[cm[u] + 1] != cm[cm[u]]) {
					rc[cm[u]] += rc[u];
				}
			}
		}
	}
}
int g[N], rg[N];
void init_g() {
	FOR(u, 1, n) rg[u] = 0, g[u] = 0;
	for(int u = 1; u <= n; ++u) {
		g[u]++; rg[u]++;
		if(u != to[u]) {
			g[to[u]] += rg[u];
			if(to[to[u]] != to[u]) {
				if(to[ to[u] - 1 ] != to[to[u]]) {
					rg[ to[u] ] += rg[u];
				}
			}
		}
	}
}

void solve() {
	read(n); read(d);
	FOR(i, 1, n) read(x[i]);
	init_to();
	init_cm();
	init_c();
	init_g();
	// FOR(u, 1, n) cout<<to[u]<<" "<<cm[u]<<endl;
	// FOR(u, 1, n) cout<<cm[u]<<" "<<g[u]<<endl;
	ll ans = 0;
	int l = n + 1, r = n; ll sum = 0;
	for(int u = n; u >= 1; --u) {
		while(l > u + 2 and cm[l - 1] + 1 >= to[u]) l--, sum += c[l];
		// if(l <= n and cm[l] + 1 < to[u]) l++;
		while(r > u + 1 and cm[r] + 1 > to[u]) sum -= c[r], r--;
		if(l <= r) {
			// cout<<u<<" "<<l<<" "<<r<<" "<<sum<<endl;
			int pl = 1, pr = r - l + 1; bool xf = 0;
			if(l <= to[to[u]] and to[to[u]] <= r) {
				if(to[ to[u] - 1 ] == to[to[u]]) {
					pr += c[ to[to[u]] ] - (r - to[to[u]] + 1), xf = 1;
				}
			}
			if(u == cm[to[u]] and u == cm[to[u] - 1]) {
				pl = g[u], xf = 1;
			}
			// cout<<u<<"   "<<l<<" "<<r<<" "<<pl<<" "<<pr<<endl;
			ans += (ll)pl * pr;
		}
	}
	// cout<<n<<"   ";
	printf("%lld\n", ans);
}
int mian() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T; _ = scanf("%d%d", &Case, &T);
	while(T--) solve();
	return 0;
}/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989


0 1
1 1999999999999999992
0

0 1
6 2
-4 -3 -2 -1 3 6


0 1
5 2
1 2 3 4 5

0 1
4 2
1 2 3 4
*/