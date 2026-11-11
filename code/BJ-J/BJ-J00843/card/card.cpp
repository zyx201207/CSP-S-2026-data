#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500100];
int R[300100];

vector<int> vec[500100];
long long f[500100];
long long ans[300100];

void dfs(int u, int fa) {
	for(int v:vec[u]) {
		if(v==fa) continue;
		dfs(v, u);
		f[u]+=f[v];
	}
	f[u]++;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		R[a[i]]=i;
	}
	for(int i=1;i<=n;++i) {
		vec[i].push_back(R[a[i]]+1);
		vec[R[a[i]]+1].push_back(i);
	}
	dfs(n+1, n+1);
	for(int i=1;i<=n;++i) {
		ans[a[i]]+=f[i];
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
	return 0;
}
