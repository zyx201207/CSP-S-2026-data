#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int fa[N];
vector<int> g[N];
int vis[N],vis2[N];
int n,k,ans = 0;

void init(){
	for(int i = 1;i < N;i ++){
		fa[i] = i;
	}
}

int get(int x){
	if(fa[x] == x){
		return x;
	} else {
		return fa[x] = get(fa[x]);
	}
}

void merge(int u,int v,vector<pair<int,int> > &fy){
	fy.push_back({get(u),fa[get(u)]});
	fa[get(u)] = get(v);
}

bool check(){
	memset(vis2,0,sizeof vis2);
	int cnt = 0;
	for(int i = 1;i <= n;i ++){
		if(vis[i]){
			if(!vis2[get(i)]){
				vis2[get(i)] = 1;
				cnt ++;
			}
		}
	}
	if(cnt > 2) return 0;
	else return 1;
}

int dfs2(int x,int p,int st){
	if(vis[x]) return st;
	int bans = 1e9;
	for(auto it : g[x]){
		if(it == p) continue;
		bans = min(bans,dfs2(it,x,st + 1));
	}
	return bans;
}

int getans(){
	int bans = 0;
	for(int i = 1;i <= n;i ++){
		bans = max(bans,dfs2(i,0,0)); 
	}
	return bans;
}

void dfs(int u,int cnt){
	vector<pair<int,int> > fy;
	if((n - u + 1) + cnt < k) return ;
	fy.clear();
	if(cnt == k){
		if(check()){
			ans = min(ans,getans());
		}
		return ;
	}
	vis[u] = 1;
	for(auto v : g[u]){
		if(vis[v]){
			merge(u,v,fy);
		}
	}
	dfs(u + 1,cnt + 1);
	vis[u] = 0;
	for(auto it : fy){
		fa[it.first] = it.second;
	}
	dfs(u + 1,cnt);
	return ;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t --){
		cin >> n >> k;
		init();
		ans = 1e9;
		for(int i = 1;i <= n;i ++){
			g[i].clear();
		}
		memset(vis,0,sizeof vis);
		for(int i = 1;i < n;i ++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		cout << ans << '\n';
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
