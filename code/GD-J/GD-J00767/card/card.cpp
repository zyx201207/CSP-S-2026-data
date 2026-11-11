#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using arr=array<ll,2>;
const ll N=1e6+10;
ll n,a[N],m,b[N],r[N];
ll vis[N],d[N];
void solve(){
	cin>>n>>m;
	bool f=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=0;
	}
	if(f){
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			b[a[i]]=i;
		}
		for(ll i=1;i<=m;i++) cout<<b[i]<<" ";
		cout<<"\n";
	}else{
		for(ll i=1;i<=n;i++) for(ll j=i;j<=n;j++) b[a[j]]++;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++) vis[j]=0;
			for (ll j=1;j<=m;j++) d[j]=0;
			for(ll j=i;j<=n;j++){
				if(vis[a[j]]){
					for(ll x=vis[a[j]];x<=j-1;x++){
						if(!d[a[x]]){
							d[a[x]]=1;
							b[a[x]]--;
							vis[a[x]]=0;
							//cout<<a[x]<<" ";
						}
					}
					//cout<<"\n";
				}
				vis[a[j]]=j;
				d[a[j]]=0;
			}
		}
		for(ll i=1;i<=m;i++) cout<<b[i]<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//ll t;cin>>t;while(t--)
	solve();
	return 0;
}

