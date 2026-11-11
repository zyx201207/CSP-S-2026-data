#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
template<class T>bool ckmax(T &x,const T y){return x<y?x=y,1:0;}
template<class T>bool ckmin(T &x,const T y){return x>y?x=y,1:0;}
inline int read(){
	int f=1,w=0,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) w=(w<<3)+(w<<1)+(ch^48);
	return f*w;
}
const int N = 5e5 + 10;
int n, m, a[N], f[N];
bool check(int x) {
	rep(i, x, n) {
		int sum = f[i] - f[i - x];
		if (x * a[i] - sum <= m) return true;
	}
	return false;
}
signed main() {
//	freopen("crystal4.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(), m = read();
	rep(i, 1, n) a[i] = read();
	sort(a + 1, a + 1 + n);
	rep(i, 1, n) f[i] = f[i - 1] + a[i];
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	printf("%lld", ans);
	return 0;
}
