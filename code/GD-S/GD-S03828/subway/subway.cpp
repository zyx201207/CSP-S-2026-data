#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
using namespace std;
int c,n,m,D,Q;
int a[500505],d[500505],vis[500505],gg[505][505];
struct node{
	int v,w;
};
vector<node>g[500505];
priority_queue<pair<int,int> >q;

void dij(int s){
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()) {
		int u=q.top().second;
		vis[u]=1;
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,w=g[u][i].w;
			if(vis[v])continue;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push(make_pair(-d[v],v));
			} 
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		for(int j=1;j<=p;j++){
			int x,w;
			cin>>x>>w;
			g[x].push_back(node{m+i,w});
			g[m+i].push_back(node{x,w});
		}
	}

	if(m+n<=2000&&Q<=2000){
		while(Q--){
			int x,y;
			cin>>x>>y;
			dij(x);
		//	cout<<a[x]<<" "<<a[y]<<" "<<d[y]<<endl;
			cout<<a[x]+a[y]+d[y]<<endl;
		}
		return 0;		
	}
	memset(gg,0x3f,sizeof(gg));
	for(int i=1;i<=m;i++){
	//	cout<<"!!!!"<<i<<endl;
		for(int x=0;x<g[i].size();x++){
			for(int y=x+1;y<g[i].size();y++){
				int v1=g[i][x].v,v2=g[i][y].v,w1=g[i][x].w,w2=g[i][y].w;
				v1-=m,v2-=m;
	//			cout<<v1<<" "<<v2<<" "<<w1<<" "<<w2<<" "<<endl;
				gg[v1][v2]=min(gg[v1][v2],w1+w2);
				gg[v2][v1]=gg[v1][v2];
			}
		}
	}
	
	for(int i=1;i<=n;i++)gg[i][i]=0;

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==k||j==k||i==j)continue;
				gg[i][j]=min(gg[i][j],gg[i][k]+gg[k][j]);
				gg[j][i]=gg[i][j];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<gg[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(Q--){
		int u,v;
		cin>>u>>v;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int x=0;x<g[u].size();x++){
			for(int y=0;y<g[v].size();y++){
				int v1=g[u][x].v,v2=g[v][y].v,w1=g[u][x].w,w2=g[v][y].w;
				v1-=m,v2-=m;
				ans=min(ans,w1+w2+gg[v1][v2]);
			}
		}
		cout<<ans+a[u]+a[v]<<endl;
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

