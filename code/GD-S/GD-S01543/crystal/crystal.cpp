#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll N=6e5+10;
ll a[N];
ll n,m;
bool check(ll x){
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			sum+=abs(a[i]-x);
		}
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=-1e10,r=1e10;
	while(l<r){
		ll mid=(l+r)>>1;
		///cout<<l<<" "<<r<<"\n";
		if(check(mid)) {
			l=mid+1;
		}
		else r=mid;
	}
	ll cnt=0;
	//int k=lower_bound(a+1,a+n+1,l)
	for(ll i=1;i<=n;i++){
		if(a[i]<=l){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
