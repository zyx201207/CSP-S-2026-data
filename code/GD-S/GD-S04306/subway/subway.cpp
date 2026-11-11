// subway
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define piii pair<int,pii>
using namespace std;
const int N = 1007;
const int INF = 1e18;
int c,n,m,d,q,w[N],k[N];
int num1[N][N],num2[N][N];
inline int dij(int u,int v,int n){
	int dis[N][n + 1] = {};
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			dis[i][j] = INF;
		}
	}
	bool vis[N][n + 1] = {};
	priority_queue<piii,vector<piii>,greater<piii>> pq;
	for(int i = 1;i <= n;i++) pq.push({0,{u,i}});
	while(pq.size()){
		int dist = pq.top().first; // 距离 
		int nxt = pq.top().second.first;
		int f = pq.top().second.second;
		pq.pop();
		cout << dist << ' ' << nxt << ' ' << f << endl;
		if(vis[nxt][f]) continue;
		vis[nxt][f] = true;
		for(int i = 1;i <= k[f];i++){
			int x = num1[f][i]; // 当前的值
			if(num2[f][x] + dist < dis[f][x]){
				dis[f][x] = num2[f][x] + dist;
				pq.push({dis[f][x],{x,i}});
			}
		}
		for(int j = 1;j <= n;j++){
			for(int i = 1;i <= k[j];i++){
				int x = num1[j][i];
				if(num2[j][x] + dist < dis[j][x]){
					dis[j][x] = num2[f][x] + dist;
					pq.push({dis[j][x],{x,j}});
				}
			}
		}
		cout << endl << endl;
	}
	int mn = INF;
	for(int i = 1;i <= n;i++) mn = min(mn,dis[v][i]);
	return mn;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++) cin >> num1[i][j] >> num2[i][j];
//		for(int j = 1;j <= k[i];j++) if()
	}
	while(q--){
		int u,v; cin >> u >> v;
		cout << dij(u,v,n) << endl;
	}
	return 0; 
}
