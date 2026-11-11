#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k;
vector <int> e[1000010];
int dis[1000010], vis1[100010], vis2[100010], vis3[100010];
void dfs(int x){
	vis2[x] = true;
	for (int v : e[x])if (vis1[v] && !vis2[v])dfs(v);
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int c, T;
	cin >> c >> T;
	while (T--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++)e[i].clear();
		for (int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int mini = n;
		for (int i = 0; i < (1 << n); i++){
			if (__builtin_popcount(i) != k)continue;
			for (int j = 1; j <= n; j++)vis1[j] = vis2[j] = 0;
			for (int j = 1; j <= n; j++)if (((i >> (j - 1)) & 1))vis1[j] = 1;
			int cnt = 0;
			for (int j = 1; j <= n; j++){
				if (vis1[j] && !vis2[j]){
					dfs(j), cnt++;
					if (cnt > 2)break;
				}
			}
			if (cnt > 2)continue;
			queue <int> q;
			for (int j = 1; j <= n; j++){
				vis3[j] = 0;
				if (vis1[j])dis[j] = 0, q.push(j);
				else dis[j] = n + 1;
			}
			while (!q.empty()){
				int x = q.front();
				q.pop();
				if (vis3[x])continue;
				vis3[x] = true;
				for (int v : e[x])if (dis[x] + 1 < dis[v])dis[v] = dis[x] + 1, q.push(v);
			}
			int maxi = 0;
			for (int j = 1; j <= n; j++)maxi = max(maxi, dis[j]);
			mini = min(maxi, mini);
		}
		cout << mini << endl;
	}
	return 0;
} 
/*
题意：
给出一棵无根无权树，请选出k个特殊点使这些点在原树中的有1或2个连通块
每个点的通勤距离为到这k个特殊点距离的最小值
使每个点通勤距离的最大值最小

为啥暴力代码还这么长啊……………………我这是纯暴力啊………………………… 
*/
