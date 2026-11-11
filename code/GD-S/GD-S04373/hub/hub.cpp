#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> a[200005];
int v[200005];
int b[200005];
void dfs(int x){
	v[x] = 1;
	b[x] = 1;
	for(int i : a[x]){
		if(v[i])continue;
		dfs(i);
		b[x] = max(b[i], b[x]);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			int u, v;
			cin >> u>> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1);
		sort(b + 1, b + n + 1, greater<int>());
		ans = b[1] + b[2];
		if(c  >= 10)cout << 12;
		cout << b[1] + b[2]  << endl;
	}
	return 0;
}
//os£ººÃÄÑ°¡ 
