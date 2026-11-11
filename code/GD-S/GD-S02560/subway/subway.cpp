#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pil=pair<int,ll>;
int c,n,m,d,q;
ll w[500005];
vector<pil> belong[500005];
int k[505];
vector<int> a[505];
vector<ll> t[505];
ll dist[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dist,0x3f,sizeof dist);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u;
			ll v;
			cin>>u>>v;
			a[i].push_back(u);
			t[i].push_back(v);
			belong[u].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<belong[i].size();j++){
			for(int k=0;k<belong[i].size();k++){
				if(j==k)continue;
				int u=belong[i][j].first,v=belong[i][k].first;
				ll w1=belong[i][j].second,w2=belong[i][k].second;
				dist[u][v]=min(dist[u][v],w1+w2);
				dist[v][u]=min(dist[v][u],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		ll ans=1e18;
		for(auto a:belong[s]){
			for(auto b:belong[t]){
				ans=min(ans,dist[a.first][b.first]+w[s]+w[t]+a.second+b.second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
