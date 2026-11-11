//subway
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
int w[500005],dis[500005],vis[500005];
vector<pii> g[500005];
int c,n,m,d,q;
int dijikstra(int st,int ed){
	priority_queue<pii> q;
	q.push({0,st});
	for(int i=0;i<=n+m;i++){
		dis[i]=1e17;
		vis[i]=0;
	}
	while(!q.empty()){
		pii nodeu=q.top();
		q.pop();
		int u=nodeu.second,cur=-nodeu.first;
		if(vis[u])continue;
		vis[u]=1;
		if(u==ed){
			return dis[ed];
		}
		for(auto edge:g[u]){
			int v=edge.second,di=edge.first;
			if(dis[v]>cur+di){
				dis[v]=cur+di;
				q.push({-dis[v],v});
			}
		}
	}
	return -1;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	if(c>11)return 0;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin >> a >> t;
			g[m+i].push_back({t,a});
			g[a].push_back({t,m+i});
		}
	}
//	for(int i=1;i<=m+n;i++){
//		for(auto v:g[i]){
//			cout << i << ' ' << v.second << ' ' << v.first << endl;
//		}
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << dijikstra(x,y)+w[x]+w[y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
