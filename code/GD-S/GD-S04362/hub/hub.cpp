#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e6+5;
ll x[N],cost[N],cnt;
vector<int> e[N];
int n;
bool vis[N];

void dijk(int st){
	priority_queue<pair<ll,int> > q;
	fill(vis+1,vis+1+n,0);
	cost[st]=0;
	vis[st]=1;
	for(auto v:e[st])
		q.push({-1ll,v});
	while(!q.empty()){
		ll w=q.top().first*-1;
		int v=q.top().second;
		q.pop();
		if(vis[v]){
			continue;
		}
			
		
		vis[v]=1;
		cost[v]=w;
		cnt=max(cnt,w);
		for(auto nxt:e[v]){
			if(!vis[nxt])
				q.push({(cost[v]+1)*-1,nxt});
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		ll ans=1e18;
		int n,k;
		scanf("%d%d",&n,&k);
		
		for(int i=1;i<=n;++i)
			while(!e[i].empty()) e[i].pop_back();
		
		for(int i=1;i<n;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}

		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				dijk(i);
				ans=min(ans,cnt);
				dijk(j);
				ans=min(ans,cnt);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
