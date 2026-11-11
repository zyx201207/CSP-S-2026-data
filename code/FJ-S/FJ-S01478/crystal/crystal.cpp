#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=5e5+10;
ll a[N];
ll s[N];
ll n,m;
ll val(ll l,ll r){
	return a[r]*(r-l+1)-s[r]+s[l-1];
}
ll find(ll x){
	ll l=1,r=x;
	ll best=-1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(val(mid,x)<=m){
			best=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return best;
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
		s[i]=s[i-1]+a[i];
	}
	ll mx=0;
	for(ll i=1;i<=n;i++){
		ll ans=find(i);
		if(ans!=-1){
			mx=max(i-ans+1,mx);
		} 
	}
	cout<<mx;
	return 0;
}
