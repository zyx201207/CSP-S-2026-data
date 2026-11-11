#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;
long long d,a[N],ans;
int dp[N],f[N];
inline void check(int l,int r){
	for(int i=l;i<=r;i++) dp[i]=N;
	dp[l]=0;f[l]=1;
	for(int i=l+1;i<=r;i++){
		f[i]=0;
		if(a[i]-a[i-1]>d) break;
		int mn=N;
		for(int j=i-1;j>=l;j--){
			if(a[i]-a[j]<=d) mn=min(mn,dp[j]);
			else break;
		}
		dp[i]=mn+1;
		for(int j=i-1;j>=l;j--){
			if(a[i]-a[j]>d) break;
			if(dp[j]==mn) f[i]+=f[j];
		}
		ans+=(f[i]==2);
	}
}
inline void solve(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ans=0;
	for(int i=1;i<=n;i++) check(i,n);
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
}
