#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+11,N=520;
int n,m,cc,d;
ll w[M],q,dis[N][N];
vector<pair<int,ll> >vec[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll t,a;
			cin>>a>>t;
			vec[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int g=vec[i].size();
		for(int j=0;j<g;j++){
			for(int k=j+1;k<g;k++){
				int u=vec[i][j].first,v=vec[i][k].first;
				ll c=vec[i][j].second+vec[i][k].second;
				dis[u][v]=min(dis[u][v],c),dis[v][u]=min(dis[v][u],c);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[j][k]=min(dis[j][k],dis[i][j]+dis[i][k]);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f;
		for(auto i:vec[x]){
			for(auto j:vec[y]){
				int u=i.first,v=j.first;
				ll c=i.second+j.second;
				ans=min(ans,dis[u][v]+c);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
