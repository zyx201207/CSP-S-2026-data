#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[511111],sum[511111];
vector<ll>g[555555];
bool cmp(ll a,ll b){
	return a<b;
}
ll rf(ll l,ll r){
	//cout<<"@!1111";
	ll k1=l;
	ll cntt=1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if((mid-k1+1)*(a[mid])-(sum[mid]-sum[k1-1])<=m){
			//cout<<k1<<"    "<<mid<<"     "<<mid-k1+1<<"     "<<a[mid]-a[k1]<<"     "<<sum[mid]<<" "<<sum[k1-1]<<"     "<<(mid-k1+1)*(a[mid]-a[k1])-(sum[mid]-sum[k1-1])<<"     !!!!!!!!!!!!!!";
			cntt=mid;
			l=mid+1;
		}else r=mid-1;
	}
	//cout<<cntt<<"!!!!!!!!!!!";
	return cntt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	//cout<<n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=0;
	if(n<0){//!!!!!!!!!!!!!!!!!!!!!
		ll d=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m-d*i>=0)ans++;
			else break;
		}
		cout<<ans;
	}else{
		ll maxx=1;
		//cout<<n;
		for(int i=1;i<=n;i++){
			//cout<<"ASFDAS";
			ll oo=rf(i,n)-i+1;
			maxx=max(maxx,oo);
		}
		cout<<maxx;
	}
	return 0;
} 
