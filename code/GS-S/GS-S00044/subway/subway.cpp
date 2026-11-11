#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
typedef pair<int,ll> pii;
int c,n,m,d,q;
vector<pii> G[N];
//vector<pii> G2[N];
ll a[N];
ll dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e12+100;
			if(i==j){
				dis[i][j]=0;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v;
			ll w;
			cin>>v>>w;
			G[v].push_back({m+i,w});
			G[m+i].push_back({v,w});
		}
	}
	
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(G[i].size()<2)continue;
		for(int j=0;j<G[i].size();j++){
			for(int k=0;k<G[i].size();k++){
				if(j==k)continue;
				ll w=G[i][j].second+G[i][k].second;
				dis[G[i][j].first-m][G[i][k].first-m]=min(dis[G[i][j].first-m][G[i][k].first-m],w); 
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		ll ans=1e12+100;
		for(int i=0;i<G[st].size();i++){
			for(int j=0;j<G[ed].size();j++){
				int u=G[st][i].first;
				int v=G[ed][j].first;
				ans=min(ans,min(dis[u-m][v-m],dis[v-m][u-m])+a[st]+a[ed]+G[st][i].second+G[ed][j].second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
