#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define intl long long
#define For(i,a,b) for(intl i=a;i<=b;i++)
#define deo(i,a,b) for(intl i=a;i>=b;i--)
intl read() {
	intl x=0,k=1;char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') k = -1; ch = getchar();}
	while(isdigit(ch)) x = (x<<3)+(x<<1)+(ch^48), ch = getchar();
	return x*k;
}
intl n, x[N], d, q[N], g[N], f[N], sum[N];
void solve() {
	n = read(), d = read();
	For(i,1,n) x[i] = read();
	intl ans = 0;
	For(i,1,n) {		
		intl h = 1, t = 0;
		q[++t] = i, g[i] = 1, sum[0] = 1, f[i] = 0;
		For(j,i+1,n) {
			while(h <= t && x[j] - x[q[h]] > d) sum[f[q[h]]] -= g[q[h]], h ++;
			if(h > t) break;
			g[j] = sum[f[q[h]]], f[j] = f[q[h]] + 1;
			if(g[j] == 2) ans ++;
			while(h <= t && f[j] < f[q[t]]) sum[f[q[t]]] -= g[q[t]], t --;
			sum[f[j]] += g[j], q[++t] = j;
		}
		For(j,1,n) g[j] = f[j] = sum[j] = 0;		
	}
	printf("%lld\n", ans);
}
void clear() {
	For(i,1,n) x[i] = q[i] = g[i] = f[i] = sum[i] = 0;
}
void solveA() {
	n = read(), d = read();
	For(i,1,n) x[i] = read();
	intl dd = x[2] - x[1], k = d/dd, ans = 0;
	if(k <= 1) return puts("0"), void();
	For(i,1,n) ans += (i+k+k-1 <= n);
	printf("%lld\n", ans);
}
intl sta[N], l[N], r[N];
void solveB() {
	n = read(), d = read();
	For(i,1,n) x[i] = read(), r[i] = 0;
	intl rt = 0, cnt = 0;
	deo(i,n,1) if(x[i] + d >= x[n] && x[i] - d <= x[1]) rt = i, cnt ++;
	intl j = 1;
	For(i,1,n) {
		j = max(j, i);
		while(j <= n && x[j] - x[i] <= d) j ++;
		r[i] = j-1;
	}
	intl ans = 0;
//	cout << cnt << " " << rt << endl;
//	For(i,1,n) cout << r[i] << " \n"[i == n];
	if(cnt >= 3) return puts("0"), void();
	else {
		For(i,1,n) {
			if(rt <= r[i] && r[i] <= rt+1) ans += n-r[rt-1];
			else ans += n-r[r[i]];
		} 
	}
	printf("%lld\n", ans);
}
void solveC() {
	
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	intl c = read(), T = read();
	if(11 <= c && c <= 12) while(T--) solveA();
	else if(13 <= c && c <= 14) while(T --) solveB();
	else if(15 <= c && c <= 18) while(T --) solveC();
	else while(T--) solve(), clear();
	return 0;
}
/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5

11 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
5 5
1 4 6 7 10

13 1
8 70
1 8 13 24 32 56 78 102
*/

