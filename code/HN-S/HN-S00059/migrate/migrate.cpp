/*
T3 我应该是想不出正解的

首先有 O(n^3) 的朴素暴力

发现只用维护前 3 优秀的转移，于是优化成 O(n^2) 

性质 A 可以发现结构是相同的，只 DP 1 次。 
*/
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e6 + 10;
const int M = 5e3 + 10; 
const int INF = 1e18;
int n, m, a[N], ans;
int f[N], g[N]; 

void getdp(int i, int j) {
	if(j <= i) return;
	if(f[i] + 1 < f[j]) {
		f[j] = f[i] + 1;
		g[j] = 0;
	}
	if(f[i] + 1 == f[j]) g[j] += g[i];
}

void task1() {
	ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) f[j] = INF;
		f[i] = 0, g[i] = 1;
		for(int j = i, k = i; j <= n; j++) {
			while(a[j] - a[k] > m) k++;
			getdp(k, j), getdp(k + 1, j), getdp(k + 2, j);
			if(f[j] != INF && g[j] == 2) ans++;
			g[j] = min(g[j], 3ll);
		} 
	} cout << ans << '\n';
	return;
}

void task2() {
	ans = 0;
	for(int i = 1; i <= n; i++) f[i] = INF; 
	f[1] = 0, g[1] = 1;
	for(int j = 1, k = 1; j <= n; j++) {
		while(a[j] - a[k] > m) k++;
		getdp(k, j), getdp(k + 1, j), getdp(k + 2, j);
		if(f[j] != INF && g[j] == 2) ans += (n - j + 1);
		g[j] = min(g[j], 3ll);
	} 
	cout << ans << '\n';
	return;
}

signed main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout); // fc migrate.out migrate.ans
	int C, T; cin >> C >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i];
		if(C <= 10) task1(); else
		if(C <= 12) task2(); else
		task1();
	}
	return 0;
}
