#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,m;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ll maxx=-1e18;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	if(m==n-1){
		ll maxx=-1e18;
		for(int i=1;i<=n;i++){
			if(i==1){
				ll ans=a[2];
				for(int j=3;j<=n;j++){
					ans=ans&[j];
				}
			}
			else {
				ll ans=a[1];
				for(int j=1;j<=n;j++){
					if(j!=i){
						ans=ans&a[j];
					}
				}
			}
			maxx=max(maxx,ans;)
		}
		cout<<maxx;
	}
	if(m==n-1){
		ll maxx=-1e18;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
		}
		cout<<maxx;
	}
	return 0;
}
