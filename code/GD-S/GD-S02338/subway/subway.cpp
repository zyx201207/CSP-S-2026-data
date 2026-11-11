#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,ll>> g[500010];
int c,n,m,d,q,k;
ll w[500010],a[500010],t[500010],dist[500010];
void bfs(int s,int t){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	for (int i = 1;i <= m;i++)
		dist[i] = 1e18;
	q.push({0,s});
	dist[s] = 0;
	while (q.size()){
		auto t = q.top();
		int u = t.second;
		q.pop();
		for (auto t : g[u]){
			int v = t.first;
			ll w = t.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				q.push({dist[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for (int i = 1;i <= m;i++)
		cin>>w[i];
	while (n--){
		cin>>k;
		for (int i = 1;i <= k;i++)
			cin>>a[i]>>t[i];
		for (int i = 1;i <= k;i++)
			for (int j = i + 1;j <= k;j++){
				g[a[i]].push_back({a[j],t[i] + t[j]});
				g[a[j]].push_back({a[i],t[i] + t[j]});
			}
	}
	while (q--){
		int s,t;
		cin>>s>>t;
		bfs(s,t);
		cout<<dist[t] + w[s] + w[t]<<'\n';
	}
	return 0;
}

