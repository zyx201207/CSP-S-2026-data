#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long
vector<ll>all,tmp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		all.push_back(x);
	}
	ll ans=0;
	for(ll i=33;i>=0;i--){
		ll cnt=0;
		tmp.clear();
		for(ll j=0;j<all.size();j++){
			ll k=all[j];
			if((k>>i)&1){
				cnt++;
				tmp.push_back(k);
			}
		}
		if(cnt>=m){
			all=tmp;
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
