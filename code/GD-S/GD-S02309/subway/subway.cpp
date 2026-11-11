#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],a[510][30],t[510][30];
int ver[1000010],head[1000010],nex[1000010],edge[1000010],tot,dist[500010];
bool v[500010];
void add(int x,int y,int z){
	ver[++tot]=y;edge[tot]=z;
	nex[tot]=head[x];head[x]=tot;
}
priority_queue<pair<int,int>> qq;
void dijkstra(int i){
	memset(v,0,sizeof(v));
	memset(dist,0x3f,sizeof(dist));
	dist[i]=0;
	qq.push(make_pair(0,i));
	while(!qq.empty()){
		int x=qq.top().second;
		qq.pop();
		if(v[x]) continue;
		v[x]=true;
		for(int i=head[x];i;i=nex[i]){
			int y=ver[i],z=edge[i];
			if(dist[x]+z<dist[y]){
				dist[y]=dist[x]+z;
				qq.push(make_pair(-dist[y],y));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				add(a[i][j],a[i][j-1],t[i][j]+t[i][j-1]);
				add(a[i][j-1],a[i][j],t[i][j]+t[i][j-1]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<w[x]+w[y]+dist[y]<<"\n";
	}
	return 0;
}
