#include<bits/stdc++.h>
using namespace std;
long long w[500001],n,m,op,d,p,vis[500501],dis[500501];
struct stu{
	long long to,w;
};
vector<stu> a[501],g[500501];
int operator<(stu a,stu b){
	return a.w>b.w;
}
long long dij(long long st,long long e){
	for(long long i=0;i<=n;i++){
		dis[i]=1e9;
		vis[i]=0;
	}
	priority_queue<stu> q;
	dis[st]=0;
	q.push({st,0});
	while(q.size()){
		long long g=q.top().to;
		q.pop();
		vis[g]=0;
		for(long long i=0;i<a[g].size();i++){
			long long to=a[g][i].to,w=a[g][i].w;
			if(dis[to]>dis[g]+w){
				dis[to]=dis[g]+w;
				if(vis[to]==0){
					vis[to]=1;
					q.push({to,dis[to]});
				}
			}
		}
	}
//	for(long long i=1;i<=n+m;i++){
//		cout<<dis[i]<<endl;
//	}
	return dis[e];
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>op>>n>>m>>d>>p;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long x,y;
			cin>>x>>y;
			g[x].push_back({m+i,y});
			g[m+i].push_back({x,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				a[g[i][j].to-m].push_back({g[i][k].to-m,g[i][j].w+g[i][k].w});
				a[g[i][k].to-m].push_back({g[i][j].to-m,g[i][j].w+g[i][k].w});
			}
		}
	}
	while(p--){
		long long x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				ans=min(ans,dij(g[x][i].to-m,g[y][j].to-m)+g[y][j].w+g[x][i].w);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

