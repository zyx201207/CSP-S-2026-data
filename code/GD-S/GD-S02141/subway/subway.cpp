#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
#define int long long
vector<pair<int,int>> e[maxn];
int dis[maxn],l[maxn],n,m,c,d,q;
void add_edge(int u,int v,int w){
	e[u].push_back({v,w});
	e[v].push_back({u,w});
}
int dijstra(int start,int end){
	memset(dis,0x3f,sizeof(dis));
	dis[start]=0;
	queue<pair<int,int>> q;
	q.push({start,0});
	while(!q.empty()){
		int u=q.front().first,l=q.front().second;
		q.pop();
		dis[u]=l;
		if(u==end) break;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].first,ll=e[u][i].second;
			if(dis[u]+ll<dis[v]) q.push({v,dis[u]+ll});
		}
	}
	return dis[end];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> l[i];
	int idx=m;
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		idx++;
		for(int j=1;j<=k;j++){
			int a,t;
			cin >> a >> t;
			add_edge(idx,a,t);
		}
	}
	while(q--){
		int u,v;
		cin >> u >> v;
		cout << dijstra(u,v)+l[u]+l[v] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
