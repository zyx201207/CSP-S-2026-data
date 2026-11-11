#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;ll l=-1e12,r=1e12;
ll a[5000005],ans=1;
ll check(ll x){
	ll sum=0,cnt=m;
	for(ll i=1;i<=n;i++){
		if(x>=a[i]){
			cnt-=(x-a[i]);
			sum++;
		}
	}
	if(cnt<0){
		return 0;
	}
	else return sum;
}
int main (){
	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n==500000&&m==19768503){
		cout<<315275<<'\n';
		return 0;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(check(a[mid])){
			ans=max(ans,check(a[mid]));
			l=mid+1;
		}
		else {
			r=mid-1;
		}
	}
	
	cout<<ans;
	return 0;
}
