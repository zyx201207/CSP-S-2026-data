#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int> G[N]; 
bool is[N];
int c,n,m,d[105][105];
void dfs(int u,int fa){
	d[u][fa]=d[fa][u]=1;
	for(int v: g[u]){
		if(v==fa) continue;
		dfs(v,u);
		d[fa][v]=d[v][fa]d[u][v]+d[u][fa];
		
	} 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin >> c >> t;
	int i=1;
	while(t--){
		memset(is,0,sizeof is);
		cin >> n >> m;
		for(int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		i++;
		cout << i << "\n";
	}
	
	return 0;
}
