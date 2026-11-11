#include <bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
il int rd(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = (s << 1) + (s << 3) + ch - 48;
	return s * w;
}
const int N = 2000005, B = 131, P = 1e9 + 9, INF = 1e18;
il int ksm(int x, int r){
	int ans = 1;
	for (; r; x = 1ll * x * x % P, r >>= 1) if (r & 1) ans = 1ll * ans * x % P;
	return ans;
}
int cid, T, n, d, a[N], h1[N], h2[N], lenth[N], h[N], t1[N], t2[N], c1[N], c2[N], ans, pw[N], ipw[N];
signed Main(){
	n = rd(), d = rd(), pw[0] = ipw[0] = 1, ans = 0;
	for (int i = 1; i <= n; i++) a[i] = rd(), c1[i] = c2[i] = 0, pw[i] = pw[i - 1] * B % P, ipw[i] = ksm(pw[i], P - 2);
	
	if (cid == 11 || cid == 12){
//		cout << n << " " << d << " " << a[2] - a[1] << "\n";
		if (d < 2 * (a[2] - a[1])) puts("0");
		else printf ("%lld\n", max(n - 2 * (d / (a[2] - a[1])) + 1, 0ll));
		return 0;
	}
	
	a[n + 1] = 3 * INF, h1[n + 1] = 0, h2[0] = 0, lenth[n + 1] = -1, t1[0] = t2[0] = 0, t1[n + 1] = t2[n + 1] = n + 1;
	for (int i = 1; i <= n; i++){
		t1[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1; if (t1[i] == i) t1[i] = n + 1;
		t2[i] = lower_bound(a + 1, a + n + 1, a[i] - d) - a; if (t2[i] == i) t2[i] = 0;
		c1[t1[i]]++, c2[t2[i]]++;
	}
	
	for (int i = 1; i <= n; i++) h2[i] = (h2[t2[i]] * B % P + i) % P;
	for (int i = n; i >= 1; i--) lenth[i] = lenth[t1[i]] + 1, h1[i] = (h1[t1[i]] + i * pw[lenth[i]] % P) % P;
	for (int i = 1; i <= n; i++) h[i] = (h1[i] + h2[i] * pw[lenth[i]] % P - i * pw[lenth[i]] % P + P) % P;
	
	for (int i = 1; i <= n; i++){
		unordered_set <int> s;
		for (int j = t1[i], lj = i, t = 1; j <= n; lj = j, j = t1[j], t++){
			int delta = (h[i] - h[j] + P) % P * ipw[lenth[j]] % P;
			if (s.count(delta)) ans += c1[i] * c2[j];//, cout << i << " " << j << " " << c1[i] * c2[j] << " Lre\n";
			
			delta = (h[i] - h[lj] + P) % P;
			if (delta == 0 && t2[j - 1] == lj) ans += c1[i] * c2[j - 1];//, cout << i << " " << j << " " << c1[i] * c2[j - 1] << "\n";
			
			s.insert(pw[t]);
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = t2[i], lj = i, t = 1; j; lj = j, j = t2[j], t++){
			int delta = (h[lj] - h[i] + P) % P;
			if (delta == 0 && t1[j + 1] == lj) ans += c1[j + 1] * c2[i];//, cout << i << " " << j << " " << c1[j + 1] * c2[i] << "\n";
		}
	}
	for (int i = 1; i < n; i++) ans += (c2[i] - (t2[i + 1] == i)) * (c1[i + 1] - (t1[i] == i + 1));

	printf ("%lld\n", ans);
	return 0;
}
signed main(){
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	for (cid = rd(), T = rd(); T--;) Main();
	return 0;
}
/*
10 3
0 3 6 7 8 9 10 11 14 17

*/
