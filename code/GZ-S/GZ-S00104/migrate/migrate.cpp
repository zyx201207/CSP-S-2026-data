//GZ-S00104 贵阳市第一中学 胡源宸 
#include<bits/stdc++.h>
#define ll long long
#define ls i<<1
#define rs i<<1|1
using namespace std;
const int N=2e6+5,L=22;
ll T,n,a[N],d,ans,c,dp[N],dp2[N],sumn[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=0;
	for(int u=1;u<=n;u++){
		for(int i=u;i<=n;i++) dp[i]=dp2[i]=0;
		for(int i=1;i<=n;i++) sumn[i]=0;
		dp[u]=1;
		sumn[u]=1;
		ll l=u,r=u,zhi=u;
		for(int v=u+1;v<=n;v++){
			if(a[v]-a[v-1]>d) break;
			while(a[v]-a[l]>d){
				l++;
			}
			if(r<l) r=l;
			while(r<v&&dp2[r]==dp2[l]) r++;
			if(r==v) r--;
			if(dp2[r]!=dp2[l]) r--;
			while(zhi<=r){
				zhi++;
			}
			dp[v]=sumn[r]-sumn[l-1];
			sumn[v]=sumn[v-1]+dp[v];
			dp2[v]=dp2[l]+1;
			if(dp[v]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	cin.tie(nullptr);
	freopen("migrate.out","w",stdout);
	T=1;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
