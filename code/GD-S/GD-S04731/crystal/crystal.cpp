#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N],d[N];
ll n,m;
ll check(ll x){
	ll l=1,r=x,zh=0;
	for(ll i=2;i<=r;i++){
		zh+=d[i]*(i-1);
	}
	if(zh<=m)return 1;
	while(r<=n){
		zh-=(a[r]-a[l]);
		r++;
		l++;
		zh+=d[r]*(x-1);
		if(zh<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	ll l=1,r=n,mid,ans=1;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	
	return 0;
} 
