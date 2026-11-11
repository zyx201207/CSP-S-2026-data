#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	if(m==1){
		ll maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		ll maxx=a[1];
		for(int i=2;i<=n-1;i++){
			maxx=maxx&a[i];
		}
		cout<<max(maxx&a[1],maxx&a[n]);
		return 0;
	}
	for(ll i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
	return 0;
}
