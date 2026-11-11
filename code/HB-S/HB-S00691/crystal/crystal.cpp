#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[1000005],b[1000005],ma=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(ll i=1;i<=n;i++){
		ll s=0,t=1;
		for(ll j=i;j<=n;j++){
			if(s+b[j]*j>m){
				break;
			}else{
				s+=b[j]*j;
				t++;
			}
		}
		ma=max(t,ma);
	}
	cout<<ma;
	return 0;
}
