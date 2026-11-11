#include<bits/stdc++.h>
#define int long long
using namespace std;
#ifdef SPPPP__
const int N=501,M=5e5+10,inf=1e18;
#endif
#ifndef SPPPP_
const int N=501,M=4e5+10,inf=1e18;
#endif
int c,n,m,d,q,ds[N][M+N],w[N+1];
struct node{
	int v,w;
};
vector<node> g[N+M];
priority_queue<node> qe;
bool operator< (node a, node b){
	return a.w > b.w;
}

void djsk(int st){
	for (int i=1;i<=n+m;++i) ds[st][i] = inf;
	ds[st][m+st] = 0;
	qe.push({m+st,0});
	while(!qe.empty()){
		int dss = qe.top().w,u = qe.top().v;qe.pop();
		if (dss > ds[st][u]) continue;
		for (node a: g[u]){
			int v = a.v,dis = a.w;
			if (ds[st][v] > ds[st][u]+dis){
				ds[st][v] = ds[st][u] + dis;
				qe.push({v,ds[st][v]});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;++i) cin >> w[i];
	for (int i=1,k;i<=n;++i){
		cin >> k;
		int u=m+i,v,w;
		for (int j=1;j<=k;++j){
			cin >> v >> w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
	}
	for (int i=1;i<=n;++i){
		djsk(i);
	}
	for (int i=1,x,y;i<=q;++i){
		cin >> x >> y;
		int ans = ds[1][x]+ds[1][y];
		for (int i=2;i<=n;++i){
			ans = min(ds[i][x]+ds[i][y],ans);
		}
		cout << ans+w[x]+w[y] << '\n';
	}
	return 0;
}
//RP++
