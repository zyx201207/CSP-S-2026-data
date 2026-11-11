#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e15; 
const int N=5e2+5;
const int M=1e6+5;
const int V=5e6+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
		(c=='-')?(f=-1):(f=f),c=getchar();
	while(isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}void write(ll x){
	if(x<0)
		putchar('-'),x=-x;
	if(x<10)
		putchar(x+'0');
	else
		write(x/10),putchar(x%10+'0');
	return;
}int cnt,nxt[V],val[V],to[V],h[M];
void add(int a,int b,int c){
	++cnt;
	nxt[cnt]=h[a];
	val[cnt]=c;
	to[cnt]=b;
	h[a]=cnt;
	return;
}ll dis[M];
bool visd[M];
int c,n,m,d,T;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
void solve(int st){
	while(!q.empty())
		q.pop();
	for(int i=1;i<=(m*(d+d));++i)
		dis[i]=INF,visd[i]=false;
	dis[st]=0;
	q.push(make_pair(dis[st],st));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(visd[u])
			continue;
		visd[u]=1;
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>dis[u]+val[i]||(dis[v]==dis[u]&&val[i]==0))
				dis[v]=dis[u]+val[i],q.push(make_pair(dis[v],v));
		}
	}return;
}int w[M];
ll query(int u,int v){
	solve(u);
	return dis[v]+w[u]+w[v];
}int u,v;
int a[N],t[N],k[N],siz[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),T=read();
	for(int i=1;i<=m;++i)
		w[i]=read();
	for(int i=1;i<=n;++i){
		k[i]=read();
		for(int j=1;j<=k[i];++j)
			a[j]=read(),t[j]=read(),++siz[a[j]];
		for(int j=1;j<=k[i];++j){
			if(j!=k[i])
				add(a[j]+a[j]*d+siz[a[j]],a[j+1]+a[j+1]*d+siz[a[j+1]],0);//a[j]+a[j]*d+siz[a[j]]为a[j]在线路i上的站台编号 
			add(a[j],a[j]+a[j]*d+siz[a[j]],t[j]),add(a[j]+a[j]*d+siz[a[j]],a[j],t[j]);//a[j]为a[j]点的站厅编号 
		}
	}for(int i=1;i<=T;++i)
		u=read(),v=read(),write(query(u,v)),putchar('\n'); 
	return 0;
}

