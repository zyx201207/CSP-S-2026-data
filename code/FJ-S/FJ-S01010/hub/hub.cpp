#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
const int N = 1e6 + 10;
int c, T;
int n, k;
vector<int> e[N];
void solve() {
	n = read(), k = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		e[u].push_back(v), e[v].push_back(u);
	}
	if (c == 13 || c == 14) cout << (n + 1) / 8 - k / 4 + 1 << endl;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = read(), T = read();
	while (T--) solve();
	return 0;
}
int read() {
	int Ca = 0;
	char Cr = ' ';
	int Cf = 1;
	while (Cr < '0' || Cr > '9') {
		Cr = getchar();
		if (Cr == '-') Cf = -1;
	} 
	while (Cr >= '0' && Cr <= '9') {
		Ca = Ca * 10 + Cr - '0';
		Cr = getchar();
	}
	return Ca * Cf;
}