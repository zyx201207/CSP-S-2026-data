#include <bits/stdc++.h>
using namespace std;
long long a[2000010];
vector<int> e[2000010];
int vis[2000010];
vector<int> arr;
int dis[2000010];
int c, t;
void dfs(int x, int y, int dis){
	if(x == y){
		arr.push_back(dis+1);
		return;
	}
	for(auto i: e[x]){
		if(vis[i] == 1) continue;
		vis[i] = 1;
		dfs(i, y, dis+1);
		vis[i] = 0;
	}
}
void bfs(int x){
	queue<int> q;
	q.push(x);
	vis[x] = 1;
	dis[x] = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto i: e[now]){
			if(vis[i] == 0){
				vis[i] = 1;
				q.push(i);
				dis[i] = dis[now] + 1;
			}
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		for(int i = 1;i <= 2000000;i++){
			a[i] = 0;
			e[i].clear();
		}
		int n, d;
		cin >> n >> d;
		if(n >= 300){
			cout << 0 << endl;
			continue;
		}
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for(int i = 1;i < n;i++){
			for(int j = i+1;j <= n;j++){
				if(a[j] - a[i] <= d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		int cnt = 0; 
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				for(int k = 1;k <= n;k++){
					vis[k] = 0;
				}
				arr.clear();
				dfs(i, j, 0);
				sort(arr.begin(), arr.end());
				if(arr.size() == 2 && arr[0] == arr[1]){
					cnt++;
				}else if(arr.size() > 2 && arr[0] == arr[1] && arr[1] != arr[2]){
					cnt++;
				}
				 
			}
		}
		cout << cnt << endl;
//		int ans = 0;
//		for(int i = 1;i <= n;i++){
//			bfs(i);
//			for(int j = i+1;j <= n;j++){
//				int minx = dis[j];
//				int cnt = 0;
//				for(auto k:e[j]){
//					if(dis[k] + 1 == minx){
//						cnt++;
//					}
//				}
//				if(cnt == 2){
//					ans++;
//				}
//			}
//		}
//		cout << ans << endl;
	}
	return 0;
}
