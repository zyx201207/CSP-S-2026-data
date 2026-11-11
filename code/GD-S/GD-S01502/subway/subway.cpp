#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const long long INF=1e18+1;
long long c,n,m,d,q,dis[1005][1005],w[1005],k[1005];
bool vis[1005];
vector<long long>sub[1005];
vector<long long>t[1005],a[1005];
int id[1005][1005];
void dijkstra(int s){
	priority_queue<pair<long long,long long> >q;
	dis[s][s]=0;
	q.push({0,s});
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		long long u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto whe:sub[u]){
			for(int i = 0;i < a[whe].size();i++){
				if(a[whe][i]==u) continue;
				if(dis[s][a[whe][i]]>dis[s][u]+t[whe][i]+t[whe][id[whe][u]]){
					dis[s][a[whe][i]]=dis[s][u]+t[whe][i]+t[whe][id[whe][u]];
					q.push({-dis[s][a[whe][i]],a[whe][i]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) cin>>w[i];
	for(int i = 1;i <= m;i++) for(int j = 1;j <= m;j++) dis[i][j]=INF;
	for(int i = 1;i <= n;i++){
		cin>>k[i];
		long long aa,tt;
		for(int j = 1;j <= k[i];j++){
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			sub[aa].push_back(i);
			id[i][aa]=j-1;
		}
	}
	for(int i = 1;i <= m;i++) dijkstra(i);
//	for(int i = 1;i <= m;i++){
//		for(int j = 1;j <= m;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//int ans[1005];
	for(int i = 1;i <= q;i++){
		long long x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<'\n';
//		ans[i]=dis[x][y]+w[x]+w[y];
	}
//freopen("subway4.ans","r",stdin);
//bool OK=1;
//	for(int i = 1;i <= q;i++){
//		long long x;
//		cin>>x;
//		if(x!=ans[i]) OK=0,cout<<i<<' '<<x<<" There";
//	}
//	cout<<OK;
	return 0;
}
