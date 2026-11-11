#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
const int N = 5e5 + 10;
int n, m;
int a[N], pre[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	for (int i = 1, j = 1; i <= n && i + j - 1 <= n; i++) {
		while ((pre[i + j - 1] - pre[i - 1] + m) / j >= a[i + j - 1] && i + j - 1 <= n) j++;
		ans = max(ans, j - 1);
	}
	cout << ans;
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