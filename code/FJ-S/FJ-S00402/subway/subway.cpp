#include<bits/stdc++.h>
#define int long long
#define MAX_N 510
#define MAX_M  500010
#define inf LLONG_MAX
using namespace std;
int c,n,m,d,q;
struct Edge {
	int v,w;
};
int w[MAX_M];
int edge[MAX_N][MAX_N];
int dist_tracks[MAX_N][MAX_N];
vector<Edge> tracks[MAX_M];

struct Node {
	int ind,dis;
	const bool operator>(const Node x) const {
		return dis > x.dis;
	}
};
int vis[MAX_N],dist[MAX_N];
priority_queue<Node,vector<Node>,greater<Node>> que;
void dij(int s) {
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) {
		dist[i] = inf;
		if(i == s) dist[i] = 0;
	}
	while(!que.empty()) que.pop();
	que.push({s,0});
	while(!que.empty()) {
		int ind = que.top().ind;
		que.pop();
		if(vis[ind] == true) continue;
		vis[ind] = true;
		for(int i = 1;i<=n;i++) {
			if(edge[ind][i] == inf) continue;
			if(dist[ind] + edge[ind][i] < dist[i]) {
				dist[i] = dist[ind] + edge[ind][i];
				que.push({i,dist[i]});
			}
		}
	}
	for(int i=1;i<=n;i++) {
		dist_tracks[s][i] = dist[i];
	}
	return ;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(i!=j) edge[i][j] = inf;
			else edge[i][j] = 0;
		}
	}
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) {
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>a>>t;
			tracks[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++) {
		for(auto ex:tracks[i]) {
			for(auto ey:tracks[i]) {
				if(ex.v == ey.v) continue;
				edge[ex.v][ey.v] = min(edge[ex.v][ey.v],ex.w + ey.w);
				edge[ey.v][ex.v] = min(edge[ey.v][ex.v],ex.w + ey.w);
			}
		}
	}
	for(int i=1;i<=n;i++) {
		dij(i);
	}
	for(int i=1;i<=q;i++) {
		int qx,qy,ans = inf;
		cin>>qx>>qy;
		for(auto j:tracks[qx]) {
			for(auto k:tracks[qy]) {
				ans = min(ans,dist_tracks[j.v][k.v]+j.w+k.w);
			}
		}
		cout<<ans+w[qx]+w[qy]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
4th anniversary ~

*/
