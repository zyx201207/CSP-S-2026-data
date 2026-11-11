#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL inf=1e14;
const int maxn=10000;
LL dis[maxn],w[maxn];
bool vis[maxn];
int c,n,m,d,q,cnt,tot;
int head[maxn];
struct node{
	int to,next;
	LL w;
}a[maxn];
struct road{
	int v;LL w;
	bool operator<(const road &x)const{
		return w>x.w;
	}
};
struct question{
	int st,en,num;
	LL ans;
}b[202];
bool cmp(question g,question h){
	return g.st<h.st;
}
bool cmp2(question g,question h){
	return g.num<h.num;
}
priority_queue<road>que;
void add(int u,int v,LL w){
	a[++cnt].to=v;
	a[cnt].next=head[u];
	a[cnt].w=w;
	head[u]=cnt;
}
void init(){
	for(int i=1;i<=tot;i++)
		dis[i]=inf,vis[i]=0;
}
void Dijkstra(int &s){
	dis[s]=0;
	que.push({s,0});
	while(!que.empty()){
		int u=que.top().v;que.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=a[i].next){
			int v=a[i].to;
			if(dis[v]>dis[u]+a[i].w){
				dis[v]=dis[u]+a[i].w;
				que.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	tot=m;
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int it;LL t;
			scanf("%d %lld",&it,&t);
			add(it,++tot,t);
			add(tot,it,t);
			if(j>=2){
				add(tot-1,tot,0);
				add(tot,tot-1,0);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&b[i].st,&b[i].en);
		b[i].num=i;
		if(b[i].st>b[i].en)swap(b[i].st,b[i].en);
	}
	if(c<=8){
		sort(b+1,b+q+1,cmp);
		for(int i=1;i<=q;i++){
			if(i==1||b[i].st!=b[i-1].st){
				init();
				Dijkstra(b[i].st);
			}
			b[i].ans=dis[b[i].en]+w[b[i].st]+w[b[i].en];
		}
		sort(b+1,b+q+1,cmp2);
		for(int i=1;i<=q;i++)printf("%lld\n",b[i].ans);
	}
	return 0;
}
