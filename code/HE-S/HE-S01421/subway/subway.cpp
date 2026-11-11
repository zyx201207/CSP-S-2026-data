#include<bits/stdc++.h>
using namespace std;
#define ll long long
const unsigned long long N=1e7+5;
ll c,n,m,d,q,tl,dis[500100],ans[500100];
unsigned long long head[N];
bool bl[500100];
struct node{
	ll xt,to,vl;
}dg[N];
struct Node{
	ll uu,vv,as;
}jh[500100];
bool cmp(Node x,Node y){
	return x.uu>y.vv;
}
struct nnode{
	ll pt,pv;
	bool operator > (const nnode &nd)const{
		return pv>nd.pv;
	}
};
void add(ll u,ll v,ll w){
	tl++;
	dg[tl].xt=head[u];
	head[u]=tl;
	dg[tl].to=v;
	dg[tl].vl=w;
	return ;
}
priority_queue<nnode,vector <nnode> ,greater <nnode> > pq;
void dij(){
	while(!pq.empty()){
		nnode uuu=pq.top();
		ll u=uuu.pt;
		pq.pop();
		if(bl[u]==1)continue ;
		for(int i=head[u];i;i=dg[i].xt){
			ll v=dg[i].to;
			if(dis[v]>dis[u]+dg[i].vl){
				dis[v]=dis[u]+dg[i].vl;
				pq.push((nnode){v,dis[v]});
			}
		}
		bl[u]=1;
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	//printf("%lld %lld %lld %lld %lld\n",c,n,m,d,q);
	ll u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w);
		add(i,i+m,w);
		add(i+m,i,w);
	}
	ll k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&v,&w);
			add(2*m+i,v+m,w);
			add(v+m,2*m+i,w);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&jh[i].uu,&jh[i].vv);
		jh[i].as=i;
	}
	sort(jh+1,jh+q+1,cmp);
	for(int i=1;i<=q;i++){
		if(i!=1&&jh[i].uu==jh[i-1].uu)ans[jh[i].as]=dis[jh[i].vv];
		else{
			memset(dis,0x7f,sizeof(dis));
			memset(bl,0,sizeof(bl));
			dis[jh[i].uu]=0;
			pq.push((nnode){jh[i].uu,0});
			//bl[jh[i].uu]=1;
			dij();
			ans[jh[i].as]=dis[jh[i].vv];
		}
	}
	
//	for(int i=1;i<=m;i++){
//		printf("%lld\n",dis[i]);
//	}
	
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
	
	/*
	 0 2 5 20 2
	 4 1 9 2 5
	 3 1 5 2 7 4 6
	 3 2 3 3 4 5 7
	 1 3
	 1 2
	*/	
	return 0;
} 
