#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll a[N];
ll n,m;
int check(ll x){
	ll t=m;
	ll cnt=0;
	for(int i=n;i>=1;i--){
		if(a[i]>x){
			continue;
		}else{
			t-=(x-a[i]);
			if(t<0){
				return cnt;
			}
			cnt++;
		}
	}
	return cnt;
	
}
void solve(){
	sort(a+1,a+n+1);
	ll ans=0;
	for(ll i=1;i<=a[n]+m;i++){
		if(check(i)>ans){
			ans=check(i);
		}
	}
	cout<<ans;
}

void solve1(){
	map<ll,ll> mp;
	mp[1]=0;
	for(int i=2;i<=n;i++){
		mp[i]=mp[i-1]+i-1;
		if(mp[i]>m) {
			cout<<i-1;
			return ;
		}
	}
	
}void solve2(){
	map<ll,ll> mp;
	mp[1]=0;
	ll ret=a[2]-a[1];
	for(int i=2;i<=n;i++){
		mp[i]=mp[i-1]+1LL*(i-1)*ret;
		if(mp[i]>m) {
			cout<<i-1;
			return ;
		}
	}
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool f=0;
	bool ff=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=1;
		}
	}
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])!=(a[2]-a[1])){
			ff=1;
		}
	}
	if(!f){
		solve1();
	}else if(!ff){
		
		solve2();
	}else{
		
		solve();
	}
	
	return 0;
}
