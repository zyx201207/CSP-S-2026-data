#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int read(){
	char ch=getchar();
	int x=0,y=1,cnt=5;
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'&&cnt){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*y;
}
int head[N],to[N],ne[N],id,w[N];
void add(int x,int y,int z){
	to[++id]=y,ne[id]=head[x],head[x]=id,w[id]=z;
}
struct node{
	int id,num;
	operator <(const node &a)const{
		return num>a.num;
	}
};
vector<node> vc[N];
int c,n,m,d,q;
ll a[N],ans;
int dis[505],vis[505];
ll bfs(int x,int y){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	dis[x]=0;
	q.push((node){x,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		if(vis[t.id]||dis[t.id]!=t.num) continue;
		int u=t.id;
		vis[u]=1;
		for(int i=head[u];i;i=ne[i]){
			int v=to[i];
			if(!vis[v]&&dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				q.push((node){v,dis[v]});
			}
		}
	}
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		a[i]=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=1,x,y;j<=k;j++){
			x=read(),y=read();
			vc[x].push_back((node){i,y});
		}
	}
	for(int i=1;i<=m;i++){
		if(vc[i].size()>1){
			for(int j=1;j<vc[i].size();j++){
				for(int k=0;k<j;k++){
					add(vc[i][j].id,vc[i][k].id,vc[i][j].num+vc[i][k].num);
					add(vc[i][k].id,vc[i][j].id,vc[i][j].num+vc[i][k].num);
				}
			}
		}
	}
	int x,y;
	while(q--){
		x=read(),y=read();
		ans=INF;
		for(int i=0;i<vc[x].size();i++){
			for(int j=0;j<vc[y].size();j++){
				ans=min(ans,vc[x][i].num+vc[y][j].num+bfs(vc[x][i].id,vc[y][j].id));
			}
		}
		printf("%lld\n",a[x]+a[y]+ans); 
	}
	return 0;
}
