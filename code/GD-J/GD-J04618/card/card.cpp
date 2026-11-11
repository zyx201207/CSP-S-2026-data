#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, M = 5e5 + 5;

bool b[N];
vector<int> ph[N], a(M), last(N, 0), ans(N, 1);

void dfs(int u){
	for(int v : ph[u]){
		dfs(v);
		ans[u] += ans[v];
	}
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=n; i; i--){
		if(b[a[i]]) continue;
		b[a[i]] = 1;
		last[a[i]] = i;
	}
	for(int i=1; i<=n; i++){
		ph[last[a[i]]+1].push_back(i);
	}
	dfs(n + 1);
	for(int i=1; i<=m; i++) cout << ans[last[i]+1]-1 << " ";
    return 0;
}
