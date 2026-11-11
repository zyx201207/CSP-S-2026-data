#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000002],l[2000002],r[2000002];
int ans,dp[2000002],newr[2000002],hsh[2000002],newl[2000002];
int dp2[2000002];
void solve(){
	memset(hsh,0,sizeof(hsh));
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
		newr[i]=r[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
//		cout << l[i] << ' ' << r[i] << endl;
	}
	int cnt=unique(newr+1,newr+n+1)-newr-1;
	memset(hsh,0,sizeof(hsh));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		int wz=lower_bound(newr+1,newr+cnt+1,l[i]+1)-newr;
		if(!(r[i-2]==i-1&&l[i]==i-1)&&
			wz!=i-1&&newr[wz]==l[i]+1)dp[i]+=hsh[wz];
		if(l[i]==i-1)dp2[i]=dp2[i-1]+1,dp[i]+=dp[i-1];
		hsh[lower_bound(newr+1,newr+cnt+1,r[i])-newr]+=dp2[i]+1;
		ans+=dp[i];
	}
	cout << ans << endl;
//	for(int i=1;i)
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d,ans=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		solve();
	}
}
