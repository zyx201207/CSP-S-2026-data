#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int N=5e5+10;
ll a[N],sum[N];
bool check(ll x){
	ll ret=1e18+10;
	for(ll i=x;i<=n;i++){
		ret=min(a[i]*x-(sum[i]-sum[i-x]),ret);
	}
//	cout<<x<<" "<<ret;
	return ret<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=n,ans=-1;
	while(l<=r){
		ll mid=(l+r)>>1;
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
