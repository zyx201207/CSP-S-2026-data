#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500100],c[500100],d[500100],ma=-10;
//Oct31==Dec25?
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
//	l--r
//	-(l-1)*(a[r]-a[l])-c[l]
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[1]=0ll;
	for(ll i=2;i<=n;i++){
		c[i]=(i-1)*(a[i]-a[i-1])+c[i-1];
	}
	ll l=1ll,r=1ll;
	while(l<=r && r<=n){
		while(c[r]-(l-1)*(a[r]-a[l])-c[l]>m && l<=n){
			l++;
		}
		ma=max(r-l+1ll,ma);
		r++;
	}
	cout<<ma;
	return 0;
} 
