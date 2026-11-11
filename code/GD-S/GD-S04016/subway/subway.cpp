#include<bits/stdc++.h>
using namespace std;
long long c,n,m,D,q,w[500100],h[500100],num,f,vis[500010],k[500010];
vector<long long>a[5010];
vector<long long>t[5010];
long long d[2010][2010];
struct node{
	long long v,w,nex;
}e[2000100];
void add(long long u,long long v,long long w){
	e[++num].v=v;
	e[num].w=w;
	e[num].nex=h[u];
	h[u]=num;
}
void dj(long long s){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
	q.push(make_pair(0,s));
	for (long long i=1;i<=m;i++){
		if (i!=s){
			d[s][i]=1e18;
		}
		vis[i]=0;
	}
	d[s][s]=0;
	while(!q.empty()){
		long long u=q.top().second,minn=q.top().first;
		q.pop();
		if (vis[u])continue;
		vis[u]=1;
		for(long long i=h[u];i;i=e[i].nex){
			long long v=e[i].v;
			if (d[s][v]>minn+e[i].w){
				d[s][v]=minn+e[i].w;
				q.push(make_pair(d[s][v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&D,&q);
	for (long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for (long long i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for (long long j=1;j<=k[i];j++){
			long long aa,tt;
			scanf("%lld%lld",&aa,&tt);
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
		if (k[i]>2)f=1;
	}
	if (f==0){
		for (long long i=1;i<=n;i++){
			if (k[i]<2)continue;
			add(a[i][0],a[i][1],t[i][0]+t[i][1]);
			add(a[i][1],a[i][0],t[i][0]+t[i][1]);
		}
		for (long long i=1;i<=m;i++){
			dj(i);
		}
		while(q--){
			long long u,v;
			scanf("%lld%lld",&u,&v);
			printf("%lld\n",d[u][v]+w[u]+w[v]);
		}
	}else{
		for (long long i=1;i<n;i++){
			for (long long j=i+1;j<=n;j++){
				for (int k1=0;k1<a[i].size();k1++){
					for (int k2=0;k2<a[j].size();k2++){
						if (a[i][k1]==a[j][k2]){
							add(a[i][k1-1],a[j][k2+1],w[a[i][k1-1]]+w[a[j][k2+1]]+t[i][k1]+t[j][k2]);
							add(a[j][k2+1],a[i][k1-1],w[a[i][k1]]+w[a[j][k2]]+t[i][k1]+t[j][k2]);
						}
					}
				}
			}
		}
		for (long long i=1;i<=m;i++){
			dj(i);
		}
		while(q--){
			long long u,v;
			scanf("%lld%lld",&u,&v);
			printf("%lld\n",d[u][v]+w[u]+w[v]);
		}
	}
	return 0;
}
