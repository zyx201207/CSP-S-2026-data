#include<bits/stdc++.h>
#define int long long
using namespace std;
struct innt{
	int a,t;
};
vector<innt> a[505];
int c,n,m,d,tq;
int w[500005],k[505],dist[500005];
vector<int> shu[500005];
bool vis[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>tq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back({x,y});
			shu[x].push_back(i);
		} 
	}
	while(tq--){
		int x,y,sum=0;
		cin>>x>>y; 
		memset(dist,0x3f3f3f3f,sizeof dist);
		memset(vis,0,sizeof vis);
		dist[x]=0;
		queue<int> q;
		q.push(x);
		while(!q.empty()){
			int u=q.front();
			vis[u]=0;
			q.pop();
			for(int i=0;i<shu[u].size();i++){
				int xian=shu[u][i],w=0;
				for(int j=0;j<a[xian].size();j++){
					if(a[xian][j].a==u) {
						w+=a[xian][j].t;
						break;
					}
				}for(int j=0;j<a[xian].size();j++){
					int v=a[xian][j].a;
					if(dist[u]+w+a[xian][j].t<dist[v]){
						dist[v]=dist[u]+w+a[xian][j].t;
						if(!vis[v]){
							q.push(v);
							vis[v]=1;
						}
					} 
				} 
			} 
		} 
		cout<<w[x]+w[y]+dist[y]<<endl;
	} 
	return 0;
}
