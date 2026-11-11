#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxn=5e5+10;
ll n,m,a[maxn],ans,sum[maxn];
bool check(ll shu){
	for(ll i=n;i>=shu;i--){
		if(a[i]*(shu-1)-(sum[i]-sum[i-shu]-a[i])<=m) return 1;
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
	sort(a,a+n);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
	
}
