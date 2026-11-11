#include<bits/stdc++.h>
#define N 502010
#define ll long long
using namespace std;
int c,n,m,d,q1;
int tot=0,to[N],nxt[N],h[N];
ll w1[N],w[N],d1[N],ans;
bool vis[N];
struct node{
	int u;
	ll dis;
	bool friend operator<(node a,node b){
		return a.dis>b.dis;
	}
}tmp;
priority_queue<node> q;
void add(int a,int b,ll c){
	to[++tot]=b;
	nxt[tot]=h[a];
	w1[tot]=c;
	h[a]=tot;
}
ll dij(int s,int t){
	for(int i=1;i<=N;i++){
	    d1[i]=100000000000000000;
	    vis[i]=0;
    }
	d1[s]=tmp.dis=0;
	tmp.u=s;
	q.push(tmp);
	while(!q.empty()){
		tmp=q.top();
		q.pop();
		int u=tmp.u;
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			if(d1[v]>d1[u]+w1[i]){
				d1[v]=d1[u]+w1[i];
				tmp.u=v;
				tmp.dis=d1[v];
				q.push(tmp);
			}
		}
	}
	return d1[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q1);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k,a;
		ll t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&a,&t);
			add(a,m+i,t);
			add(m+i,a,t);
		}
	}
	while(q1--){
		int x,y;
		scanf("%d%d",&x,&y);
		ans=dij(x,y)+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
