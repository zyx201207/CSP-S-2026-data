#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(5000>=n){
		sort(a+1,a+1+n);
		b[1]=-a[1];
		b[0]=0;
		for(ll i=2;i<=n;i++){
			b[i]=b[i-1]-a[i];
		}
		ll ans=0;
		for(ll i=2;i<=n;i++){
			for(ll j=1;j<i;j++){
				ll x=abs((i-j)*b[i]-(i-j+1)*b[i-1]+b[j-1]);
	//			cout<<x<<" "<<i<<" "<<j<<endl;
				if(x<=m){
					ans=max(ans,i-j+1);
				}					
				
			}
		}
		cout<<ans;
		return 0;		
	}if(5000<=n){
		ll gc=a[2]-a[1];
		double b=(-gc+sqrt(gc*gc+8*gc*(double)m))/(2*gc);
		ll ans=floor(b)+1;
		cout<<ans;
	}

	return 0;
}
