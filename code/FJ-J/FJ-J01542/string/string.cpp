#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
ll a[200010];
char c[200010];

ll ef(ll x){
	ll left=1,right=n,mid;
	while(left<right-1){
		mid=(left+right)/2;	
		if(a[mid]>x){
			right=mid;
		}else if(a[mid]<x){
			left=mid;
		}else if(a[mid]==x){
			return mid;
		}
	}
	return right;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]+=a[i-1];
	}
	for(ll last=1;last<=ef(a[n]/2);last++){
		ll sta=ef(a[n]+1-a[last]);
		ll end=ef(a[n]-a[last-1]);
//		cout<<sta<<' '<<end<<'\n';
		for(int j=sta+1;j<end;j++){
			if(c[j]!=c[last]){
				ans+=a[j];
			}
		}
		if(sta==end){
			if(c[sta]!=c[last]) ans+=a[last]-a[last-1];
		}else{
			if(c[sta]!=c[last]) {
				ans+=a[sta]-a[n]+a[last];
			}
			if(c[end]!=c[last]) {
				ans+=a[n]-a[last-1]-a[end-1];
			}
		}
	}
	cout<<ans;
	return 0;
}