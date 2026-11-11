#include<bits/stdc++.h>
using namespace std;
const int N=500007,M=507;
int c,n,m,dis,qu,vis[N],a[M][M],t[M][M],d[N],cnt[N],w[N],k[N];
struct edge{int v,w;};
vector<edge> e[N]; 
priority_queue<pair<int,int> > q;
void dij(int s){
	for(int i=1;i<=m;i++)d[i]=0x3f3f3f3f;
	d[s]=0;
	q.push({0,s});
	vis[s]=1;
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		int u=t.second;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=1;i<=cnt[u];i++){
			edge ed=e[u][i];
			int v=ed.v,w=ed.w;
			if(d[u]+w<d[v]){
				d[v]=min(d[u]+w,d[v]);
				q.push({-d[v],v});
			}
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dis>>qu;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int o=j+1;o<=k[i];o++){
				cnt[a[i][j]]++;
				cnt[a[i][o]]++;
				e[a[i][j]].push_back({a[i][o],t[i][j]+t[i][o]});
				e[a[i][o]].push_back({a[i][j],t[i][j]+t[i][o]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<d[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}/*
0 2 5 20 2 
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
 1 2 ¿¨ÁË,dij¶¼´ò´í 
*/
