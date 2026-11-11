#include<bits/stdc++.h>
#define pll pair<long long,int>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll cnt,w[500007];
ll k[507],st,ed;
vector<ll> a[500007],t[500007],v[500007],f[500007];
ll dis[500007],vis[500007];
priority_queue<pll,vector<pll>,greater<pll>> pq;
ll get(){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	while(!pq.empty()) pq.pop();
	dis[st]=0; pq.push({0,st});
	while(!pq.empty()){
		pll cu=pq.top();
		pq.pop();
		if(vis[cu.second])
			continue;
		vis[cu.second]=true;
		if(cu.second==ed) return dis[ed];
		for(ll l=0;l<v[cu.second].size();l++){
			ll i=v[cu.second][l],w1=f[cu.second][l];
			for(ll j=0;j<a[i].size();j++){
				ll to=a[i][j],w2=t[i][j];
				if(!vis[to]&&cu.first+w1+w2<dis[to]){
					dis[to]=cu.first+w1+w2;
					pq.push({dis[to],to});
				}
			}
		}
	}
	return dis[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			v[x].push_back(i);
			f[x].push_back(y);
		}
	}
	while(q--){
		cin>>st>>ed;
		cout<<w[st]+w[ed]+get()<<"\n";
	}
	return 0;
}
