#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		vector <ll> v;
		for(ll j=i;j<=n;j++){
			ll x = a[j];
			vector <ll> v1;
			for(ll k=0;k<v.size();k++){
				if(v[k] == x){
					break;
				}
				v1.push_back(v[k]);
			}
			v = v1;
			v.push_back(x);
		}
		for(ll j=0;j<v.size();j++){
			t[v[j]] ++ ;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
