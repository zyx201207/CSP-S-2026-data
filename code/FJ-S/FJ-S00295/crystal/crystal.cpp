#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[5000005],ans,b=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			b=0;
			break;
		}
	}
//	if(b==1){
//		ll cnt=0,t=0;
//		for(ll j=n;j>0&&cnt<=m;j--){
//			if(cnt+a[n]-a[j]<=m) cnt+=a[n]-a[j],t++;
//			else break;
//		}
//		cout<<t;
//		return 0;
//	}
//	for(ll i=1;i<=n;i++){
//		ll cnt=0,t=0;
//		for(ll j=i;j>0&&cnt<=m;j--){
//			if(cnt+a[i]-a[j]<=m) cnt+=a[i]-a[j],t++;
//			else break;
//		}
//		ans=max(ans,t);
//	}
//	cout<<ans;
	ll l=n,r=n,t=0;
	while(0<r&&0<l){
		if(t<=m){
			ans=max(ans,r-l+1);
			l--;
			t+=a[r]-a[l];
		}else{
			t-=(r-l+1)*(a[r]-a[r-1]);
			r--;
		}
//		cout<<l<<r<<t<<endl;
	}
	cout<<ans;
	return 0;
}
