#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(n) cout << #n << " = " << n << "\n";
#define deb(n) cout << #n << " = " << n << "    ";
#define div() cout << "\n---------------------\n";
int c,t;int n,d;
int a[2000005];
int dis[5005][5005];
int cnt[5005][5005];
vector<int>g[5005];
inline void dij(int st){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	bool vis[5005];memset(vis,0,sizeof(vis));
	q.push({0,st});
	dis[st][st] = 0;cnt[st][st] = 1;
	while(q.size()){
		int u = q.top().second;q.pop();
		if(vis[u]){continue;}
		vis[u] = 1;
		for(auto v : g[u]){
			if(dis[st][v] > dis[st][u]+1){
				dis[st][v] = dis[st][u]+1;
				cnt[st][v] = cnt[st][u];
				q.push({dis[st][v],v});
			}
			else if(dis[st][v] == dis[st][u]+1){
				cnt[st][v] += cnt[st][u];
			}
		}
	}
}
inline void work(){
	cin >> n >> d;int ans = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		g[i].clear();
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			dis[i][j] = 1e9;cnt[i][j] = 0;
			if(a[j]-a[i] <= d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		dij(i);
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(cnt[i][j] == 2){ans++;}
		}
	}
	cout << ans << "\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		work();
	}
	return 0;
}
