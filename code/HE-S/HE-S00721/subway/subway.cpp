#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5;
int c, n, m, d, sum, b[M];
struct Edge{
	int v;
	long long w;
	bool operator<(const Edge &s)const{return s.w<w;}
};
struct questions{
	int k, x, y;
//	bool operator<(const questions &s)const{return s.x<x;}
}ask[M];
bool cmp(questions a,questions b){
	return a.x<b.x;
}
vector<Edge> e[M], a;
long long dist[M], ans[M];
void dij(int rt){
//	cout<<11111;
	priority_queue<Edge> q;
	bool vis[M];
	for(int i=1;i<=m;i++)dist[i]=1e18, vis[i]=0;
	dist[rt]=0;
	q.push({rt,0});
//	cout<<q.top().v;
	while(!q.empty()){
		int p=q.top().v;
		long long num=q.top().w;
		q.pop();
//		cout<<p<<" ";
		if(vis[p]==1)continue;
		vis[p]=1;
		for(auto i:e[p]){
			int _v=i.v, _w=i.w;
			if(dist[_v]>num+_w){
				dist[_v]=num+_w;
			}
			q.push({_v,dist[_v]});
		}
	}
//	for(int i=1;i<=m;i++)cout<<dist[i]<<" ";
//	cout<<endl;
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&sum);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		int _u=0, _v, uw=0, vw;
//		for(int j=1;j<=k;j++){
//			scanf("%d%d",&_v,&vw);
//			if(_u!=0){
//				e[_u].push_back({_v,uw+vw});
//				e[_v].push_back({_u,uw+vw});
//			}
//			_u=_v,uw=vw;
//		}
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&_v,&vw);
			a.push_back({_v,vw});
		}
		for(auto x:a){
			for(auto y:a){
				if(x.v==y.v)continue;
				e[x.v].push_back({y.v,x.w+y.w});
			}
		}
		a.clear();
	}
	
//	for(int i=1;i<=m;i++){
//		cout<<i<<": ";
//		for(auto j:e[i])cout<<j.v<<" ";
//		cout<<endl;
//	}
	for(int i=0;i<sum;i++){
		scanf("%lld%lld",&ask[i].x,&ask[i].y);
//		cin>>ask[i].x>>ask[i].y;
		ask[i].k=i+1;
	}
	sort(ask,ask+sum,cmp);
	int xx=0;
	for(int i=0;i<sum;i++){
		if(ask[i].x!=xx){
			xx=ask[i].x;
			dij(xx);
		}
		ans[ask[i].k]=dist[ask[i].y]+b[ask[i].x]+b[ask[i].y];
	}
	for(int i=1;i<=sum;i++)printf("%lld\n",ans[i]);//cout<<ans[i]<<endl;
	return 0;
}
