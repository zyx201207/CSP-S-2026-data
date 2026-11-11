#include<bits/stdc++.h>
using namespace std;
long long w[501];
struct P{
	int to,w;
};
struct node{
	int x,d;
};
vector<P>g[100010];
long long dis[510][510];
bool vis[510];
int c,n,m,d,q,k[510];
long long ans=1e18;
bool operator < (node a,node b){
	return a.d>b.d;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x,z;
		cin>>x>>z;
		g[i].push_back({x,z});
		g[x].push_back({i,z});
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		priority_queue<node>q;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		q.push({x,0});
		dis[x][x]=0;
		while(!q.empty()){
			int y=q.top().x;
			q.pop();
			if(!vis[x]){
				for(int i=0;i<g[y].size();i++){
					int z=g[y][i].to;
					if(dis[x][z]>dis[x][y]+g[y][i].w){
						dis[x][z]=dis[x][y]+g[y][i].w;
						q.push({z,g[y][i].w});
					}
				}
			}
		} 
		cout<<dis[x][y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
