#include<bits/stdc++.h>
using namespace std;
#define int long long
char buf[1<<21],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2){
		p2=(p1=buf)+fread(buf,1,1<<1,stdin);
		if(p1==p2) return EOF;
	}
	return *p1++;
}
inline int read(){
	int x=0,f=1;
	char c=gc();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=gc(); 
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=gc();
	}
	return x*f;
}
const int M=5e5+10,N=504;
int c,n,m,d,q,x,y,w[M],k[M],dis[M];
vector<int> a[N],t[N],l[M];
bool vis[M];
int dijkstra(int x,int y){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; 
	dis[x]=0,q.push({0,x});
	while(!q.empty()){
		int d=q.top().first,u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int z:l[u])
			for(int v:a[z])
				if(dis[v]>d+t[z][u]+t[z][v] && v!=u)
					dis[v]=d+t[z][u]+t[z][v],q.push({dis[v],v});
	}
	return dis[y]+w[x]+w[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++)
			x=read(),y=read(),a[i].push_back(x),t[i].push_back(y),l[x].push_back(i);
	}
	while(q--){
		x=read(),y=read();
		cout<<dijkstra(x,y)<<"\n";
	}
	return 0; 
} 
