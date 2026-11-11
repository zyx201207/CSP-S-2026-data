#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;
long long n,m,q,w[500005],a[501][50001],t[501][50001],head[500005],dis[500005],inq[500005],cnt;
vector<int>g[500005];
struct edge{
	int next,v,w;
}e[2000006];
void add(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void spfa(int s){
	queue<int>q;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(inq,0,sizeof(inq));dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=head[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(dis[u]+e[i].w<dis[v]){
				dis[v]=dis[u]+e[i].w;
				if(!inq[v]){q.push(v);inq[v]=1;}
			}
		}
	}
}
int main(){

	freopen("subway3.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,D;
	memset(head,-1,sizeof(head));
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int ki;scanf("%d",&ki);
		for(int j=1;j<=ki;j++){
			int x,y;scanf("%d%d",&x,&y);
			a[i][j]=x;t[i][j]=y;
			if(!g[x].empty()){
				for(int k=0;k<(int)g[x].size();k++){
					add(i,g[x][k],(t[i][x]+t[g[x][k]][x]));
					add(g[x][k],i,(t[i][x]+t[g[x][k]][x]));
				}
			}
			g[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		long long mid=0x3f3f3f3f,ans=0x3f3f3f3f,midy=g[y][0];
		if(!g[x].empty()){
			
			for(int j=0;j<(int)g[x].size();j++){
				spfa(g[x][j]);
				if(!g[y].empty()){
					for(int j=0;j<(int)g[y].size();j++){
						if(dis[g[y][j]]<mid){
							mid=dis[g[y][j]];
							midy=g[y][j];
						}
					}
				}
				ans=min(ans,w[x]+w[y]+mid+t[g[x][j]][x]+t[midy][y]);
			}
			
		}
		cout<<ans<<endl;
	}
}
