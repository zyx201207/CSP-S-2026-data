#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define N 500005
vector<int> e[N];
int d[N], p[N], n, k;
bool vis[N], V[N];
int s[N], ans = 1e9;
int find(int x){
	if(p[x]!=x){
		return p[x] = find(p[x]);
	}
	return x;
}
void bfs(){
	int temp = 0;
	for(int i = 1;i <= n;i++){
		queue<int> q;
		for(int i = 1;i <= n;i++)d[i] = 0x3f3f3f3f;
		//for(int i = 1;i <= k;i++)d[s[i]] = 0;
		bool is = 0;
		for(int j = 1;j <= k;j++){
			if(i==s[j])is=1;
		}
		if(is)continue;
		d[i] = 0;
		q.push(i);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int v:e[u]){
				if(d[u]+1<d[v]){
					d[v]=d[u]+1;
					q.push(v);
				}
			}
		}
		int tmp = 1e9;
		for(int j = 1;j <= k;j++){
			tmp = min(tmp, d[s[j]]);
		}
		
		temp = max(tmp, temp);
		
	}
	ans = min(ans, temp);
}
void dfs(int step){
	if(step < k){
		for(int i = 1;i <= n;i++){
			if(!vis[i]){
				s[step+1] = i;
				vis[i] = 1;
				dfs(step+1);
				vis[i] = 0;
			}
		}
		return ;
	}
	for(int i = 1;i <= n;i++)V[i] = 0;
	int cnt = 0;
	for(int i = 1;i <= k;i++){
		int fa = find(s[i]);
		if(!V[fa])cnt++;
		V[fa]=1;
	}
	if(cnt > 2)return ;
	bfs();
} 
void init(){
	ans = 1e9;
	for(int i = 1;i <= n;i++){
		e[i].clear();
		p[i]=i;
	}
	for(int i = 1;i <= k;i++)s[i]=0;
	for(int i = 1;i <= n;i++)vis[i]=0;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		init();
		
		for(int i = 1;i < n;i++){
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
			p[u] = v;
		}
		dfs(0);
		cout << ans << endl;
	}
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
