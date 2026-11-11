#include <bits/stdc++.h>
using namespace std;
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define pre(i,n) for(int i = n;i;--i)
#define rep(i,n) for(int i = 1;i <= n;++i)
#define rpt(i,a,n) for(int i = a;i <= n;++i)
#define repg(i,u) for(int i = head[u];i;i = e[i].nxt)
#define WR(x) cerr<<#x<<':'<<x<<endl
#define int long long
#define swap(x,y) (x ^= y ^= x ^= y)
constexpr int N = 5e5 + 5;
int a[N],n,m,res;
signed main(){
	// fin("crystal4.in"),fout("crystal.out");
	fin("crystal.in"),fout("crystal.out");
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	rep(i,n) cin>>a[i];
	sort(a + 1,a + n + 1);
	int u = m,l = 1;
	rep(i,n){
		u -= (a[i] - a[i-1]) * (i - l);
		while(u < 0) u += a[i] - a[l],++l;
		res = max(res,i - l + 1);
	}
	cout<<res;
	cerr<<'\n'<<1.0 * clock() / CLOCKS_PER_SEC;
	return 0;
}