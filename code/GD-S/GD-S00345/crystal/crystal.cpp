#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l;i <= (r);i ++)
#define per(i,l,r) for(int i = l;i >= (r);i --)
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e5+5,INF=1e18;
int n,m,a[N],sum[N],ans;
void Solve() {
	cin >> n >> m;
	rep(i,1,n) cin >> a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) sum[i]=sum[i-1]+a[i];
	int l=0;
	rep(i,1,n) {
		int s=i-l;
		while(s*a[i]-sum[i]+sum[l]>m) l++,s--;
		ans=max(ans,s); 
	} 
	cout << ans;
	return ;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int dc=0,T=1,id;
	if(dc) cin >> T;
	rep(i,1,T) Solve();
	return 0; 
} 
