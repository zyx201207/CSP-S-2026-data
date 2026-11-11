#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=500005;
struct nd{
	int u,w;
	bool operator>(nd other)const{
		return w>other.w;
	}
};
vector<nd> mp[N+M];
int a[M];
int dis[M+N];
bool vis[N+M];
int c,n,m,d,q;
void clear(){
	for(int i=0;i<N+M;i++) mp[i].clear();
	memset(a,0,sizeof(a));

}
int solve(int u,int v){
	priority_queue<nd,vector<nd>,greater<nd>> q;
	q.push({u,0});	
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n+m;i++) dis[i]=1e18;
	dis[u]=0;
	while(!q.empty()){
		auto f=q.top();
		q.pop();
		if(vis[f.u]) continue;
		vis[f.u]=1;
		for(auto k : mp[f.u]){
			int nxt=k.u;
			int ds=f.w+k.w;
			if(ds<dis[nxt]){
				dis[nxt]=ds;
				q.push({nxt,ds});
			}
		}
	}
	return dis[v];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int k;scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int u,w;scanf("%lld%lld",&u,&w);
			mp[i].push_back({u+n,w});
			mp[u+n].push_back({i,w});
		}
	}
	while(q--){
		int u,v;scanf("%lld%lld",&u,&v);
		printf("%lld\n",solve(u+n,v+n)+a[u]+a[v]);
	}
}
/*131 136*/
