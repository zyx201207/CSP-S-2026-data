#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e12+5;
ll n,m;
ll a[500005];
ll sum[500005];
bool check(int mid){
	for(int i=mid;i<=n;i++){
		if(((sum[i]-sum[i-mid])-((i-mid)*(a[i]-a[i-mid])))<=m){
			return true;
		}
	}
	return false;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ll x=0;
		x=a[i]-a[i-1];
		sum[i]=sum[i-1]+(i-1)*x;
	}
	ll l=0,r=n+1;
	while(l<r){
		ll mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else {
			r=mid-1;
		}
	}
	cout<<l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
