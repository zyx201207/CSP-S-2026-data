#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c<=11){
//		cout<<1;
		vector<ll>v(m+1);
		vector<vector<array<ll,2>>>mp(n+m+1);
		vector<vector<ll>>dist(n+m+1,vector<ll>(n+m+1,INF));
		for(ll i = 1; i <= m; i ++)cin>>v[i];
		for(ll i = 1; i <= n; i ++){
			ll x;
			cin>>x;
			for(ll j = 1; j <= x; j ++){
				ll y,z;
				cin>>y>>z;
				mp[n+y].push_back({z,i});
				mp[i].push_back({z,n+y});
			}
		}
	//	ll num=0;
		for(ll s = n+1; s <= n+m; s ++){
			priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>>pq;
			pq.push({0,s});
			dist[s][s]=0;
			while(pq.size()){
				auto[dx,x]=pq.top();
				pq.pop();
				if(dx>dist[s][x])continue;
				for(auto [dy,y]:mp[x]){
					ll d = dy+dx;
					if(d<dist[s][y]){
						dist[s][y]=d;
						pq.push({d,y});
					}
				}
			}
	//		for(ll i = 1; i <= n+m; i ++)cout<<dist[s][i]<<' ';
	//		cout<<endl;
		}
	//	for(ll k = 1; k <= n+m; k ++){
	//		for(ll i = 1; i <= n+m; i ++){
	//			for(ll j = 1; j <= n+m; j ++){
	//				dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[j][k]);
	//				num++;
	//			}
	//		}
	//	}
	//	cout<<num;
		while(q--){
			ll x,y;
			cin>>x>>y;
			cout<<dist[x+n][y+n]+v[x]+v[y]<<endl;
		}
	}
	else{
//		cout<<2;
		vector<ll>v(m+1);
		for(ll i = 1; i <= m; i ++)cin>>v[i];
		vector<vector<array<ll,2>>>mp(m+1);
		vector<vector<ll>>dist(n+1,vector<ll>(n+1,INF));
		for(ll i = 1; i <= n; i ++){
			dist[i][i]=0;
			ll k;
			cin>>k;
			for(ll j = 1; j <= k; j ++){
				ll x,y;
				cin>>x>>y;
				mp[x].push_back({y,i});
			}
		}
		for(ll k = 1; k <= m; k ++){
			for(auto i:mp[k]){
				for(auto j:mp[k]){
					dist[i[1]][j[1]]=dist[j[1]][i[1]]=
						min(dist[j[1]][i[1]],i[0]+j[0]);
				}
			}
		}
		for(ll k = 1; k <= n; k ++){
			for(ll i = 1; i <= n; i ++){
				for(ll j = 1; j <= n; j ++){
					dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[j][k]);
				}
			}
		}
		while(q--){
			ll x,y;
			cin>>x>>y;
			ll ans=INF;
			for(auto i:mp[x]){
				for(auto j:mp[y]){
					ll an=dist[i[1]][j[1]];
					an += v[x]+v[y];
					an += i[0]+j[0];
					ans = min(ans,an);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
