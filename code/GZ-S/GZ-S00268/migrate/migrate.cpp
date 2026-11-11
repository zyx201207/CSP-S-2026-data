//GZ-S00268 遵义天立学校 杨润凯 
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
typedef long long ll;
int n;
ll d,a[maxn];
int head[maxn],len;
struct edge{
	int u,v,w,ne;
}e[maxn*maxn];
void insert(int u,int v,int w){
	e[++len]={u,v,w,head[u]},head[u]=len;
}
int dis[maxn];
ll w[maxn];
bool vis[maxn];
void rink(){
	memset(head,0,sizeof head);len=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;++i)scanf("%lld\n",&a[i]);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(i==j)continue;
			if(a[j]-a[i]<=d){
				insert(i,j,1),insert(j,i,1);
//				printf("%d %d\n",i,j);
			}
		}
	}
}
bool ans[maxn][maxn];
void spfa(int i){
	memset(dis,0x3f,sizeof dis);
	memset(w,0,sizeof w);
	memset(vis,0,sizeof vis);
	queue<int>q;
	vis[i]=1,dis[i]=0,w[i]=1;
	q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].ne){
			int v=e[i].v;
			if(dis[v]==dis[u]+e[i].w)w[v]+=w[u];
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w,w[v]=1;
				if(!vis[v]){vis[v]=1;q.push(v);}
			}
		}
	}
	for(int k=1;k<=n;++k)if(w[k]==2)ans[k][i]=ans[i][k]=1;//printf("%d ",w[k]);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;scanf("%d%d",&c,&t);
    while(t--){
        rink();
        for(int i=1;i<=n;++i)spfa(i);
        int res=0;
        for(int i=1;i<=n;++i)
        	for(int j=i;j<=n;++j)
        		if(ans[i][j])++res;
		printf("%d\n",res);
	} 
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
// 0 2
// 5 3
// -2 -1 0 1 2
// 6 2
// -4 -3 -2 -1 3 6
