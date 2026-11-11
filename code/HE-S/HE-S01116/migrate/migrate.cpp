#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int rd() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch-'0'); ch=getchar();}
	return x * f;
}
inline void write(int x) {
	if(x < 0) putchar('-'), x=-x;
	if(x > 9) write(x/10); putchar(x%10+'0');
}
inline void wt(int x,char ch) {
	write(x); putchar(ch);
}
/*
»√Œ“”Æ“ª¥Œ 
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/ 
const int N = 2e6+7;
int n, d;
int f[N], g[N], x[N];
int q[N], cnt[N];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c = rd(), t = rd();
	while(t--) {
		n = rd(), d = rd();
		for(int i=1;i<=n;i++) {
			x[i] = rd();
		}
		int ans = 0;
		for(int l=1;l<=n;l++) {
			for(int i=0;i<=n;i++) cnt[i] = 0;  
			for(int r=l;r<=n;r++) f[r] = 1e9, g[r] = 0;
			f[l] = 0, g[l] = 1;
			int head = 1, tail = 0;
			q[++tail] = l;
			cnt[f[l]] += g[l]; 
			for(int r=l+1;r<=n;r++) {
				while(head <= tail && x[r] - x[q[head]] > d) {
					cnt[f[q[head]]] -= g[q[head]];
					head ++;
				}
				if(head > tail) break;
				f[r] = f[q[head]] + 1;
				g[r] = cnt[f[q[head]]];
				if(g[r] > 2) g[r] = 3;
				if(g[r] == 2) ans++;
				while(head <= tail && f[r] < f[q[tail]]) {
					cnt[f[q[tail]]] -= g[q[tail]];
					tail--;
				}
				q[++tail] = r;
				cnt[f[r]] += g[r];  
			}
		} 
		wt(ans,'\n');
	} 
	return 0;
}
