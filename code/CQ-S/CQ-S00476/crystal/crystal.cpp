#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=5e5+5;
ll n,m,a[N],c[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) c[i]=c[i-1]+a[i];
	for(ll i=1;i<=n;++i){
		ll l=1,r=i;
		while(l<r){
			ll mid=l+r>>1;
			if(a[i]*(i-mid+1)-(c[i]-c[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		if(i-r+1ll>ans) ans=i-r+1ll;
	}
	cout<<ans;
	return 0;
}
