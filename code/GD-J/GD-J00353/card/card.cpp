#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a;i <= (b);i ++)
#define per(i,a,b) for(int i = a;i >= (b);i --)
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e5+5,INF=1e18;
int n,m,a[N],t[N],z[N],dp[N],ans[N];
void Solve() {
	cin >> n >> m;
	rep(i,1,n) cin >> a[i];
	per(i,n,1) if(t[a[i]]) z[i]=t[a[i]]; else t[a[i]]=i;
	rep(i,1,n) if(z[i]!=0) dp[z[i]]+=dp[i]+1; 
	else ans[a[i]]=dp[i]+1,dp[i+1]+=dp[i]+1;
	rep(i,1,m) cout << ans[i] << " ";
	return ;
}
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int dc=0,T=1;
	if(dc) cin >> T;
	rep(i,1,T) Solve();
	return 0;
}

