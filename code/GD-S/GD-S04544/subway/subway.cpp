#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

#define int long long

using namespace std;

const int M=5e5+5;
const int inf=1e18;

struct edge{
	int fr,to,val,nxt;
};

edge a[M<<1];
int had[M],tot;

void build(int u,int v,int w){
	a[++tot]={u,v,w,had[u]};
	had[u]=tot;
}

int c,n,m,d,q;

int w[M];

int dis[M];

void dij(int s){
	
	for(int i=1;i<=m+n;i++){
		dis[i]=inf;
	}
	
	dis[s]=0;
	
	priority_queue<pair<int,int>> q;
	
	q.push(make_pair(0,s));
	
	while(!q.empty()){
		int u=q.top().second;
		int w=-q.top().first;
		
		q.pop();
		
		if(w>dis[u])continue;
		
		for(int i=had[u];i;i=a[i].nxt){
			int v=a[i].to;
			
			if(dis[u]+a[i].val<dis[v]){
				dis[v]=dis[u]+a[i].val;
				q.push(make_pair(-dis[v],v));
			}
			
		}
		
	}
}

//void dfs(int s,int w,int fa){
//	if(w>dis[s])return;
//	for(int i=had[s];i;i=a[i].nxt){
//		int v=a[i].to;
//		if(v==fa)continue;
//		if(dis[s]+a[i].val<dis[v]){
//			dis[v]=dis[s]+a[i].val;
//			dfs(v,dis[v],s);
//		}
//	}
//	
//}

struct qry{
	int s,t,id;
};

qry b[M];

int ans[M];

bool cmp(qry A,qry B){
	return A.s<B.s;
}

int sum[M];

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			build(x,m+i,y);
			build(m+i,x,y);
		} 
	}
	
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&b[i].s,&b[i].t);
		sum[b[i].s]++;
		sum[b[i].t]++;
		b[i].id=i;
	}
	
	for(int i=1;i<=q;i++){
		if(sum[b[i].s]<sum[b[i].t]){
			swap(b[i].s,b[i].t);
		}
	}
	
	sort(b+1,b+q+1,cmp);
	
	for(int i=1;i<=q;i++){
		if(b[i].s!=b[i-1].s){
			dij(b[i].s);
		}
		ans[b[i].id]=w[b[i].s]+w[b[i].t]+dis[b[i].t];
	}
	
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
	
	return 0;
}


