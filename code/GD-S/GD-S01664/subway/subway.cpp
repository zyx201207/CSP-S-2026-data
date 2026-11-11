#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 600005
#define fi first
#define se second
int c,n,m,d,q,w[N],s,t,ans,dis[N],inf=0x3f3f3f3f3f3f3f3f;
vector<pair<int,int> > e[N],g[N];
vector<int> cl;
void bfs(){
	priority_queue<pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int> > > p;
	for(int i = m+1;i <= n+m;i++){
		dis[i]=inf;
	}
	for(auto  v : e[s]){
		p.push({v.se,v.fi});
		dis[v.fi]=v.se;
	}
	while(!p.empty()){
		int u = p.top().se;
		p.pop();
		for(auto v : g[u]){
			if(dis[v.fi]>dis[u]+v.se){
				dis[v.fi]=dis[u]+v.se;
				p.push({dis[v.fi],v.fi});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
//	freopen("ans.out","w",stdout);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int a,t;
			cin >> a >> t;
			e[m+i].push_back({a,t});
			e[a].push_back({m+i,t});
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < e[i].size();j++){
			for(int k = 0;k < e[i].size();k++){
				if(j<k){
					g[e[i][j].fi].push_back({e[i][k].fi,e[i][j].se+e[i][k].se});
					g[e[i][k].fi].push_back({e[i][j].fi,e[i][j].se+e[i][k].se});
				}
			}
		}
	}
	while(q--){
		cin >> s >> t;
		bfs();
		int mn=inf;
		for(auto v : e[t]){
			mn=min(mn,dis[v.fi]+v.se);
		}
		cout << w[s]+w[t]+mn << endl;
	}
	return 0;
}
