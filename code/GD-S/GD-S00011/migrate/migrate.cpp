#include <algorithm>
#include <iostream>
#include <assert.h>
#include <vector>

const int N = 2e6 + 7;
typedef long long i64;

int n;
i64 d; i64 x[N];
int l[N], r[N], bk[N];
int asr[N], asl[N];
int pre[N], nex[N];

inline void solve() {
	std::cin >> n >> d;
	for(int i = 1; i <= n; ++i) { std::cin >> x[i]; }
	int pt = 1;
	for(int i = 1; i <= n; ++i) {
		while(x[i] - x[pt] > d) ++pt;
		l[i] = pt;
		bk[i] = bk[i-1]; if(l[i] == i) ++bk[i];
	}
	pt = n;
	for(int i = n; i >= 1; --i) { while(x[pt] - x[i] > d) --pt; r[i] = pt; }
	for(int i = 1; i <= n; ++i) asl[i] = asr[i] = 0;
	for(int i = 1; i <= n; ++i) {
		if(l[i] != i) ++asl[l[i]];
		if(r[i] != i) ++asr[r[i]];
	}
	for(int i = 1; i <= n; ++i) { pre[i] = asr[i]; if(l[i] < i && r[l[i]] == i) pre[i] += pre[l[i]]; }
	for(int i = n; i >= 1; --i) { nex[i] = asl[i]; if(r[i] > i && l[r[i]] == i) nex[i] += nex[r[i]]; }
	i64 ans = 0;
	for(int i = 1; i < n; ++i) {
		if(bk[i] != bk[i+1]) continue;
		i64 v1 = asr[i+1] - (r[i] == i+1);
		if(l[i] < i && r[l[i]] == i+1) v1 += pre[l[i]];
		i64 v2 = asl[i] - (l[i+1] == i);
		if(r[i+1] > i+1 && l[r[i+1]] == i) v2 += nex[r[i+1]];
		ans += v1 * v2;
	}
	std::cout << ans << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int c, t; std::cin >> c >> t; 
	while(t--) solve();
} 
