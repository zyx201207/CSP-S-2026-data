#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=505;
int c,n,m,d,q;
int w[N],k[M];
int a[M][N],t[M][N];
int dist[N];
bool vis[N];
struct node{
	int x,line,no;
};
void bfs(int x){
	memset(dist,-0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	queue<node> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				q.push({x,i,j});
			}
		}
	}
	dist[x]=w[x];
	while(!q.empty()){
		auto e=q.front();
		q.pop();
		int u=e.x,line=e.line,num=e.no;
		dist[u]+=t[line][num];
		vis[u]=true;
		for(int j=1;j<=k[line];j++){
			int v=a[line][j];
			if(v==u||vis[v]) continue;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		bfs(x);
		cout<<dist[x]<<endl;
	}
	return 0;
} 
