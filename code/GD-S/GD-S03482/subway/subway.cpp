#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
int n,m,w[maxn],d,q,c;
ll dis[maxn];
vector<pair<ll,int>> g[maxn];
vector<pair<ll,int>> fs;
bool used[maxn];
void dij(ll x) {
	memset(used,0,sizeof(used));
	memset(dis,0x3f3f3f3f,sizeof(dis));
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> qq;
	qq.push({0,x});
	dis[x]=0;
	while(!qq.empty()) {
		int v=qq.top().second;
		qq.pop();
		if(used[v]) continue;
		used[v]=1;
		int l=g[v].size();
		for(int i=0;i<l;i++) {
			int u=g[v][i].second;
			ll ddd=g[v][i].first;
			if(dis[u]>dis[v]+ddd) {
				dis[u]=dis[v]+ddd;
				qq.push({dis[u],u});
			}
		}
	}
	return;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//c=read(),n=read(),m=read(),d=read(),q=read();
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	//for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) {
		int k=0,dd=0,lam=0;
		scanf("%d%d%d",&k,&lam,&dd);
		fs.clear();
		fs.push_back({dd,lam});
		//ll k=read(),x=read(),y=read(),la=y,lam=x;
		for(int j=1;j<k;j++) {
			//x=read(),y=read();
			int x=0,y=0;
			scanf("%d%d",&x,&y);
			int mm=fs.size();
			for(int i=0;i<mm;i++) {
				ll dis=fs[i].first+y;
				int nn=fs[i].second;
				g[x].push_back({dis,nn});
				g[nn].push_back({dis,x});
			}
			//cout <<i<<" "<<dis<<" "<<lam<<" "<<x<<" ";
			fs.push_back({y,x});
		}
	}
	while(q) {
		q--;
		int x=0,y=0;
		scanf("%d%d",&x,&y);
		dij(x);
		ll ans=dis[y]+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
