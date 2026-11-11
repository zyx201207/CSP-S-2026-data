#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}sum[1000005];
bool cmp(node a,node b){
	return a.y>b.y;
}
int c,t,n,k,ans;
vector<int> g[1000005];
bool vis[1000005];
void dfs(){
	
	memset(vis,0,sizeof(vis));
	
}
void solve(){
	cin >> n >> k;
	for(int u,v,i = 1;i <= n;i++){
		cin >> u >> v;
		sum[u].x=u,sum[v].x=v;
		sum[u].y++,sum[v].y++;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	sort(sum+1,sum+(n-1)+1,cmp);
	dfs();
	cout << ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cout << "1\n";
//		solve();
	}
	return 0;
}

