#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=6*1e5;
ll c[N];
ll s[N];
ll n,m;

ll bs(ll x){
	ll l,r,mid;
	l=0,r=x-1,mid=(l+r)/2;
	while(l<r){
		mid=(l+r)/2;
		if((x-mid)*c[x]-(s[x]-s[mid])<=m){
			r=mid;
		}
		else l=mid+1;
	}
	return l;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans=max(ans,i-bs(i));
	}
	cout<<ans<<endl;
	return 0;
}
