#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],sum[N],l,r,ans; 
bool check(ll x){
	for(ll i=x;i<=n;i++){
		ll now=a[i];
		if((x-1)*now-(sum[i-1]-sum[i-x])<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i]; 
	l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
