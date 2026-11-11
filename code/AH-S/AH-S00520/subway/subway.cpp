#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=5e5+1000;
int c,n,m,d,t,W[N],dis[N],vis[N],ans[N];
bool pd;
vector<pair<int,int> >g[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
struct query{
	int a,b;
}qw[N];
void Dij(int s){
	dis[s]=0;
	pq.push(make_pair(dis[s],s));
	while(!pq.empty()){
		int u=pq.top().second;pq.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(vis[v])continue;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push(make_pair(dis[v],v));
			}
		}
	}
}
queue<pair<int,int> >qp;
void bfs(int s){
	dis[s]=0;
	qp.push(make_pair(dis[s],s));
	while(!qp.empty()){
		int u=qp.front().second;qp.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(vis[v])continue;
			dis[v]=dis[u]+w;
			qp.push(make_pair(dis[v],v));
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),t=read();
	for(int i=1;i<=m;i++){
		W[i]=read();
	}
	pd=true;
	int len,v,w,w0;
	for(int i=1;i<=n;i++){
		len=read();
		while(len--){
			v=read(),w=read();
			g[v].push_back(make_pair(m+i,w));
			g[m+i].push_back(make_pair(v,w));
			if(!w0)w0=w;
			else if(w!=w0)pd=false;
		}
	}
	for(int i=1;i<=t;i++){
		qw[i].a=read(),qw[i].b=read();
	}
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n;i++){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,false,sizeof(vis));
		if(!pd)Dij(m+i);
		else bfs(m+i);
		for(int j=1;j<=t;j++){
			ans[j]=min(ans[j],dis[qw[j].a]+dis[qw[j].b]+W[qw[j].a]+W[qw[j].b]);
		}
	}
	for(int i=1;i<=t;i++){
		write(ans[i]);
		putchar('\n');
	}
	return 0;
}
