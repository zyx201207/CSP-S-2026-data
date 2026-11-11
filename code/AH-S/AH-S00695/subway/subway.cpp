#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 5e5 + 10;

int c, n, m, d, q, s, e;
int w[M], k, a[M], t[M];
vector <int> E[M];
vector <pair <int, int> > P[M];
struct node{
	int u, line, ti; 
	friend bool operator<(node a, node b){
		return a.u < b.u;
	}
};
map <node, int> vis;

int bfs(){
	queue <node> q;
	for(auto k : P[s])
		q.push({s, k.first, w[s] + k.second});
	int ans = 2e9;
	while(!q.empty()){
		node now = q.front();
		q.pop();
//		cout << now.u << ' ' << now.line << ' ' << now.ti << '\n';
		if(vis[{now.u, now.line, now.ti}] >= 5) continue;
		if(now.u == e){
			int tmp = 0;
			for(auto k : P[now.u]){
				if(k.first == now.line){
					tmp = k.second;
					break;
				}
			}
			ans = min(ans, now.ti + tmp);
			continue;
		}
		vis[{now.u, now.line, now.ti}] ++;
		for(auto i : E[now.u]){
			int tmp = -1;
			for(auto j : P[i])
				if(j.first == now.line){
					tmp = j.second;
		     		break;
				}
			if(tmp == -1) continue;
			for(auto j : P[i]){
				if(now.line == j.first)
					q.push({i, j.first, now.ti});
				else
					q.push({i, j.first, now.ti + tmp + j.second});
			}
		}
	}
	return ans + w[e];
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
		cin >> w[i];
	for(int i = 1; i <= n; i ++){
		cin >> k;
		for(int j = 1; j <= k; j ++){
			cin >> a[j] >> t[j];
			if(j >= 2){
				E[a[j]].push_back(a[j - 1]);
				E[a[j - 1]].push_back(a[j]);
			}
			P[a[j]].push_back({i, t[j]});
		}
	}
//	for(int i = 1; i <= m; i ++, cout << '\n')
//		for(auto j : P[i]) cout << j.first << ' ';
//	cout << "\n\n";
	while(q --){
		vis.clear();
		cin >> s >> e;
		cout << bfs() << '\n';
	}
	return 0;
}

