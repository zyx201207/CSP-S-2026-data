#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll s[500005];
ll mm[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=0;i<n;i++){
		for(ll j=1;j<=n;j++) s[j]=0;
		ll x=1;
		ll ans=0;
		for(ll j=i;j<=n;j++){
			ll t=lower_bound(s+1,s+x,a[j])-s;
			if(t==a[j]){
				for(ll k=t;k<=x;k++) s[k]=0;
				x=t;
				a[t]=a[j];
			}else{
				s[x]=a[j];
				x++;
			}
			for(ll k=1;k<=m;k++){
				ll t2=lower_bound(s+1,s+x,k)-s;
				if(t2==k) mm[k]++;
			}
		}
	}
	for(ll i=1;i<=m;i++)cout<<mm[i]<<" ";
	return 0;
}