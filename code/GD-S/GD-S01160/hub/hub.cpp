#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=3e18;
ll c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		vector<ll>x(n+1);
		for(int i=1;i<=n;i++)cin>>x[i];
		if(abs(x[1]-x[n])<=d){
			printf("1");
			continue;
		}
		vector<int>g[2+n];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					g[i].push_back(j);
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			vector<ll>dis(n+1);
			vector<ll>cnt(n+1);
			for(int j=1;j<=n;j++)dis[j]=inf;
			queue<pair<ll,ll>>q;
			map<ll,ll>mp[n+2];
			q.push({i,0});
			dis[i]=0;
			cnt[i]=1;
			while(q.size()){
				ll u=q.front().first,d=q.front().second;
				q.pop();
				if(d!=dis[u])continue;
				for(int v:g[u]){
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						q.push({v,dis[v]});
						cnt[v]+=cnt[u];
					}else if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
				}
			}
			for(int j=1;j<=n;j++){
				if(cnt[j]==2)ans++;		
			}
		}
		cout<<ans<<'\n';
	}
}
