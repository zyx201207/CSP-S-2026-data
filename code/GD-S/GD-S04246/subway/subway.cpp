#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+5,T=5e5+5;
long long c,m,n,D,Q,w[N],d[N],vis[N];
struct mc{
	int u,w;
	friend bool operator < (mc x,mc y){
		return x.w<y.w;
	}
	friend bool operator > (mc x,mc y){
		return x.w>y.w;
	}
};
struct Node{
	long long v,w;
};
vector <Node> e[N];
priority_queue < mc, vector<mc>, greater<mc> > q;
void dij(int st,int en){
	q.push({st,0});
	memset(d,1,sizeof(d));
	d[st]=0;
	while(!q.empty()){
		mc f=q.top();
		q.pop();
		int u=f.u;
		if(vis[u]) continue;
		if(d[u]<f.w) continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].v,w=e[u][i].w;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({v,d[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>D>>Q;
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++){
		int ni;
		scanf("%lld",&ni);
		int u=n+i+1;
		for(int j=0;j<ni;j++){
			int v,w;
			scanf("%lld%lld",&v,&w);
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
	} //cout<<"PPP";
	while(Q--){
		int start,end;
		scanf("%lld%lld",&start,&end);
		if(start==end) {
			cout<<"0\n";
			continue;
		}
//		e[0].push_back({start,w[start]});
//		e[end].push_back({n+1,w[end]});
		dij(start,end);
		int ans=d[end]+w[start]+w[end];
		printf("%lld\n",ans);
//		for(int i=1;i<=n;i++) cout<<d[i]<<' ';
//		cout<<"\n";
		memset(vis,0,sizeof(vis));
	}
	return 0;
} 
