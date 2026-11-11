#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+10;
int ID,n,m,d,Q,idx,h[N],u[N],w[N],dis[N][3];
queue<int> q;
struct node{
	int x,y,id;
}ans[N];
struct egde{
	int to,w,nxt;
}e[N<<1];
void add(int u,int v,int w){
	++idx;
	e[idx].to=v;
	e[idx].w=w;
	e[idx].nxt=h[u];
	h[u]=idx;
	return ;
}
void spfa(int s,int id){
	q.push(s);
	for (int i=1;i<=n+m;i++) dis[i][id]=1e18;
	dis[s][id]=0;
	while (!q.empty()){
		int x=q.front();
		u[x]=0;
		q.pop();
		for (int i=h[x];i;i=e[i].nxt){
			int y=e[i].to;
			int w=e[i].w;
			if (dis[y][id]>dis[x][id]+w){
				dis[y][id]=dis[x][id]+w;
				if (!u[y]){
					u[y]=1;
					q.push(y);
				}
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf ("%lld%lld%lld%lld%lld",&ID,&n,&m,&d,&Q);
	for (int i=1;i<=m;i++) scanf ("%lld",&w[i]);
	for (int i=1;i<=n;i++){
		int k;
		scanf ("%lld",&k);
		for (int j=1;j<=k;j++){
			int a,t;
			scanf ("%lld%lld",&a,&t);
			add(a,m+i,t);
			add(m+i,a,t);
		}
	}
//	spfa(1,1);
//	spfa(n,2);
	for (int i=1;i<=Q;i++)
	{
		int u,v;
		scanf ("%lld%lld",&u,&v);
		spfa(u,0);
		printf ("%lld\n",dis[v][0]+w[u]+w[v]);
//		printf ("%lld\n",dis[n][1]-dis[u][1]-dis[v][1]+w[u]+w[v]);
	}
	return 0;
}

