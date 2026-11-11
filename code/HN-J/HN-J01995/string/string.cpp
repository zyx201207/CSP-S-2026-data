#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 114;
ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	for(;c < 48 || c > 57; c = getchar())
		if(c == '-')
			f = -1;
	for(;c >= 48 && c <= 57; c = getchar())
		x = x * 10 + c - 48;
	return x * f;
}
void write(ll x) {
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
	return ;
}
ll n, m, tot, ans;
ll now, tmp, cnt1, cnt2;
struct L {
	ll x;
	char ch;
}l[N], r[N];
int a[N];
char c[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		tot += a[i];
		cin >> c[i];
	}
	r[cnt2].x = (tot + 1) / 2;
	for(int i = 1; i <= n; i++) {
		if(now + a[i] <= (tot + 1) / 2) {
			if(now + a[i] == (tot + 1) / 2)
				if(tot & 1) --a[i];
			now += a[i];
			++cnt1;
			l[cnt1].x = now;
			l[cnt1].ch = c[i];
			if(now + a[i] == (tot + 1) / 2)
				if(tot & 1) ++now;
		} else { 
			tmp = now;
			if(now + 1 < (tot + 1) / 2) {
				now = (tot + 1) / 2;
				if(tot & 1) --now;
				++cnt1;
				l[cnt1].x = now;
				l[cnt1].ch = c[i];
				if(tot & 1) ++now;
			}
			now = tmp;
			now += a[i];
			++cnt2;
			r[cnt2].x = now;
			r[cnt2].ch = c[i];
		}
	}
	ll it = cnt2;
	ll tail = r[it].x;
	for(ll i = 1; i <= cnt1; i++) {
		int len = l[i].x - l[i - 1].x;
		while(len >= tail - r[it - 1].x && it) {
			if(l[i].ch != r[it].ch) 
				ans += r[it].x - r[it - 1].x;
			len -= r[it].x - r[it - 1].x;
			--it, tail = r[it].x;
		}
		if(it) {
			if(l[i].ch != r[it].ch)
				ans += len;
			tail -= len;
		}
	}
	write(ans);
	cout << endl;
	return 0;
}
