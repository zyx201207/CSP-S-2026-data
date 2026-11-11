#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll p[500005];
bool k(ll x){
	for(int i=x;i<=n;i++){
		ll t=(x-1)*a[i]-(p[i-1]-p[i-x]);
		if(t<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
	}
	ll l=1,r=n+1;
	while(l<r){
		ll mid=(l+r)/2;
		if(k(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<r-1;
	return 0;
}
