#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
typedef long long ll;
ll a[N+5];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	ll n,m,mx=0,ans=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ans=max(ans,(a[i] & a[j]));
			}
		}
	}
	if(m==3){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					ans=max(ans,(a[i]&a[j])&a[k]);	
				}
			}
		}
	}
	if(m==4){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					for(ll t=k+1;t<=n;t++){
						ans=max(ans,a[i]&a[j]&a[k]&a[t]);	
					}
				}
			}
		}
	}
	if(m>4){
		sort(a+1,a+1+n);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
