#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e6+5;
ll x[N],cost[N],cnt[N];
vector<int> e[N];
int n;
bool vis[N];

void dijk(int st){
	priority_queue<pair<ll,int> > q;
	fill(vis+1,vis+1+n,0);
	fill(cnt+1,cnt+1+n,0);
	cost[st]=0;
	vis[st]=1;
	for(auto v:e[st])
		q.push({-1ll,v});
	while(!q.empty()){
		ll w=q.top().first*-1;
		int v=q.top().second;
		q.pop();
		if(vis[v]){
			if(w==cost[v]){
					++cnt[v];
//					printf("!!! %d ",v);
			}
			else continue;
		}
			
		
		vis[v]=1;
		cost[v]=w;
		for(auto nxt:e[v]){
			if(!vis[nxt])
				q.push({(cost[v]+1)*-1,nxt});
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		ll d,ans=0;
		scanf("%d%lld",&n,&d);
		
		for(int i=1;i<=n;++i)
			while(!e[i].empty()) e[i].pop_back();
		
		for(int i=1;i<=n;++i)
			scanf("%lld",x+i);
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j)
				if(x[j]-x[i]<=d) e[i].push_back(j);
		}
		for(int i=1;i<n;++i){
			dijk(i);
			for(int j=i+1;j<=n;++j){
				
//				printf("%d: ",i);
//				for(auto v:e[i])
//					printf("%d ",v);
//				printf("\n");
				
				
				if(cnt[j]==1ll){
					++ans;
					
//					printf("%d %d\n",i,j);
					
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
