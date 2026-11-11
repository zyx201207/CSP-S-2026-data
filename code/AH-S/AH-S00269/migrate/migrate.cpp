#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+10;
ll C,T;
ll n,d,a[N],dp[N];
ll pre,now,ans;
void solve(){
	ans=0;
	now=1;
	pre=0;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=2;i<=n;i++){
		now++;
		if(a[i]-a[i-1]>d){
			now--;
			ans+=now*pre;
			pre=0;
			now=1;
		}
		else if(i>=3&&i<n&&a[i]-a[i-2]<=d&&a[i+1]-a[i-1]<=d&&a[i+1]-a[i-2]>d){
			ans+=now*pre;
			pre=max(now-2,1ll);
			now=0;
		}
	}
	ans+=now*pre;
	cout<<ans<<'\n';
}
void solve1(){
	ans=0;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		dp[i]=0;
		for(ll j=i+1;j<=n;j++){
			ll cnt=0,p=0x3f3f3f3f3f3f3f3f;
			for(ll k=j-1;k>=i&&a[j]-a[k]<=d;k--){
				if(dp[k]+1==p) cnt++;
				else if(dp[k]+1<p){
					p=dp[k]+1;
					cnt=1;
				}
			}
			if(cnt==2) ans++;
			dp[j]=p;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		if(n*n<=100000000) solve1();
		else solve();
	}
	return 0;
}
