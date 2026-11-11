#include <bits/stdc++.h>
#define _rep(i,a,b) for(int i = a; i <= b; ++i)
// #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
using ll = long long;

char buf[1 << 20], *p1 = buf, *p2 = buf;
char gc(void) {
	if(p1 == p2) p1 = buf, p2 = buf + fread(buf, 1, 1 << 20, stdin);
	return *p1++;
}
int in(void) {
	int x = 0, f = 1; char c = gc();
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = gc();
	}
	while(isdigit(c)) x = x * 10 + c - '0', c = gc();
	return x * f;
}
ll inl(void) {
	ll x = 0, f = 1; char c = gc();
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = gc();
	}
	while(isdigit(c)) x = x * 10 + c - '0', c = gc();
	return x * f;
}

// int in(void) { int x; scanf("%d", &x); return x; }
// ll inl(void) { ll x; scanf("%lld", &x); return x; }
using namespace std;
const int kN = 2050000;	
ll x[kN]; int n; ll d;
int R[kN];
int cnt[kN][3];
void solve(void) {
	n = in(), d = inl();
	_rep(i,1,n) x[i] = inl(), cnt[i][0] = cnt[i][1] = cnt[i][2] = 0;
	_rep(i,1,n) {
		R[i] = max(i, R[i - 1]);
		while(R[i] < n && x[R[i] + 1] - x[i] <= d) ++R[i];
		if(i < R[i]) ++cnt[R[i]][0];
	}
	ll ans = 0;
	_rep(i,2,n) if(i < R[i]) {
		int y = R[i], flg = 0;
		// debug("y = %d\n", y);
		if(x[y] - x[i - 1] <= d) {
			if(i < 3 || x[y] - x[i - 2] > d) {
				cnt[y][1] += cnt[i][0];
			}
		} else {
			cnt[y][1] += cnt[i][1];
			if(x[y - 1] - x[i - 1] <= d) cnt[y][2] += cnt[i][0] + cnt[i][2];
			else cnt[y][0] += cnt[i][0] + cnt[i][2];
		}
		if(i > 2) ans += 1ll * cnt[i][0] * (max(i, R[i - 1]) - max(i, R[i - 2]));
		// debug("i = %d, ans = %lld, %d %d\n", i, ans, cnt[i][0], cnt[i][1]);
		ans += 1ll * cnt[i][1] * (max(i, R[i]) - max(i, R[i - 1]));
		// debug("i = %d, ans = %lld, %d %d\n", i, ans, cnt[i][0], cnt[i][1]);
	}
	printf("%lld\n", ans);
	// L[n + 1] = 0;
	// for(int i = n; i; --i) {
	// 	L[i] = min(i, L[i + 1]);
	// 	while(L[i] > 1 && x[i] - x[L[i] - 1] <= d) --L[i];
	// }

	// int ans = 0;
	// _rep(u,1,n) if(u < R[u]) _rep(v,u + 1,n) {
	// 	int i = u;
	// 	vector<int> path;
	// 	while(i < v) path.push_back(i), i = R[i];
	// 	path.push_back(v);
	// 	int cnt = 0;
	// 	for(int i = 1; i + 1 < path.size(); ++i) {
	// 		if(x[path[i + 1]] - x[path[i] - 1] <= d) {
	// 			if(i > 1 && x[path[i] - 1] - x[path[i - 1] - 1] <= d) {
	// 				cnt = -114514;
	// 			}
	// 			++cnt;
	// 		}
	// 		if(path[i] >= 3 && x[path[i + 1]] - x[path[i] - 2] <= d) cnt = -114514;
	// 	}
	// 	if(cnt == 1) {
	// 		++ans, debug("%d %d\n", u, v);
	// 		for(auto &u : path) debug("%d ", u); debug("\n");
	// 	}
	// 	if(R[v] == v) break;
	// }
	// printf("%d\n", ans);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	in(); int t = in();
	while(t--) solve();
	return 0;
}