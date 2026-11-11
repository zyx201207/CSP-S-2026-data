#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll c,n,m,d,q;
ll w[1000100];
ll k[1000100];
pair<ll,ll> mnst[1000100];    //1时间 2第几条线 
vector<pair<ll,ll>> g[1000100]; //g[i][j]  第i条路第j个站 

void solve(){
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1;i<=m;i++){
		cin >> w[i];
	} 
	for(ll i = 1;i<=n;i++){
		cin >> k[i];
		for(ll j = 1;j<=k[i];j++){
			ll a,t;cin >> a >> t;
			g[i].push_back({a,t});
			if(mnst[a].first>t){
				mnst[a].first = t;
				mnst[a].second = i;
			}
		}
	}
	while(q--){
		ll x,y;cin >> x >> y;
		ll sum = 0;
		sum += mnst[x].first;
		sum += mnst[x].second;
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	return 0;
}   
