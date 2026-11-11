#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll read() {
	ll n = 0 ,f = 1; char c = getchar();
	while (c < '0' || c > '9') f = (c == '-') ? -f : f ,c = getchar();
	while (c >= '0' && c <= '9') n = n * 10 + c - '0' ,c = getchar();
	return n * f;
}
template<class T> inline void chkmx(T &x ,T y) { if (y > x) x = y; }
template<class T> inline void chkmn(T &x ,T y) { if (y < x) x = y; }

int main() {
	freopen("travel.in" ,"r" ,stdin);
	freopen("travel.out" ,"w",stdout);
	string a ,b ,c ,d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		putchar('1');
		if (b[0] == d[0] && b[1] == d[1]) {
			putchar('1');
			if ((b[2] <= 'C') == (d[2] <= 'C')) {
				putchar('1');
				putchar(abs(d[2] - b[2]) == 1 ? '1' : '0');
				putchar('\n');
			} else puts("00");
		} else puts("000");
	} else puts("0000");
	return 0;
}
