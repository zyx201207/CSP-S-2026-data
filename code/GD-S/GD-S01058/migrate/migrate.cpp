#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define pii pair<int ,int>
ll read() {
	ll n = 0 ,f = 1; char c = getchar();
	while (c < '0' || c > '9') f = (c == '-') ? -f : f ,c = getchar();
	while (c >= '0' && c <= '9') n = n * 10 + c - '0' ,c = getchar();
	return n * f;
}
template<class T> inline void chkmx(T &x ,T y) { if (y > x) x = y; }
template<class T> inline void chkmn(T &x ,T y) { if (y < x) x = y; }

const int N = 2e6 + 10;

int n; ll d;
ll a[N];
int nxt[N] ,g[N] ,f[N] ,h[N]; // 下一个位置，向左几个唯一起点，向右几个唯一终点，向左几个唯一起点（同时满足 i - 1 和 i） 

void solve() {
	n = read() ,d = read();
//	printf("%d\n",n);
	for (int i = 1;i <= n;i++) a[i] = read();
	nxt[0] = 1;
	for (int i = 1 ,j = 1;i <= n;i++) {
		while (j < n && a[j + 1] - a[i] <= d) j++;
		nxt[i] = j;
	}
	for (int i = 1;i < n;i++) {
		g[nxt[i]] += g[i] * (nxt[i - 1] < nxt[i]) + 1;
		h[nxt[i]] += g[i] * (nxt[i - 1] < nxt[i] - 1) + 1;
	}
	for (int i = n;i >= 1;i--)
		if (nxt[i - 1] == nxt[i]) f[i] = 0;
		else f[i] = f[nxt[i]] + nxt[i] - max(i ,nxt[i - 1]); // i - 1 不能到 
//	for (int i = 1;i <= n;i++) printf("%d ",nxt[i]);
//	puts("");
//	for (int i = 1;i <= n;i++) printf("%d ",f[i]);
//	puts("");
//	for (int i = 1;i <= n;i++) printf("%d ",g[i]);
//	puts("");
	ll ans = 0;
	for (int i = 2;i <= n;i++) if (nxt[i - 1] > i) {
//		printf("%d:\n",i);
		// nxt 以后的 
		if (nxt[i - 1] == nxt[i] && nxt[i - 2] < nxt[i])
			ans += 1LL * h[i] * f[nxt[i]];
//		printf("%lld\n",ans);
		// i + 1 ~ nxt 的 
		ans += 1LL * h[i] * (nxt[i - 1] - max(i ,nxt[i - 2]));
//		printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
	
	for (int i = 1;i <= n;i++) nxt[i] = f[i] = g[i] = h[i] = 0;
}

int main() {
//	freopen("migrate3.in" ,"r" ,stdin);
	freopen("migrate.in" ,"r" ,stdin);
	freopen("migrate.out" ,"w" ,stdout);
	int c = read() ,T = read();
	while (T--) solve();
	return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63
*/
