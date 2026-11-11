#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[1000100],vis[1000100],dp[1000100],b[1000100],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(m==2){
		ll ans;
		for(ll i=1;i<=n;i++)if(a[i]==1)ans++;
		cout<<ans<<n-ans;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		//cout<<i;
		if(vis[a[i]]==0)vis[a[i]]=1,b[t]=a[i],t++;
		else {
			t--;
			while(b[t]!=a[i]){
				//cout<<b[t];
				vis[b[t]]==0;
				b[t]=0;t--;
			}
			t++;
			//cout<<2;
		}
		for(ll j=1;j<=m;j++){
			//cout<<1;
			if(vis[j]>0)dp[j]++;
		}
	}
	//cout<<1;
	for(ll i=1;i<=n;i++){
		if(vis[i])cout<<dp[i]<<" ";
	}
	return 0;
}
