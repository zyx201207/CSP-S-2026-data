#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int c,n,m,d,q;
int w[500005],k[505];
struct Edge{
	int v,next;
	long long w;
}e[1000005];
int head[500005];
int idx=1;
void add(int u,int v,int w){
	e[idx].v=v;
	e[idx].w=w;
	e[idx].next=head[u];
	head[u]=idx++;
}
long long dist[500005];
bool st[500005];
void dij(int s){
	memset(dist,0x3f3f,sizeof dist);
	memset(st,false,sizeof st);
	priority_queue<PII,vector<PII>,greater<PII> > heap;
	dist[s]=0;
	heap.push({0,s});
	while(!heap.empty()){
		PII t=heap.top();
		heap.pop();
		int ver=t.second;
		if(st[ver])continue;
		st[ver]=true;
		for(int i=head[ver];i;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dist[v]>dist[ver]+w){
				dist[v]=dist[ver]+w;
				heap.push({dist[v],v});
			}
		}
	}
}
void bfs(int s,int t){
	memset(dist,0,sizeof dist);
	memset(st,false,sizeof st);
	queue<int> q;
	q.push(s);
	st[s]=true;
	while(!q.empty()){
		int ver=q.front();
		q.pop();
		for(int i=head[ver];i;i=e[i].next){
			int v=e[i].v;
			if(!st[v]){
				st[v]=true;
				q.push(v);
				dist[v]=dist[ver]+1; 
				if(v==t)return ;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int v;
			long long w;
			scanf("%d%lld",&v,&w);
			add(i+m,v,w);
			add(v,i+m,w);
		}
	}
	if(c>=12&&c<=19){
		for(int i=1;i<=q;i++){
			int s,t;
			scanf("%d%d",&s,&t);
			bfs(s,t);
			printf("%lld\n",dist[t]*e[i].w+w[s]+w[t]);
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		dij(s);
		printf("%lld\n",dist[t]+w[s]+w[t]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
