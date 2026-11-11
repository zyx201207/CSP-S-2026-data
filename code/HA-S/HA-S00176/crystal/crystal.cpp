#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll da,n,m,a[500005],sum[500005],maxm=-0x3fffffff;
bool check(ll x){
	for(int i=x;i<=n;++i){
//		if(1.0*(sum[i]-sum[i-x])/x+1.0*m/x-(sum[i]-sum[i-x])/x+m/x>=0.5){
//			ll z=ceil(1.0*(sum[i]-sum[i-x])/x+1.0*m/x);
//			if(z>=a[i]) return true;
//		}else{
//			ll z=1.0*(sum[i]-sum[i-x])/x+1.0*m/x;
//			
//		}
		ll z=(sum[i]-sum[i-x]+m)/x; 
		if(z>=a[i]) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			da=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<da;
	return 0;
}

