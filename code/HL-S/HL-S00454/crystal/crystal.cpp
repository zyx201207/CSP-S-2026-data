#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int maxn = 5e5+10 ;
ll a[maxn],s[maxn] ;
bool cmp(ll x,ll y){
	return x>y ;
}
int main(){
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0),cout.tie(0) ;
	ll n,m,gc ; cin>>n>>m ;
	bool check_B=1 ;
	for(int i=1;i<=n;i++){
		cin>>a[i] ;
	}
	sort(a+1,a+n+1,cmp) ;
	gc=a[1]-a[2] ;
	for(int i=1;i<n;i++){
		if(a[i]-a[i+1]!=gc){
			check_B=0 ;
		}
	}
	if(check_B){
		ll cnt=0,ssum=0 ;
		for(int i=1;i<=n;i++){
			if(ssum<=m){
				ssum+=gc*i ;
				cnt++ ;
			}
		}
		cout<<cnt ;
		return 0 ;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i] ;
	}
	ll ans=-1 ;
	for(int i=1;i<=n;i++){
		if(a[i]*(n-i)-(s[n]-s[i])<=m){
			ans=max(ans,n-i+1) ;
		}
	}
	cout<<ans ;
	return 0 ;
}