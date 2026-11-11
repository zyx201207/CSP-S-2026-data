#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int c, t;
void solve(){
	int n, d;
	cin >> n >> d;
	vector<int> x(n + 1, 0);
	int mn = 0;
	for(int i = 1;i <= n;i++) {cin >> x[i];;mn = min(mn, x[i]);}
	vector<int> g[n + 5];
	for(int i = 1, j = 1;i <= n;i++){
		for(;x[i] - x[j] > d;j++);
		for(int k = j;k < i;k++){
			g[k].push_back(i);
		}
	}
//	for(int i = 1;i <= n;i++){
//		for(int j : g[i]){
//			cout << j << ' ';
//		}
//		cout << '\n';
//	}
	int anss = 0;
	queue<pair<int, int>> q;
	for(int i = 1;i <= n;i++){
		vector<int> dist(n + 5, (int)2e18 + 5);
		vector<bool> vis(n + 5);
		vector<int> ans(n + 5);
		q.push({i, 0});
		while(!q.empty()){
			int cur = q.front().first, val = q.front().second;
			dist[cur] = val;
			q.pop();
			for(int j : g[cur]){
				if(ans[j] && dist[j] == val + 1) ans[j]++;
				else if(!ans[j]){
					ans[j] = 1; dist[j] = val + 1;
					q.push({j, val + 1});
				}
			}
		}
		for(int j = 1;j <= n;j++) {anss += ans[j] == 2;}
	}
	cout << anss << '\n';
}
			
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	for(;t--;){
		solve();
	}
	return 0;
}
