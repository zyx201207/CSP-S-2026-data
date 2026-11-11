#include<bits/stdc++.h>
using namespace std;
int x[2000005], n, d, c, t;
int ans = 0;
void bfs(int u, int v){
	int cnt = 0, maxn = 0;
	queue<pair<int, int>> q;
	q.push({u, 0});
	while(!q.empty()){
		auto f=q.front();
		q.pop();
		int y = f.first;
		int step = f.second;
		if(y == v){
			if(cnt == 0) maxn = step;
			if(step == maxn)cnt++;
			continue;
		}
		for(int i = 1; i <= n; i++){
			if(d < abs(x[y] - x[i]) || y == i) continue;
			q.push({i, step + 1});
		}
	}
	if(cnt == 2) ans++;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		ans = 0;
		memset(x, 0, sizeof x);
		int n, d; cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		for(int i = 1; i < n; i++){
			for(int j = i + 1; j <= n; j++){
				bfs(i, j);
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
