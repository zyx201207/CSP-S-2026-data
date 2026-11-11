#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,d,a[2000005],b[2000005],ans;
void solve(){
	cin>>n>>d;
	ans=0;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(a[j]-a[i]>=d*2 or a[j]-a[i]<=d or *upper_bound(a+1,a+n+1,a[j]-d)<a[i]+d or j-i<=2) continue;
			ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
