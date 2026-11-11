#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> adj[2000010];
int n,k;
bool vis[2000010];
int inD[2000010];
int dis1[2000010];
void topo(){
	queue<int> q;
	for(int i = 1;i <= n;i ++){
		if(inD[i] == 1){
			q.push(i);
		}
	}
	int cnt = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = true;
		cnt++;
		if(cnt == n-k) break;
		for(int v : adj[u]){
			inD[v]--;
			if(inD[v] == 1 && !vis[v])q.push(v);
		}
	}
}
void dfs1(int u,int fa,int dis){
	if(vis[u]) return ;
	for(int v : adj[u]){
		if(v == fa) continue;
		dis1[v] = dis+1;
		dfs1(v,u,dis+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1;i <= n;i ++){
			adj[i].clear();
//			cout << adj[i].size();
			inD[i] = 0;
			vis[i] = false;
			dis1[i] = 0;
		}
		for(int i = 1;i < n;i ++){
			int u,v,w;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			inD[u]++;
			inD[v]++;
		}
		topo();
		for(int i = 1;i <= n;i ++){
//			cout << vis[i] << ' ';
			if(!vis[i]){
				dfs1(i,0,0); 
//				break;
			} 
		}
//		cout << '\n';
		int Max = -1;
		int Maxpos = 0;
		int ans = -1;
		for(int i = 1;i <= n;i ++){
			if(Max < dis1[i]){
				Max = dis1[i];
				Maxpos = i;
			}
		}
		dfs1(Maxpos,0,0);
		for(int i = 1;i <= n;i ++){
			if(!vis[i])ans = max(ans,dis1[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
