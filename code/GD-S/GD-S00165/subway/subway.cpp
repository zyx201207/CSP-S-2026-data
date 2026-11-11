#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll CCC,n,m,d,q,w[1010],vis[20][1010];
struct node{
	ll dis;
	ll z,l;//z站l路 
};
ll cmp(node x,node y){
	return x.dis<y.dis;
}
vector<pair<ll,pair<ll,ll>>>t[1010][20];
int main(){
	cin>>CCC>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(ll i=1;i<=n;i++){
		ll x;cin>>x;
		ll a1,b1;cin>>a1>>b1;
		t[a1][i].push_back({b1,{a1,0}});
		for(int j=2;j<=x;j++){
			
			ll a,b;cin>>a>>b;
			t[a][i].push_back({b,{a,0}});
			t[a][0].push_back({b,{a,i}});
			t[a][i].push_back({0,{a1,i}});
			t[a1][i].push_back({0,{a,i}}); 
		}
	}
	while(q--){
		ll dis[30][1010];//dis要反过来写!!! 
		memset(dis,500010,sizeof(dis));
		ll s,e;cin>>s>>e;
		priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>q;
		q.push({0,{s,0}});
		dis[0][s]=0;
		while(!q.empty()){
			ll uz=q.top().second.first,ul=q.top().second.second,dist=q.top().first;
			q.pop();
			if(vis[ul][uz]==1){
				continue;
			}
			vis[ul][uz]=1;
			for(auto v:t[uz][ul]){
				if(dis[v.second.second][v.second.first]>dis[ul][uz]+v.first){
					dis[v.second.second][v.second.first]=dis[ul][uz]+v.first;
					q.push({dis[ul][uz]+v.first,{v.second.first,v.second.second}});
				}
			}
		}
		cout<<w[s]+w[e]+dis[0][e]<<'\n';
	}
	return 0;
}/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
 */
