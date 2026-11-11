#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=400+5;
vector<pair<ll,ll>> g[N];
struct stop{
	ll time_line[N];
	ll time_in_out;
}p[N];
ll st[N];
ll fl[N];
ll last;
ll ans;
ll num;
ll n,m;
ll d,q;
ll c;
signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	// ‰»Î
	for(int i=1;i<=m;i++){
		cin>>p[i].time_in_out;
	}
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=1;j<=num;j++){
			ll u,v,x;
			cin>>v>>x;
			if(i==1){
				u=v;
			}else{
				g[u].push_back({v,i});
				g[v].push_back({u,i});
			}
			p[v].time_line[i]=x;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st[i]>>fl[i];
	}
	//
	return 0;
}
