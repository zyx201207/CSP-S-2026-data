#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,D,q;
struct stu{
	int p,w;
	bool operator< (const stu &h) const{
		return h.w < w;
	}
};
vector <pair<int,int> > g[21005];
int d[21005],ans[1005][1005],vis[21005];
int k[505],siz[500005],w[500005];
void dij(int st){
	priority_queue <stu> q;
	q.push({st,0});
	memset(vis,0,sizeof vis);
	memset(d,0x3f,sizeof d);
	d[st] = 0;
	while(!q.empty()){
		stu f = q.top();
		q.pop();
		if(vis[f.p] == 1) continue;
		vis[f.p] = 1;
		for(auto tp : g[f.p]){
			int v = tp.first,w = tp.second;
			if(d[f.p]+w < d[v]){
				d[v] = d[f.p]+w;
				q.push({v,d[v]});
			}
		}
	}
	for(int i = 1;i <= m;i++) ans[st][i] = d[i];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> D >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		int la,lt;
		for(int j = 1;j <= k[i];j++){
			int u,t;
			cin >> u >> t;
			if(j != 1){
				if(j == 2) siz[la]++;
				siz[u]++;
				g[la+m*siz[la]].push_back({u+siz[u]*m,0});
				g[la+m*siz[la]].push_back({u,t});
				g[la].push_back({u+siz[u]*m,lt});
				g[la].push_back({u,lt+t});
				
				g[u+siz[u]*m].push_back({la+m*siz[la],0});
				g[u].push_back({la+m*siz[la],t});
				g[u+siz[u]*m].push_back({la,lt});
				g[u].push_back({la,lt+t});
			}
			la = u,lt = t;
		}
	}
	for(int i = 1;i <= m;i++){
		dij(i);
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << w[x]+ans[x][y]+w[y] << "\n"; 
	}
	return 0;
}
