#include <bits/stdc++.h>
#define ll long long
#define inf 0x3fffffff
using namespace std;
int c,t,n,k,dis[1000005];
bool vis[100005];
vector<int> e[1000005];

int dfs(int x){
	vis[x]=1;
	for(auto it:e[x]){
		if(!vis[it]) dis[x]=max(dis[x],dfs(it)+1);
	}
	return dis[x];
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<n;i++){
			dis[i]=0;e[i].clear();vis[i]=0;
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dis[n]=0;e[n].clear();vis[n]=0;
		dfs(1);
		int cnt=0;
		for(auto it:e[1]) cnt+=dis[it]+1;
		cout << cnt/2-1 << endl;
	}
	return 0;
}
