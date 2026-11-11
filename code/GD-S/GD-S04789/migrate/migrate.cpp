#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e6+5;

int c, t, n, d, a[maxn], mn = 1e9+5, cnt, vis[maxn];

vector<int> V[maxn];

void bfs(int x, int y){
	memset(vis, 0, sizeof(vis));
	queue <pair<int, int> > q;
	q.push({0, x});
	vis[x] = 1;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(now.first > mn) continue;
//		cout << now.first << " " << now.second << "\n";
		if(now.second == y){
			if(mn > now.first){
				mn = now.first;
				cnt = 1;
			}else if(mn == now.first) cnt++;
			continue;
		}
		for(auto v : V[now.second]){
			if(vis[v]) continue;
//			cout << v << " ";
			q.push({now.first +1, v});
			vis[v] = 1;
		}
		vis[y] = 0;
//		cout << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			for(int j = 1; j <= i-1; j++){
				if(a[i] <= d + a[j]) {
					V[i].push_back(j);
					V[j].push_back(i);
				}
			}
		}
		int ans = 0;
		for(int i = 2; i <= n; i++){
			for(int j = 1; j < i; j++){
				bfs(j, i);
				if(cnt == 2) ans++;
//				cout << i << " " << j << " " << mn << " " << cnt << "\n"; 
//				cout << "\n";
				mn = 1e9+5, cnt = 0;
			}
		}
		for(int i = 1; i <= n; i++)V[i].clear();
		cout << ans << "\n";
	}
	
	return 0;
}


