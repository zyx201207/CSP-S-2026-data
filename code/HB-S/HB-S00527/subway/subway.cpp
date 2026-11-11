#include<bits/stdc++.h>
using namespace std;
const int N=2005;
struct node{
	int v,w;
};
int wm[N];
int c,n,m,d,qq;
vector<node>e[N];
int dis[N][N];
int sze[N];
int vis[N];
queue<int>q;
void dij(int s){
	memset(vis,0,sizeof(vis));
	dis[s][s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(auto ed:e[u]){
			if(dis[s][ed.v]>dis[s][u]+ed.w){
				dis[s][ed.v]=dis[s][u]+ed.w;
				if(!vis[ed.v]){q.push(ed.v);
				vis[ed.v]=1;}
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		cin>>wm[i];
	}
	for(int i=1;i<=n;i++){
		int sz;
		cin>>sz;
		sze[i]=sz;
		for(int j=1;j<=sz;j++){
			int vv,ww;
			cin>>vv>>ww;
			e[i+m].push_back({vv,ww});
			e[vv].push_back({i+m,ww});
		}
	}
	for(int i=1;i<=n+m;i++){
		dij(i);
	}
	for(int i=1;i<=qq;i++){
		int x,y;
		cin>>x>>y;
	//	cout<<dis[x]<<" "<<dis[x+1]<<"\n";
		cout<<dis[x][y]+wm[x]+wm[y]<<"\n";
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
