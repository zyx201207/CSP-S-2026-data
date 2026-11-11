#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,n,m,d,q;
int w[500505];
vector<pair<int,int> > ve[500505];
int dis[500][500505];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			ve[500000+i].push_back({a,t});
			ve[a].push_back({500000+i,t});
		}
	}
	for(int x=1;x<=n;x++){
		for(int i=1;i<=500500;i++)dis[x][i]=INT_MAX;
		pq.push({0,500000+x});dis[x][500000+x]=0;
		while(!pq.empty()){
			int u=pq.top().second,dist=pq.top().first;
			pq.pop();
			if(dist!=dis[x][u])continue;
			int l=ve[u].size();
			for(int i=0;i<l;i++){
				int v=ve[u][i].first;
				if(dis[x][u]+ve[u][i].second<dis[x][v]){
					dis[x][v]=dis[x][u]+ve[u][i].second;
					pq.push({dis[x][v],v});
				}
			}
		}
	}
	while(q--){
		int x=1,y;
		cin>>x>>y;
		int ans=INT_MAX;
		for(int i=1;i<=n;i++){
			ans=min(ans,dis[i][x]+dis[i][y]);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
