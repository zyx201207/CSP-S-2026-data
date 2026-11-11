#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >q;
long long to[1001],nxt[1001],h[600001],cnt,vail[1001],n,m,d,q1,c,w[600001],bk[600001],dis[600001];
void add(long long a,long long b,long long c){
	cnt++;
	to[cnt]=b;
	vail[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q1);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		long long k,u,v,t1,t2;
		scanf("%lld%lld%lld%lld%lld",&k,&u,&t1,&v,&t2);
		add(u,v,t1+t2);
		add(v,u,t1+t2);
	}
	for(int k=1;k<=q1;k++){
		long long s,t;
		scanf("%lld%lld",&s,&t);
		for(int i=1;i<=m;i++){
			bk[i]=0;dis[i]=1e18;
		}
		dis[s]=w[s];
		q.push(make_pair(dis[s],s));
		while(!q.empty()){
			long long u=q.top().second;
			q.pop();
			if(bk[u]){
				continue;
			}
			bk[u]=1;
			for(int j=h[u];j!=0;j=nxt[j]){
				long long v=to[j];
				if(!bk[v]&&dis[v]>dis[u]+vail[j]){
					dis[v]=dis[u]+vail[j];
					q.push(make_pair(dis[v],v));
				}
			}
		}
		printf("%lld\n",dis[t]+w[t]);
	}
	return 0;
}
