#include<bits/stdc++.h>
#define LL long long
using namespace std;
char buf[1<<22],*p1=buf,*p2=buf;
inline int read(){
	int x=0,f=1;
	char ch;
	while(1){
		if(p1==p2){p2=(p1=buf)+fread(buf,1,1<<20,stdin);if(p1==p2)return EOF;}
		ch=*p1++;
		if(ch>='0'&&ch<='9')break;
		if(ch=='-')f=-1;
	}
	while(1){
		x=x*10+(ch^48);
		if(p1==p2){p2=(p1=buf)+fread(buf,1,1<<20,stdin);if(p1==p2)break;}
		ch=*p1++;
		if(ch<'0'||ch>'9')break;
	}
	return x;
}
int c,n,m,d,Q;
int w[500005];
int t[505][500005];
struct edge{int v,ne,w;}e[510055],E[1000005];
int idx,h[505],tot,H[500505];
inline void add(int u,int v,int w){
	e[++idx]={v,h[u],w};h[u]=idx;
}
inline void Add(int u,int v){
	E[++tot]={v,H[u]};H[u]=tot;
}
LL dis[505][505];
inline void Dijkstra(int r){
	priority_queue<pair<LL,int> >q;
	q.push({LLONG_MAX,r});dis[r][r]=0;
	while(!q.empty()){
		pair<LL,int>p=q.top();q.pop();
		int u=p.second;
		LL d=LLONG_MAX-p.first;
		if(dis[r][u]<d)continue;
		for(int i=h[u];i;i=e[i].ne){
			int v=e[i].v,w=e[i].w;
			if(v<=0||dis[r][v]<=d+w)continue;
			q.push({LLONG_MAX-d-w,v});dis[r][v]=d+w;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k;
		k=read();
		for(int j=1;j<=k;j++){
			int x;
			x=read(),t[i][x]=read();
			Add(x,i+m);
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=H[i];j;j=E[j].ne){
			int u=E[j].v-m;
			for(int k=H[i];k;k=E[k].ne){
				int v=E[k].v-m;
				if(u==v)continue;
				add(u,v,t[u][i]+t[v][i]);
			}
		}
	memset(dis,0x3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++)Dijkstra(i);
	while(Q--){
		int x,y;
		LL ans=LONG_LONG_MAX;
		x=read(),y=read();
		for(int i=H[x];i;i=E[i].ne){
			int u=E[i].v-m;
			for(int j=H[y];j;j=E[j].ne){
				int v=E[j].v-m;
				ans=min(ans,dis[u][v]+t[u][x]+t[v][y]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
