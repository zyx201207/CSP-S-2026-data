#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
int c,n,m,d,q,vis[2005];
long long dis[2005][2005],f[2005][2005],w[500005];
struct node{
	int id,t;
};
struct tmp{
	long long dis,id;
	bool friend operator<(tmp x,tmp y){
		return x.dis>y.dis;
	}
};
priority_queue<tmp> qq;
bool cmp(node x,node y){
	return x.id<y.id;
}
vector<node> a[500005];
vector<pair<int,int> > sub;
void dij(int s){
	for(int i=1;i<=m;i++){
		dis[s][i]=inf;
		vis[i]=0;
	}
	dis[s][s]=0;
	qq.push({0,s});
	while(!qq.empty()){
		int u=qq.top().id;
		//cout<<u<<' '<<dis[s][u]<<'\n';
		qq.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int v=1;v<=m;v++){
			if(dis[s][v]>dis[s][u]+f[u][v]){
				dis[s][v]=dis[s][u]+f[u][v];
				qq.push({dis[s][v],v});
			} 
		}
	}
}
long long solve(int u,int v){
	return w[u]+w[v]+dis[u][v];
}
long long minn(long long x,long long y){
	return x<y?x:y;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j){
				f[i][j]=inf;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int k,xx,tt;
		cin>>k;
		sub.clear();
		for(int j=1;j<=k;j++){
			cin>>xx>>tt;
			sub.push_back(make_pair(xx,tt));
		}
		for(int i1=0;i1<k;i1++){
			for(int i2=0;i2<k;i2++){
				if(i1!=i2){
					int u=sub[i1].first,v=sub[i2].first,t=sub[i1].second+sub[i2].second;
					f[u][v]=minn(f[u][v],t);
					//cout<<u<<' '<<v<<'\n';
				}
			}
		}
		//cout<<'\n';
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]!=inf) cout<<f[i][j]<<' ';
			else cout<<"inf ";
		}
		cout<<'\n';
	}*/
	for(int i=1;i<=m;i++){
		dij(i);
		//cout<<'\n';
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<solve(u,v)<<'\n';
	}
	return 0;
}
