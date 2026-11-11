#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<int,int>
const int M=5e6;
const int Q=1e5+5;
const int INF=0x3f3f3f3f;
int c,n,m,d,q;
int jcw[M];
int k;
int cnt=0;
int head[M];
int dis[M];
int vis[M];
int ans[Q];
struct R{
	int to;
	int w;
	int next;
}mp[M];
struct srd{
	int ff;
	int ww;
}srdx[M];
struct srq{
	int f1,s2,t3;
}qu[Q];
bool cmpq1(srq x,srq y){
	return x.f1<y.f1;
}
void add_edge(int u,int v,int w){
	mp[++cnt].to=v;
	mp[cnt].w=w;
	mp[cnt].next=head[u];
	head[u]=cnt;
}
void dij(int u,int v){
	
	priority_queue<PII,vector<PII>,greater<PII>>pq;
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[u]=0;
	pq.push({dis[u],u});
	while(!pq.empty()){
		PII PQ=pq.top();
		pq.pop();
		if(vis[PQ.second]){
			continue;
		}
		vis[PQ.second]=1;
		for(int i=head[PQ.second];i;i=mp[i].next){
			if(PQ.first+mp[i].w<dis[mp[i].to]){
				dis[mp[i].to]=PQ.first+mp[i].w;
				pq.push({dis[mp[i].to],mp[i].to});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){

		scanf("%d",&jcw[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&srdx[j].ff,&srdx[j].ww);
		}
		for(int j=1;j<=k-1;j++){
			for(int z=j+1;z<=k;z++){
				int uu=srdx[j].ff;
				int vv=srdx[z].ff;
				int ww=srdx[j].ww+srdx[z].ww;
				add_edge(uu,vv,ww);
				add_edge(vv,uu,ww);
			}
		}
		
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qu[i].f1,&qu[i].s2);
		int ttemp;
		if(qu[i].s2<qu[i].f1){
			ttemp=qu[i].s2;
			qu[i].s2=qu[i].f1;
			qu[i].f1=ttemp;
		}
		qu[i].t3=i;
		
	}
	sort(qu+1,qu+q+1,cmpq1);
	for(int i=1;i<=q;i++){
		if(qu[i].f1!=qu[i-1].f1){
			dij(qu[i].f1,qu[i].s2);
		}
		ans[qu[i].t3]=dis[qu[i].s2]+jcw[qu[i].f1]+jcw[qu[i].s2];
		
	}
	for(int i=1;i<=q;i++)
	printf("%d\n",ans[i]);
	
	return 0;
}
