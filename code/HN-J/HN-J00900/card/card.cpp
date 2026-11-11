#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m, a[N], ls[M], ans[M], f[N];
bool vis[N];
vector<int> g[M];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) f[i] = 1;
	for(int i = n; i >= 1; i--){
		if(!ls[a[i]]) ls[a[i]] = i, vis[i] = 1;
		g[ls[a[i]]].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		if(vis[i - 1]){
			for(auto p : g[i - 1]) f[i] += f[p];
		}
	}
	for(int i = 1; i <= n; i++) ans[a[i]] += f[i];
	for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
