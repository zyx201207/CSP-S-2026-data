#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M=5e5+5,Q=1e5+5;
ll w[M],t[M],cost[M],ans[Q];
int a[M],st,zd,cnt;
bool vis[M];

struct lpr{
	int u,v;
	ll w;
};
map<pair<int,int> ,lpr> al;

inline void add(int x,int y,ll lc){
//	if(al[{x,y}]==NULL) al[{x,y}]=lc;
//	else
	if(al[{x,y}].w==0||lc<al[{x,y}].w) al[{x,y}].w=lc,al[{x,y}].u=x,al[{x,y}].v=y;
//	a_l[cnt].u=x,a_l[cnt].v=y,a_l[cnt].w=lc;
//	++cnt;
}
//inline bool cmp2(lpr x,lpr y){
//	if(x.u==y.u){
//		if(x.v==y.v) return x.w<y.w;
//		return x.v<y.v;
//	}
//	return x.u<y.u;
//}

struct node{
	int to;
	ll w;
};
vector<node> e[M];

struct data{
	int x,y,bh;
}que[Q];
inline bool cmp(data x,data y){return x.x<y.x;}

void dijk(){
	priority_queue<pair<ll,int> > q;
	cost[st]=0;
	vis[st]=1;
	for(auto now:e[st])
		q.push({now.w*-1,now.to});
	while(!q.empty()){
		ll w=q.top().first*-1;
		int v=q.top().second;
		q.pop();
		if(vis[v]) continue;
		vis[v]=1;
		cost[v]=w;
		for(auto nxt:e[v]){
			if(!vis[nxt.to])
				q.push({(cost[v]+nxt.w)*-1,nxt.to});
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%lld",w+i);
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j)
			scanf("%d%lld",a+j,t+j);
		for(int j=1;j<k;++j){
			for(int o=j+1;o<=k;++o){
				if(a[j]>a[o]) add(a[o],a[j],t[j]+t[o]);
				add(a[j],a[o],t[j]+t[o]);
			}
		}
	}
//	sort(a_l,a_l+cnt,cmp2);
//	for(int i=0;i<cnt;++i){
//		ll lc=a_l[i].w;
//		int u=a_l[i].u,v=a_l[i].v;
//		if(i&&u!=a_l[i-1].u)
//			fill(vis+1,vis+1+m,0);
//		
//		if(!vis[v]){
//			e[u].push_back(node{v,lc});
//			e[v].push_back(node{u,lc});
//			vis[v]=1;
//		}
//	}
	for(auto l:al){
		e[l.second.u].push_back(node{l.second.v,l.second.w});
		e[l.second.v].push_back(node{l.second.u,l.second.w});
	}
	
	for(int i=1;i<=q;++i){
		scanf("%d%d",&que[i].x,&que[i].y);
		if(que[i].x>que[i].y) swap(que[i].x,que[i].y);
		que[i].bh=i;
	}

	sort(que+1,que+1+q,cmp);
	int ost=-1;
	for(int i=1;i<=q;++i){
		st=que[i].x,zd=que[i].y;
		if(st==ost){
			ans[que[i].bh]=cost[zd]+w[st]+w[zd];
			continue;
		}
		fill(vis+1,vis+1+m,0);
		dijk();
		ans[que[i].bh]=cost[zd]+w[st]+w[zd];
		ost=st;
	}
	for(int i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
	return 0;
}
