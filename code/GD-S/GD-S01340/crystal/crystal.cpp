#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5*1e5+10;
ll m,n,a[N],ans;
bool check(ll x){
	ll temp=0;
	for(ll i=1;i<x;i++){
		temp+=(a[x]-a[i]);
	}
	if(temp>m){
		return false;
	}else{
		return true;
	}
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
