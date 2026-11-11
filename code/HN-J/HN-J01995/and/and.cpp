#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 114;
int read() {
	int x = 0, f = 1;
	char c = getchar();
	for(;c < 48 || c > 57; c = getchar())
		if(c == '-')
			f = -1;
	for(;c >= 48 && c <= 57; c = getchar())
		x = x * 10 + c - 48;
	return x * f;
}
void write(int x) {
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
	return ;
}
int n, m, x, ans;
int cnt, mx, top;
int a[N];
int t[114][N];
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + 1 + n, greater<int >());
	for(int i = 1; i <= n; i++) {
		x = a[i], cnt = 0;
		while(x) {
			++cnt;
			mx = max(mx, cnt);
			if(x & 1)
				t[cnt][i] = true;
			x >>= 1;
		}
	}
	for(int i = 1; i <= mx; i++)
		for(int j = 1; j <= n; j++)
			t[i][j] += t[i][j - 1];
	top = n;
	for(int i = mx; i; i--) {
		if(t[i][top] < m) continue;
		while(t[i][top] == t[i][top - 1]) --top;
		ans += 1 << (i - 1);
	}
	write(ans);
	cout << endl;
	return 0;
}
