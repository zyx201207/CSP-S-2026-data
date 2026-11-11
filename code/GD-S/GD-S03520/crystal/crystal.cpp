#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
ll a[500005],b[500005];
ll p;

ll solve(ll x){
	ll ans=0x3f3f3f3f;
	for(int i=x;i<=n;i++){
		ll k=b[i-1]-b[i-x];
		k+=1LL*(x-1)*a[i];
		ans=min(ans,k);
	}
	return ans;
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
		b[i]=b[i-1]-a[i];
	}
	ll l=1,r=n;
	while(l<=r){
		ll mid=(r-l)/2+l;
		if(solve(mid)<=m){
			p=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<p;
	
	return 0;
}
