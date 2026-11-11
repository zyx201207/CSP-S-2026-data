#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct subway{
	ll p,t;
};
ll c,n,m,d,q;
ll w[500005];
vector<subway>sub[500005];
vector<subway>po[500005];
vector<subway>mp[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll p,t;
			cin>>p>>t;
			mp[i].push_back({p,t});
			po[p].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<mp[i].size();j++){
			ll p=mp[i][j].p;
			for(int k=0;k<po[p].size();k++){
				ll x=po[p][k].p;
//				cout<<i<<" "<<j<<" "<<k<<endl;
				if (x==i)continue;
				sub[i].push_back({x,mp[i][j].t+po[p][k].t});
			}
		}
		mp[i].clear();
	}
	while (q--){
		ll s,e;
		cin>>s>>e;
		priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
		vector<ll>dis(n+1,0x3f3f3f3f);
		for(int i=0;i<po[s].size();i++){
			dis[po[s][i].p]=po[s][i].t;
			pq.push({po[s][i].t,po[s][i].p});
//			cout<<po[s][i].p<<" "<<po[s][i].t<<endl;
		}
//		cout<<endl;
		while (pq.size()){
			ll u=pq.top().second;
			ll w=pq.top().first;
			pq.pop();
			if (w>dis[u])continue;
//			cout<<u<<" ";
			for(int i=0;i<sub[u].size();i++){
				ll v=sub[u][i].p,t=sub[u][i].t;
//				cout<<v<<" "<<t<<endl;
				if (dis[v]>dis[u]+t){
					dis[v]=dis[u]+t;
					pq.push({dis[v],v});
				}
			}
		}
//		for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
//		cout<<endl;
		ll ans=LLONG_MAX;
		for(int i=0;i<po[e].size();i++){
			ans=min(ans,dis[po[e][i].p]+po[e][i].t);
		}

		cout<<ans+w[s]+w[e]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
