#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<int,int>
const int N=5e5+5,M=5e2+5;
int C,n,m,D,T,w[N];
ll dis[M][M];
vector<PII> g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>n>>m>>D>>T;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,len;j<=k;j++){
			cin>>x>>len;
			g[x].push_back({i,len});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=1e18;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=0;k<g[i].size();k++){
				if(j==k)continue;
				int x=g[i][j].first,y=g[i][k].first;
				dis[x][y]=min(dis[x][y],1ll*g[i][j].second+g[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=T;i++){
		int st,ed;
		cin>>st>>ed;
		ll ans=1e18;
		for(auto it1:g[st]){
			for(auto it2:g[ed]){
				ans=min(ans,dis[it1.first][it2.first]+it1.second+it2.second);
			}
		}
		cout<<ans+w[st]+w[ed]<<"\n";
	}
	return 0;
}
