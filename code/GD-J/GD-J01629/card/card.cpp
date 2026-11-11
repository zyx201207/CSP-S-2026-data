#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m;
ll a[1000100];
ll cnt[1000100];
vector<ll> vt;
ll find(ll x){
	for(ll i=0;i<vt.size();i++){
		if(vt[i]==x)return i;
	}
	return -1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(vt.size()==0){
				vt.push_back(a[j]);
				continue;
			}
			ll x=find(a[j]);
			if(x==-1){
				vt.push_back(a[j]);
			}
			else {
				ll t=vt.size()-x;
				while(t--)vt.pop_back();
				vt.push_back(a[j]);
			}
		}
		for(auto c:vt){
			cnt[c]++;
		}
		vt.clear();
	}
	for(ll i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
