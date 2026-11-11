#include <bits/stdc++.h>
using namespace std;
const int N=505;
using ll = long long;
using pll = pair<ll,ll>;
int t,d,vis[N];
ll n , m , q , w[N],v[N] , dist[N];
struct as{;
	ll s,v;
}a[N];
vector<pll> p[N];
ll dfs(int s, int e) {
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	priority_queue<pll,vector<pll>,greater<pll>> p1;
	p1.push({0,s});
	while(!p1.empty()) {
		auto u=p1.top();
		p1.pop();
		ll u1=u.second;
		if(vis[u1]) continue;
		vis[u1]=1;
		for(auto e:p[u1]) {
			int t1=e.first;
			ll w1=e.second;
			if(dist[t1]>dist[u1]+w1) {
				dist[t1]=dist[u1]+w1;
				p1.push({dist[t1],t1});
			} 
		} 
	}
	return dist[e];
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++) {
		cin>>w[i];
	}
	for(int i = 1; i <= n; i++) {
		ll k;
		cin>>k;
		for(int j = 1; j <= k; j++) {
			cin>>a[j].s>>a[j].v;
		}
		for(int j = 2; j <= k; j++) {
			p[a[j-1].s].push_back({a[j].s,a[j-1].v});
		}
	}
	for(int i = 1; i <= q; i++) {
		int l , r;
		cin>>l>>r;
		ll sum=w[l]+w[r];
		sum+=dfs(l,r);
		cout << sum << '\n';
	}
	return 0;
}
