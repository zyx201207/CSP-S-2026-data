#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[500005];
vector<ll>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(m == 1)cout << n;
	else if(n<=500&&m<=200){
		ll l=1;
		for(ll i = 1;i<=n;i++){
			for(ll j = i;j<=n;j++)s.push_back(a[i]);
			for(ll j = 1;j<=m;j++){
				for(ll z = i;z<=n;z++){
					if(b[z]==j)
				}
			}
		}
	}
	else if(n<=500&&m<=200){
		
	}
	return 0;
}
