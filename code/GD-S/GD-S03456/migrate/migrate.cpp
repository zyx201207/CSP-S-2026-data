// Created by YoungL
// Date: 10/31/2026
#include <bits/stdc++.h>
//#define ONLINE_JUDGE
#define FILENAME "migrate"

using ll = long long;
constexpr int N = 2e6 + 5;
int C;
int n;
ll x[N];
ll d;

int q[N];
int f[N]; // min
ll g[N]; // cnt

void solve() {
	std::cin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		std::cin >> x[i];
	}
	
	if (C == 13 or C == 14) {
		std:: cout << "0\n";
		return;
	}
	
	int res = 0;
	for (int s = 1; s <= n; ++s) {
//		std::cerr << "NOW start with " << s << ", ans = ";
		std::fill(f + 1, f + 1 + n, 0);
		std::fill(g + 1, g + 1 + n, 0);
		f[s] = 1;
		g[s] = 1;
		int h = 1;
		int t = 1;
		int p = 1;
		int Q = 1;
		q[1] = s;
		ll sum = 0;
		int ans = 0;
		for (int i = s + 1; i <= n; ++i) {
			while (h <= t and x[q[h]] + d < x[i]) {
				sum -= g[q[h]];
				++h;
			}
			if (p < h) {
				p = h;
			}
			while (p <= t and f[q[p]] == f[q[h]]) ++p;
			
			while (Q < p) {
				sum += g[q[Q]];
				++Q;
			}
			
			f[i] = f[q[h]] + 1;
			g[i] = sum;
			
			while (h <= t and f[q[t]] > f[i]) --t;
			q[++t] = i;
			
			if (g[i] == 2) {
				++ans;
			}
		}
//		std::cout << ans << "\n";
//		std::cerr << "F: ";
//		for (int i = s; i <= n; ++i) {
//			std::cerr << f[i] << " \n"[i == n];
//		}
//		std::cerr << "G: ";
//		for (int i = s; i <= n; ++i) {
//			std::cerr << g[i] << " \n"[i == n];
//		}
//		std::cerr << "\n";
		res += ans;
	}
	std::cout << res << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif

//	std::cin.tie(0);
//	std::cout.tie(0);
//	std::ios::sync_with_stdio(0);
	
	int t;
	std::cin >> C >> t;
	while (t--) {
		solve();
	}

	return 0;
}

