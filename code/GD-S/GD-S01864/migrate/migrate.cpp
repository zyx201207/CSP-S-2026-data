#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6 + 5, inf = (int)4e18 + 5; 
int n, d, a[maxn], l[maxn], r[maxn];
int cntt = 0;
int call(int x, int y, int p) {
	int cnt = 0;
	for (int i = x; i < y; i++) {
		cnt += (r[i] == p);
//		cntt++;
		if(r[i] != p)
			break;
	}
	return cnt;
}
int calr(int x, int y, int p) {
	int cnt = 0;
	for (int i = y; i > x; i--) {
		cnt += (l[i] == p);
//		cntt++;
		if(l[i] != p)
			break;
	}
	return cnt;
}
int Read() {
	int sum = 0, f = 1; char c = getchar();
	while(!isdigit(c)) {
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(isdigit(c))
		sum = sum * 10 + c - '0', c = getchar();
	return sum * f;
}
void Write(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x <= 9) {
		putchar(x + '0');
		return ;
	}
	Write(x / 10); putchar(x % 10 + '0');
}
int vl[maxn], vr[maxn];
void solve() {
	n = Read(); d = Read();
	for (int i = 1; i <= n; i++)
		a[i] = Read(), l[i] = 0, r[i] = n + 1;
	a[n + 1] = inf, a[0] = -inf;
	int p = n + 1;
	for (int i = n; i >= 1; i--) {
		while(a[p] - a[i] > d)
			p--;
		r[i] = p;
	}
	p = 0;
	for (int i = 1; i <= n; i++) {
		while(a[i] - a[p] > d)
			p++;
		l[i] = p;
	}
	for (int i = 1; i <= n; i++) {
		if(l[i] != i && r[l[i]] == i) 
			vl[i] = vl[l[i]] + call(l[i], i, i);
		else
			vl[i] = 0;
	}
	for (int i = n; i >= 1; i--) {
		if(r[i] != i && l[r[i]] == i)
			vr[i] = vr[r[i]] + calr(i, r[i], i);
		else
			vr[i] = 0;
	}
//	for (int i = 1; i <= n; i++)
//		cout << l[i] << " " << r[i] << endl;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if(!l[i] || r[i] == n + 1 || !l[i + 1] || r[i + 1] == n + 1)
			continue;
		int lv = call(l[i + 1], i, i + 1), rv = calr(i + 1, r[i], i);
//		cout << lv << " " << rv << " " << vr[r[i]] << " " << r[i] << " " << r[i + 1] << endl;
		if(i != l[i] && l[i] == l[i + 1] && r[l[i]] == i + 1)
			lv += vl[l[i]];
		if(i != r[i] && r[i] == r[i + 1] && l[r[i]] == i)
			rv += vr[r[i]];
//		cout << i << " " << lv << " " << rv << endl;
		ans += lv * rv;
	}
//	cerr << cntt << " " << n << endl;
	Write(ans), putchar('\n');
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	cout << inf << endl;
	int c, T; cin >> c >> T;
	while(T--)	
		solve();
	return 0;
} 
/*
1 1
6 3
0 1 2 3 4 7
*/
