#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],p[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(ll i=1;i<=n;i++){
		p[i]=p[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(ll i=1;i<=n;i++){
		ll l=i,r=n;
		while(l<r){
			ll mid=l+(r-l+1)/2;
			if(p[mid]-p[i]-(a[mid]-a[i])*(i-1)>m)r=mid-1;
			else l=mid;
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
}
