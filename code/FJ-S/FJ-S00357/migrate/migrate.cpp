#include <bits/stdc++.h>
#define int long long
#define pub push_back
using namespace std;
const int N = 2e6 + 5, MAX = 5005, inf = 1e9;
int c, T, n, d, a[N], b[N], dis[N], ans; bool vis[N];
vector <int> ed[N]; queue <int> q;
void bfs(int x){
	while(!q.empty()) q.pop();
	for(int i = x;i <= n;i++) vis[i] = 0, dis[i] = inf, b[i] = 0;
	q.push(x), b[x] = 1, dis[x] = 0;
	while(!q.empty()){
		int t = q.front(); q.pop();
		for(auto i : ed[t]){
			if(dis[t] + 1 < dis[i] && !vis[i]){
				dis[i] = dis[t] + 1, b[i] = b[t];
				q.push(i);
			} else if(dis[t] + 1 == dis[i]){
				b[i] += b[t];
			}
		}
	}
	for(int i = x + 1;i <= n;i++) if(b[i] == 2) ans++;
}
signed main(){
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while(T--){
		cin >> n >> d; ans = 0;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++)
			for(int j = i + 1;j <= n;j++)
				if(a[j] - a[i] <= d) ed[i].pub(j);
		for(int i = 1;i <= n;i++) bfs(i);
		cout << ans << "\n";
		for(int i = 1;i <= n;i++) ed[i].clear();
		for(int i = 1;i <= n;i++) vis[i] = 0, dis[i] = inf, b[i] = 0;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
Ô¤¹À40·Ö 
*/
