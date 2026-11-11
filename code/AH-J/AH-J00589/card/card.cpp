#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+20;
ll n,m;
ll a[N];
vector<ll>v;
ll ans;
bool found(ll a){
	for(ll i=0;i<(ll)v.size();i++){
		if(v[i]==a)return true;
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v.clear();
		for(int j=i;j<=n;j++){
			if(!found(a[j])){
				v.push_back(a[j]);
			}else{
				ll x;
				for(ll k=0;k<(ll)v.size();k++){
					if(v[i]==a[j]){
						x=k;
						break;
					}
				}
				ll y=v.size()-x;
				while(y--){
					v.pop_back();
				}
			}
			if(found(i))ans++;
		}
	}
	cout<<ans;
	return 0;
}
