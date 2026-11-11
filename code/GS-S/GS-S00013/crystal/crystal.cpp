#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
unsigned ll m;
ll a[500010];
bool check(ll x){
	ll cnt=m;
	for(int i=1;i<=n;i++){
		if(x>=a[i]){
			cnt-=x-a[i];
			if(cnt<0){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool B=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll maxa=a[1],mina=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>maxa)maxa=a[i];
		if(a[i]<mina)mina=a[i];
	}
	ll z=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=z){
			B=0;
			break;
		}
	}
	if(B){
		ll k;
		for(k=1;k*(k+1)/2*z<=m;k++);
		cout<<k;
		return 0;
	}
	ll l=mina,r=maxa;
	ll ans=-1;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
			ll cnt=0;
			for(int i=1;i<=n;i++){
				if(mid>=a[i]){
					cnt++;
				}
			}
			ans=max(ans,cnt);
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
