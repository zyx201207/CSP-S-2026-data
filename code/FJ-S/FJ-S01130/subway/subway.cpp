#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
constexpr int N=505,M=5e5+5;
int c,n,m,d,q,a[M];
int dis[N][N];
bool vis[N];
vector<pii> stage[M],G[N];

void dijkstra(int S){
	memset(dis[S],0x7f,sizeof dis[S]);
	memset(vis,false,sizeof vis);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({dis[S][S]=0,S});
	while(!pq.empty()){
		int u=pq.top().se; pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto nxt:G[u])
			if(!vis[nxt.fi] && dis[S][nxt.fi]>dis[S][u]+nxt.se)
				pq.push({dis[S][nxt.fi]=dis[S][u]+nxt.se,nxt.fi});
	}
	return;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> a[i];
	for(int i=1,K;i<=n;i++){
		cin >> K;
		for(int j=1,b,t;j<=K;j++)
			cin >> b >> t,stage[b].push_back({i,t});
	}
	for(int i=1;i<=m;i++){
		for(auto st1:stage[i])
			for(auto st2:stage[i])
				if(st1.fi!=st2.fi)
					G[st1.fi].push_back({st2.fi,st1.se+st2.se});
	}
	for(int i=1;i<=n;i++)
		dijkstra(i);
	while(q--){
		int u,v,ans=1e14; cin >> u >> v;
		for(auto i:stage[u])
			for(auto j:stage[v])
				ans=min(ans,dis[i.fi][j.fi]+i.se+j.se);
		cout << ans+a[u]+a[v] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
