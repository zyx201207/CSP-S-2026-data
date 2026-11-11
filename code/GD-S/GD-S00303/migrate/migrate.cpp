#include<bits/stdc++.h>
#define int long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;
const int N = 5050;
int c, t;
int a[N];
vector<int> ed[N];
int dist[N][N], cnt[N][N];
bool fl[N];
void add(int u, int v){
	ed[u].push_back(v);
}
void bfs1(int x){
	memset(fl, 0, sizeof fl);
	queue<pair<int, int> > q;
	q.push({x, 0});
	fl[x] = 1;
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		for(int v : ed[u.first]){
//			cout << u.first << ' ' << v << '\n';
			if(fl[v]) continue;
			fl[v] = 1;
			q.push({v, u.second + 1});
			dist[x][v] = u.second + 1;
		}
	}
}
void bfs2(int x){
	queue<pair<int, int> > q;
	q.push({x, 0});
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		for(int v : ed[u.first]){
			if(u.second + 1 > dist[x][v]) continue;
			q.push({v, u.second + 1});
			if(u.second + 1 == dist[x][v]){
				cnt[x][v]++;
			}
		}
	}
}
signed main(){
	fin("migrate.in");
	fout("migrate.out");
	cin >> c >> t;
	while(t--){
		int n, d, ans = 0;
		cin >> n >> d;
		memset(a, 0, sizeof a);
		memset(ed, 0, sizeof ed);
		memset(dist, 0, sizeof dist);
		memset(cnt, 0, sizeof cnt);
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(a[j] - a[i] <= d) 
					add(i, j);
			}
		}
		for(int i = 1; i <= n; i++) bfs1(i);
		for(int i = 1; i <= n; i++) bfs2(i);
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(cnt[i][j] == 2) ans++; 
//				cout << i << ' ' << j << ' ' << dist[i][j] << '\n';
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
//18:03 暴力打完，复杂度好像是O(n^3) 大概24分 
