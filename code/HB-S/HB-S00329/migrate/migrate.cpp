#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll n,d,ans=0;
		cin>>n>>d;
		vector<ll> x(n+1);
		for(ll i=1;i<=n;++i) cin>>x[i];
		
		//BFS
		for(ll s=1;s<=n;++s){
			vector<ll> dist(n+1,1LL<<60);
			vector<ll> cnt(n+1);
			queue<pair<ll,ll>> que;
			
			que.push({0,s});
			dist[s]=0;
			cnt[s]=1;
			
			while(!que.empty()){
				ll u=que.front().second,D=que.front().first;
				que.pop();
				if(D!=dist[u]) continue;
				
				for(ll v=1;v<=n;++v){
					if(llabs(x[v]-x[u])<=d){
						if(dist[u]+1<dist[v]){
							dist[v]=dist[u]+1;
							que.push({dist[v],v});
							cnt[v]=cnt[u];
						}
						else if(dist[u]+1==dist[v]){
							cnt[v]+=cnt[u];
						}
					}
				}
				
			}
			
			for(ll i=s;i<=n;++i){
				if(cnt[i]==2) ++ans;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
