// crystal
#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
#define pc(x) putchar(x)
using ll = long long ;
inline ll read() {ll res = 0;char ch = gc();ll flag = 1;while(!isdigit(ch)) {if(ch == '-') {flag = -flag;}ch = gc();}while(isdigit(ch)) {res = res*10+ch-48;ch = gc();}return res*flag;}
void write(ll x) {if(x < 0) {pc('-');x = -x;}if(x >= 10) {write(x/10);}pc(x%10+48);}

int const maxn = 5e5+5;
ll a[maxn];
ll s[maxn];
int n;
ll m;

inline ll check(ll x) {
	// 第一步先找到小于或等于x最靠右的
	int l = 1,r = n;
	int ans = 0;
	int pr = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(a[mid] <= x) {
			// 往前找 
			l = mid+1;
			pr = mid;
		}
		else  r = mid-1;
	} 
	l = 1,r = pr;
	// 第二部找最多能选多少个
	
	while(l <= r) {
		int mid = (l + r) >> 1;
		// 此时相当于选择了 pr ~ pr-mid+1 区间内的
		if(x*mid - s[pr] + s[pr-mid] <= m) {
			ans = mid;
			l = mid+1;
		} 
		else  r = mid-1;
	}
	return ans;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read();
	m = read();
	for(int i = 1; i <= n; ++i) {
		a[i] = read();
	}
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; ++i)  s[i] = s[i-1] + a[i];
	ll ans = 0;
//	for(int i = -1000; i <= 1000; ++i) {
//		write(check(i)),pc(10);
//	}
	for(int i = 1; i <= n; ++i) {
		ans = max(ans,check(a[i]));
	}
	write(ans),pc(10);
	return 0;
}




















 
