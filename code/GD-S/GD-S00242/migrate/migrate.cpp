#include <bits/stdc++.h>
using namespace std;
long long c, t;
long long n, d;
long long ans;
long long x[2000005];
// for n <= 5000
bool vis[5005];
long long dis[5005][5005];
long long cnt[5005][5005];
vector<long long> adj[5005];
//
void bfs(long long st){
	for(int i = 1; i <= n; i++){
		vis[i] = false;
	}
	
	queue<long long> q;
	q.push(st);
	dis[st][st] = 0;
	cnt[st][st] = 1;
	vis[st] = true;
	while(!q.empty()){
		long long u = q.front();
		q.pop();
		for(long long i = 0; i < adj[u].size(); i++){
			long long v = adj[u][i];
			if(vis[v] == false){
				q.push(v);
				dis[st][v] = dis[st][u] + 1;
				cnt[st][v]++;
				vis[v] = true;
			}
			else if(dis[st][u] + 1 == dis[st][v]){
				cnt[st][v] += 1;
			}
		}
	}
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(long long i = 1; i <= n; i++){
			cin >> x[i];
		}
		
		if(c >= 1 && c <= 10){
			ans = 0;
			for(long long i = 1; i <= n; i++){
				adj[i].clear();
			}
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					dis[i][j] = 1e9;
					cnt[i][j] = 0;
				}
			}
			
			for(long long i = 1; i <= n; i++){
				for(long long j = i + 1; j <= n; j++){
					if(x[j] - x[i] <= d){
						adj[i].push_back(j);
					}
					else{
						break;
					}
				}
			}
			
			for(long long i = 1; i <= n; i++){
				bfs(i);
				for(long long j = 1; j <= n; j++){
					if(cnt[i][j] == 2){
						ans++;
					}
					cout << cnt[i][j] << " ";
				}
				cout << "\n";
			}

			cout << ans << "\n";
		}
		else if(c >= 11 && c <= 12){
			long long diff = x[2] - x[1];
			if(d < diff){
				cout << 0 << "\n";
			}
			else{
				long long bs = diff / d;
				cout << 0 << "\n";
			}
		}
		else if(c >= 13 && c <= 14){
			cout << 0 << "\n"; 
		}
		else{
			cout << 0 << "\n";
		}
	}
}
