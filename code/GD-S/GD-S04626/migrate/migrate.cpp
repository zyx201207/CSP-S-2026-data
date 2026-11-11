#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int v, w;
};
vector <int> ve[2000001];
int c, t, n, d, a[2000001], di[2000001], num[2000001], ans;
bool vis[2000001];
void bfs(int st){
	memset(di, 0x3f, sizeof(di));
	memset(num, 0, sizeof(num));
	memset(vis, 0, sizeof(vis));
	di[st] = 0;
	vis[st] = 1;
	queue<node> qu;
	qu.push({st, 0});
	
	while (!qu.empty()){
		node f = qu.front();
		qu.pop();
		if (di[f.v] == 0x3f3f3f3f3f3f3f3f){
			di[f.v] = f.w;
			num[f.v]++;
		}
		else if (f.w == di[f.v]){
			num[f.v]++;
		}
		else if (f.w > di[f.v]){
			vis[f.v] = 1;
		}
		for (int i = 0; i < ve[f.v].size(); i++){
			if (!vis[ve[f.v][i]]){
				qu.push({ve[f.v][i], f.w + 1});
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if (num[i] == 2){
			ans++;
		}
	}
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld",&c, &t);
	while(t--){
		ans = 0; 
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
			ve[i].clear();
		}
		for (int i = 1; i <= n; i++){
			int j = i + 1;
			while (j <= n && a[j] - a[i] <= d){
				ve[i].push_back(j);
				ve[j].push_back(i);
				j++;
			}
		}
		for (int i = 1; i <= n; i++){
			bfs(i);
		}
		printf("%lld\n", ans / 2);
	}
	return 0;
}
