#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
#define pc(x) putchar(x)
using ll = long long ;
inline ll read() {ll res = 0;char ch = gc();ll flag = 1;while(!isdigit(ch)) {if(ch == '-') {flag = -flag;}ch = gc();}while(isdigit(ch)) {res = res*10+ch-48;ch = gc();}return res*flag;}
void write(ll x) {if(x < 0) {pc('-');x = -x;}if(x >= 10) {write(x/10);}pc(x%10+48);}

ll d;
int const maxn = 2e6+5;
ll a[maxn];
int f[maxn];
ll dp[maxn];

inline void work() {
	int n = read();d = read();
	for(int i = 1; i <= n; ++i)  a[i] = read();
	for(int i = 1; i <= n; ++i) {
		int l = i,r = n;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(a[mid] - a[i] <= d) {
				f[i] = mid;
				l = mid+1;
			}
			else  r = mid-1;
		} 
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		fill(dp+i,dp+1+n,0);
		for(int j = i; j <= f[i]; ++j)  dp[j] = 1;
		int x = i;
		while(x != f[x]) {
			// 这次跳到 f[x] ，那么所有跳超过 f[x] 的都可以对后面贡献
			if(x+1 == f[x]) {
				for(int k = f[x]+1; k <= f[f[x]]; ++k) {
					dp[k] += dp[x+1];
				}
				++x;
				continue ;
			}
			for(int j = max(x,f[x]-2); j <= f[x]; ++j) {
				for(int k = f[x]+1; k <= f[j]; ++k)  dp[k] += dp[j];
			} 
			x = f[x];
		}
		for(int j = i; j <= n; ++j)  ans += (dp[j] == 2);
	}
	write(ans),pc(10);
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c = read(),T = read();
	while(T--)  work();
	return 0;
}





















