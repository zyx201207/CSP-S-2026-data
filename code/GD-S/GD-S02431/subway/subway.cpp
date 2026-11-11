#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=1e5+10,P=2e4+10;
ll read(){
	ll res=0,F=1; char ch=getchar();
	for(;ch<'0' || ch>'9';ch=getchar()) 
		if(ch=='-') F=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())
		res=res*10+ch-'0';
	return res*F;
}


int c,n,m,d,Q,nxt=0;
ll w[N];
vector <pair<int,ll>> adj[N*2];
vector <int> sta[N];
int id[510],vis[N*2]; ll dis[510][P*2];
priority_queue <pair<ll,int>,
 				vector<pair<ll,int> >,
				greater<pair<ll,int>> > q;

void dijks(int s){
	for(int i=1;i<=nxt;i++) {
		dis[s][i]=1e18;
		vis[i]=0;
	}
	while(!q.empty()) q.pop();
	q.push({0,id[s]}); dis[s][id[s]]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<(int)adj[u].size();i++){
			int v=adj[u][i].first;
			ll D=adj[u][i].second;
			if(dis[s][v]>dis[s][u]+D) {
				dis[s][v]=dis[s][u]+D;
				q.push({dis[s][v],v});
			}
		}
	}
}

int main(){
	//freopen("subway1_1.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); 
	d=read(); Q=read(); nxt=m;
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k; k=read();
		id[i]=nxt+1;
		for(int j=1;j<=k;j++){
			int a; ll t; nxt++;
			a=read(); t=read();
			sta[a].push_back(i);
			adj[a].push_back({nxt,t});
			adj[nxt].push_back({a,t});
		}
		//printf("\n");
		for(int j=2;j<=k;j++) {
			int u=nxt-k+j-1,v=nxt-k+j;
			adj[u].push_back({v,0});
			adj[v].push_back({u,0});
			//printf("%d %d ",u,v);
		}
		//printf("\n");
	}
	for(int i=1;i<=n;i++) dijks(i);
	for(int i=1;i<=Q;i++){
		int u,v; ll ans=1e18;
		u=read(); v=read();
		for(int p:sta[u]) ans=min(ans,dis[p][u]+dis[p][v]);
		ans=ans+w[u]+w[v];
		printf("%lld\n",ans);
	}
}
