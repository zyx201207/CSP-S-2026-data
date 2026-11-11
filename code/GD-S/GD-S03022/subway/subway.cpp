//n <= 505, m <= 500005
#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, p, k;
struct Edge{
	int to, nbr;
};
struct Node{
	vector <Edge> edge;
	int tme[505];//tme[i]第i线路进入站厅所需时间 
};
pair <int, int> ki[500005];
vector <Node> g(500005);
int w[505];
int ans = 1234567890;

int srch(int s, int e){
	bool vis[500005];
	for(int i = 1;i <= m;i++) vis[i] = false;
	queue <pair<int, int>> q;
	q.push({s, w[s]});
	while(!q.empty()){
		pair <int, int> t = q.front();
		if(t.first == e){
			if(t.second < ans) ans = t.second;
			continue;
		} 
		//遍历g[t.first].edge
		for(int i = 0;i < g[t.first].edge.size();i++){
			Edge to2 = g[t.first].edge[i];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> p;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> ki[j].first >> ki[j].second;
		}
		for(int j = 1;j <= k;j++){
			if(j != 1) {
				Edge tmp;
				tmp.
				g[ki[j].first].edge.push_back({g[ki[j - 1].first], i});
			}
			if(j != k){
				g[ki[j].first].edge.push_back({g[ki[j + 1].first], i});
			}
			g[ki[j].first].tme[i] = ki[j].second;
		}
	}
	return 0;
}

