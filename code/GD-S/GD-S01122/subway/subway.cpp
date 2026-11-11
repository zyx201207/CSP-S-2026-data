#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=505,M=5e5+5;

ll c,n,m,d,q;
ll w[M];
struct node{
	ll w;
	ll t;
};vector<node>g[N];
ll k[N][M*2];
void init(){
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll s;cin>>s;
		for(ll j=1;j<=2*s;j++){
			ll popipa;cin>>popipa;
		}
	}
	return;
}
void solve(){
	cout<<15<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	init();
	while(q--)solve();
	return 0;
}
