#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+5;
int c , T;
int n , k;
vector<int> e[N];
int dep[N] , f[N][25];
bool vis[N];
void dfs(int u,int fa){
	dep[u] = dep[fa]+1 , f[u][0] = fa;
	for(auto x : e[u])
		if( x != fa )
			dfs( x, u); 
} 
void bfs(int st,int ck){
	queue<int> q;
	q.push(st);
	vis[st] = true;
	while( !q.empty() ){
		int x = q.front(); q.pop();
		for(auto u : e[x]){
			if( (ck>>(u-1))&1 && !vis[u] ){
				q.push(u);
				vis[u] = true;
			}
		}
	}
}
int lca(int a,int b){
	if( dep[a] < dep[b] ) swap(a,b);
	for(int j = 22;j >= 0;j--)
		if( dep[ f[a][j] ] >= dep[b] ) a = f[a][j];
	if( a == b ) return a;
	for(int j = 22;j >= 0;j--)
		if( dep[f[a][j]] != dep[f[b][j]] )
			a = f[a][j] , b = f[b][j];
	return f[a][0];
}
int dis(int a,int b){
	return dep[a]+dep[b]-dep[lca(a,b)]*2;
}
bool check(int s){
	for(int i = 1;i <= n;i++) vis[i] = 0;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if( (s>>(i-1))&1 && !vis[i] ){
			++cnt;
			bfs( i , s ); 
		}
	}
	return cnt <= 2;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	
	cin >> c >> T;
	while( T-- ){
		cin >> n >> k;
		for(int i = 1;i <= n;i++) e[i].clear();
		for(int i = 1,u,v;i < n;i++){
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		for(int j = 1;j <= 22;j++)
			for(int i = 1;i <= n;i++)
				f[i][j] = f[ f[i][j-1] ][j-1];
		
		int minn = INT_MAX;
		for(int s = 1;s < (1<<n);s++){
			vector<int> in;
			for(int j = 1;j <= n;j++) if( (s>>(j-1))&1 ) in.push_back(j);
			if( check(s) && in.size() == k ){
				int ans = 0;
				for(int i = 1;i <= n;i++){
					if( !( (s>>(i-1))&1 ) ){
						int ppm = INT_MAX;
						for(auto x : in ) ppm = min( ppm , dis(x,i) );
						ans = max( ans , ppm );
					}
				}
				minn = min( minn , ans);
			}
		}
		cout << minn <<'\n';
	}
	return 0;
}

