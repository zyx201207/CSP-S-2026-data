#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=1005;
vector<ll> a[N];
ll dis[N];
void bfs(ll st){
	queue<PII> q;
	q.push({st,0});
	dis[st]=0;
	while(!q.empty()){
		ll u=q.front().first;
		ll d=q.front().second;
		q.pop();
		for(auto v:a[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		for(ll i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ll ans=1e18;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				memset(dis,0x3f,sizeof(dis));
				ll Max=-1e18;
				bfs(i);
				bfs(j);
				for(ll l=1;l<=n;l++){
					Max=max(Max,dis[l]);
				}
				ans=min(ans,Max);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}