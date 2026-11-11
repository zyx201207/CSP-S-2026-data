#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=5e5+5;
ll n,m,ans=0;
ll a[N];
ll sn[N];

bool hf(ll l,ll r){
	ll x=sn[r]-sn[l-1];
	ll y=a[r]*(r-l+1);
	if(m>=y-x)return true;
	else return false;
}
ll ck(ll x){
	ll l=1,r=x,mid,ans=1;
	while(l<=r){
		mid=(l+r+1)/2;
		if(hf(mid,x)){
			r=mid-1;
			ans=max(ans,x-mid+1);
//			cout<<x<<' '<<mid<<'\n';
		}else{
			l=mid+1;
		}
	}
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		sn[i]=sn[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		ans=max(ans,ck(i));
	}
	cout<<ans<<'\n';
	
	return 0;
}
