#include <bits/stdc++.h>
using namespace std;
const long long N=3e6+5,M=5005,oo=1e15,Q=1e5+5;
long long edge[N<<1],value[N<<1],nxt[N<<1],head[M],cnt,dis[M],n,m,c,d,q,wx[M],k,a[5*Q],x[5*Q],ans[Q];
struct node{
	long long x,y,id;
}r[Q];
bool cmp(node x1,node x2){
	return x1.x<x2.x;
}
void add(long long u,long long v,long long w){
	edge[++cnt]=v;
	value[cnt]=w;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
priority_queue<pair<long,long> >que;
void dijkstra(long long s){
	for (long long i=1;i<=m;i++)
		dis[i]=oo;
	dis[s]=0;
	que.push({0,s});
	while (!que.empty()){
		long long u=que.top().second,val=-que.top().first;
		que.pop();
		if (dis[u]<val)
			continue;
		for (long long i=head[u];i;i=nxt[i]){
			long long v=edge[i],w=value[i];
			if (dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				que.push({-dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf ("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (long long i=1;i<=m;i++)
		scanf ("%lld",&wx[i]);
	for (long long i=1;i<=n;i++){
		scanf ("%lld",&k);
		for (long long j=1;j<=k;j++){
			scanf ("%lld%lld",&a[j],&x[j]);
			for (long long l=1;l<j;l++){
				add(a[l],a[j],x[j]+x[l]);
				add(a[j],a[l],x[j]+x[l]);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		scanf ("%lld%lld",&r[i].x,&r[i].y);
		r[i].id=i;
	}
	sort (r+1,r+q+1,cmp);
	for (long long i=1;i<=q;i++){
		if (r[i].x==r[i-1].x){
			ans[r[i].id]=wx[r[i].x]+wx[r[i].y]+dis[r[i].y]; 
		}
		else{
			dijkstra(r[i].x);
			ans[r[i].id]=wx[r[i].x]+wx[r[i].y]+dis[r[i].y]; 
		}
	}
	for (long long i=1;i<=q;i++)
		printf ("%lld\n",ans[i]);
	return 0;
}
