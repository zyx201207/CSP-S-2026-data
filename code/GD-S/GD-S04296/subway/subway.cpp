#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 5e5+9,INF = 1e18;
int c,n,m,d,q;
int w[N];
vector<pii> g[N];
vector<pii> st[N];
int dis[N];
int solve(int x,int y){
	fill(dis+1,dis+m+1,INF);
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({w[x],x});
	dis[x] = w[x];
	while(q.size()){
		pii now = q.top();q.pop();
		int u = now.second,d = now.first;
		for(pii it : st[u]){
			int cost = it.second,sub = it.first;
			for(pii at : g[sub]){
				int v = at.first,fee = at.second;
				if(v == u) continue;
				if(dis[v] > d + cost + fee){
					dis[v] = d + cost + fee;
					q.push({dis[v],v});
				}
			}
		}
	}
	return dis[y] + w[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1,k;i <= n;i++){
		cin>>k;
		for(int j = 1;j <= k;j++){
			int a,t;cin>>a>>t;
			st[a].push_back({i,t});
			g[i].push_back({a,t});
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		cout<<solve(x,y)<<"\n";
	}
	return 0;
}
