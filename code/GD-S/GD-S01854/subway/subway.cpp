#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
struct ed{
	long long nxt,to,val;
}pho[N];
long long idx,head[N];
void add(long long x,long long y,long long z){
	pho[++idx].nxt=head[x];
	pho[idx].to=y;
	pho[idx].val=z;
	head[x]=idx;
}
long long c,n,m,d,q,w[N],dist[N],vis[N];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > qu;
void dijkstral(long long s){
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	dist[s]=0;
	qu.push(make_pair(0,s));
	while(!qu.empty()){
		pair<long long,long long> uq=qu.top();
		long long u=uq.second;
		qu.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(long long i=head[u];~i;i=pho[i].nxt){
			long long tp=pho[i].to;
			if(dist[tp]>dist[u]+pho[i].val){
				dist[tp]=dist[u]+pho[i].val;
				qu.push(make_pair(dist[tp],tp));
			}
		}
	}
}
long long vd[N][25];
struct eq{
	long long x,r,id;
}qr[N];
long long res[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(head,-1,sizeof head);
	memset(res,0x3f,sizeof res);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			long long a,t;
			scanf("%lld%lld",&a,&t);
			add(i+m,a,t);
			add(a,i+m,t);
			vd[a][i]=t;
		}
	}
	for(long long i=1;i<=q;i++){
		scanf("%lld%lld",&qr[i].x,&qr[i].r);
		qr[i].id=i;
	}
	for(long long i=1;i<=n;i++){
		dijkstral(i+m);
		for(long long j=1;j<=q;j++){
			if(vd[qr[j].x][i]==0)continue;
			res[qr[j].id]=min(res[qr[j].id],w[qr[j].x]+w[qr[j].r]+vd[qr[j].x][i]+dist[qr[j].r]);
		}
	}
	for(long long i=1;i<=q;i++){
		printf("%lld\n",res[i]);
	}
	return 0;
}
