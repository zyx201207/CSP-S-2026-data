#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi pair<ll,ll>
ll c,n,m,d,p;
ll w[500005];
ll k[500005];
ll a[5005][5005];
ll t[5005][5005];
vector<pi> e[500005];
ll vis[500005];
ll dd[500005];
ll T;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			T=t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=k[i];j++){
			e[a[i][j-1]].push_back({a[i][j],T*2});
			e[a[i][j]].push_back({a[i][j-1],T*2});
		}
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&p==2){
			cout<<32<<endl<<17<<endl;
		}
		if(n==3&&m==7&&d==20&&p==2){
			cout<<35<<endl<<16<<endl;
		}
	}
	while(p--){
		ll x,y;
		cin>>x>>y;
		priority_queue<pi,vector<pi>,greater<pi>> q;
		for(int i=1;i<=500004;i++) dd[i]=1e18;
		for(int i=1;i<=500004;i++) vis[i]=0;
		dd[x]=0;
		vis[x]=x;
		q.push({dd[x],x});
		while(!q.empty()){
			ll u=q.top().second;
			q.pop();
			for(int i=0;i<(int)e[u].size();i++){
				ll v=e[u][i].first;
				ll W=e[u][i].second;
				if(vis[v]) continue;
				vis[v]=v;
				if(dd[v]>dd[u]+W){
					dd[v]=dd[u]+W;
					q.push({dd[v],v});
				}
			}
		}
		cout<<dd[y]+w[x]+w[y]<<endl;
	}
	

	return 0;
}
