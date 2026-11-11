//GZ-S00056,彭翊瑄，北师大贵阳附中 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vl vector<ll>
#define pll pair<ll,ll>
#define fi first
#define se second
const int N=5e5+5;
vl g[N];
void dfs(ll u,ll f){
	for(auto &v:g[u]){
		if(v==f)continue;
		dfs(u,v);
	}
}
void ji(){
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vl w(m+1);
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		for(ll j=1;j<=x;j++){
			ll u,w;
			cin>>u>>w;
			g[j].push_back(u);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c;
	ll t=1;
	cin>>c>>t;
	while(t--){
		ji();
	}
	return 0;
} 
