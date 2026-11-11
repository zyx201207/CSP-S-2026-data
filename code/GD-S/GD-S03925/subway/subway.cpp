#include<bits/stdc++.h>
using namespace std;
const int N=2e7+10;
const int M=5e5+10;
const int INF=0x3f3f3f3f;
struct Node{
	int v,w;
};
vector<Node>g[N];
int dis[N];
bool vis[N];
int x,y;
void SPFA(){
	queue<int>q;
	q.push(x);
	vis[x]=1;
	dis[x]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(Node t:g[u]){
			int v=t.v;
			int w=t.w;
			if(dis[u]+w<dis[v]){
				if(!vis[v])q.push(v);
				dis[v]=dis[u]+w;
				vis[v]=1;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		int w;
		scanf("%d",&w);
		g[i+2*m].push_back({i+m,w});
		g[i+m].push_back({i+2*m,w});
	}
	for(int i=3;i<=n+2;i++){
		int k;
		scanf("%d",&k);
		int a,t;
		int last=0;
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			if(j>1){
				g[j-1+i*m].push_back({j+i*m,0});
				g[j+i*m].push_back({j-1+i*m,0});
			}
			g[a+m].push_back({j+i*m,t});
			g[j+i*m].push_back({a+m,t});
			last=a;
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		x=2*m+x;
		y=2*m+y;
		memset(vis,0,sizeof vis);
		for(int i=0;i<2e5;i++)dis[i]=INF;
		SPFA();
		printf("%d\n",dis[y]);
	}
	return 0;
} 
