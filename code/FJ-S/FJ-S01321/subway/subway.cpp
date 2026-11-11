#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 5e5 + 5;
const ll Q = 1005;
const ll INF = 1e18;

ll c,n,m,d,q;
ll w[N];
ll ans[Q][Q],dis[Q + 505],vis[Q + 505],dis2[N];
vector<pair<ll,ll> >G[N + 505];

void solve1(){
	for(int i = 1; i <= m; i++) cin >> w[i];
	ll x,v,val;
	for(int i = 1; i <= n; i++){
		cin >> x;
		for(int j = 1; j <= x; j++){
			cin >> v >> val;
			G[m + i].push_back(make_pair(v,val));
			G[v].push_back(make_pair(m + i,val));
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m + n; j++) dis[j] = INF;
		dis[i] = 0;vis[i] = 1;
		priority_queue<pair<ll,ll> >p; 
		p.push(make_pair(0,i));
		while(p.size()){
			pair<ll,ll> pp = p.top();
			p.pop();
			ll val = -pp.first,u = pp.second;
			for(auto g : G[u]){
				ll v = g.first,vall = g.second;
//				cout << u << "->" << v << ":"<<  vall << " " <<dis[v] << " " << dis[u] + vall << "\n";
				if(dis[v] > dis[u] + vall){
					dis[v] = min(dis[v],dis[u] + vall);
					p.push(make_pair(-dis[v],v));	
				}
			}
		}
		for(int j = 1; j <= m; j++) ans[i][j] = dis[j];
//		cout << i << "------------\n";
//		for(int j = 1; j <= m + n; j++) cout << dis[j] << " ";
//		cout << "\n";
//		cout << "------------------\n";
	}
	ll uu,vv;
	
	while(q--){
		cin >> uu >> vv;
		cout << ans[uu][vv] + w[uu] + w[vv] << "\n";
	}
	return;
}

void solve2(){
	for(int i = 1; i <= m; i++) cin >> w[i];
	ll x,v,val,t = 0;
	for(int i = 1; i <= n; i++){
		cin >> x;
		for(int j = 1; j <= x; j++){
			cin >> v >> val;
			t = val;
			G[m + i].push_back(make_pair(v,val));
			G[v].push_back(make_pair(m + i,val));
		}
	}
	ll uu,vv;
	while(q--){
		cin >> uu >> vv;
		for(int j = 1; j <= m + n; j++) dis2[j] = INF;
		dis2[uu] = 0;
		priority_queue<ll>p; 
		p.push(uu);
		while(p.size()){
			ll pp = p.top();
			p.pop();
			for(auto g : G[pp]){
//				cout << pp << "->" << v << "\n";
				ll v = g.first;
				if(dis2[v] > dis2[pp] +1){
					dis2[v] = min(dis2[v],dis2[pp] + 1);
					p.push(v);	
				}
			}
		}
		cout << dis2[vv] * t + w[uu] + w[vv] << "\n";
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	if(c <= 11 || c >= 20) solve1();
	else if(c <= 19 && c >= 12) {
		solve2();
	}
	return 0;
}
 
// warning:"==",全局变量,freopen,check_code
/*
regart the subway ronue as a false jiedian 
maybe we can't entrance all check

*/

