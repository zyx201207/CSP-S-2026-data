#include<bits/stdc++.h>
using namespace std;
inline long long rd() {
	long long x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch-'0'); ch=getchar();}
	return x * f;
}
inline void write(long long x) {
	if(x < 0) putchar('-'), x=-x;
	if(x > 9) write(x/10); putchar(x%10+'0');
}
inline void wt(long long x,char ch) {
	write(x); putchar(ch);
}
long long n, m;
const long long N = 1e6+7;
long long a[N], sum[N];
long long check(long long l,long long r) {
	long long ans = r;
	long long R = r;
	while(l <= r) {
		long long mid = (l + r) / 2;
		long long len = R - mid + 1; 
		if(len*a[R]-(sum[R]-sum[mid-1]) <= m) ans = mid, r = mid-1;
		else l = mid+1; 
	}
	return R - ans + 1;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = rd(), m = rd();	
	for(long long i=1;i<=n;i++) {
		a[i] = rd(); 
	}
	sort(a+1,a+n+1);
	long long ans = 1;
	for(long long i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
	for(long long i=1;i<=n;i++) {
		ans = max(ans,check(1,i)); 
	} 
	wt(ans,'\n');
	return 0;
}
