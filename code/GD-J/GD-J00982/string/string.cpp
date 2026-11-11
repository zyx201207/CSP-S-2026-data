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

const int N = 2e5 + 10;

int n; ll m;
ll a[N] ,l[N] ,r[N];
char c[N];

int main() {
	freopen("string.in" ,"r" ,stdin);
	freopen("string.out" ,"w" ,stdout);
	n = read();
	for (int i = 1;i <= n;i++) {
		a[i] = read(); cin >> c[i];
		m += a[i];
		l[i] = r[i - 1] + 1;
		r[i] = l[i] + a[i] - 1;
	}
	for (int i = 1;i <= n;i++)
		if (l[i] <= m / 2 && r[i] > m / 2) {
			n++;
			for (int j = n;j > i + 1;j--) a[j] = a[j - 1] ,c[j] = c[j - 1] ,l[j] = l[j - 1] ,r[j] = r[j - 1];
			a[i] = m / 2 - l[i] + 1;
			a[i + 1] = r[i] - m / 2,c[i + 1] = c[i];
			l[i + 1] = m / 2 + 1 ,r[i + 1] = r[i] ,r[i] = m / 2;
			break;
		}
	ll ans = 0;
	for (int i = 1 ,j = n;i <= n && l[i] <= m / 2;i++) {
		ll cur = 0;
		while (1) {
			ll L = max(l[j] ,m - r[i] + 1) ,R = min(r[j] ,m - l[i] + 1);
			if (L > R) { j--; continue; }
			ll len = R - L + 1;
			ans += len * (c[j] != c[i]) ,cur += len;
			a[j] -= len;
			if (!a[j]) j--;
			if (cur == a[i]) break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
