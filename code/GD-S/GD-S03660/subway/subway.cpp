#include<bits/stdc++.h>
#define int long long
#define ls first
#define rs second
using namespace std;
const int MaxM=5e5+5,MaxN=5e2+5;
int C,n,m,d,Q;
int w[MaxM];
int dis[MaxN][MaxN];
vector<pair<int,int> > to[MaxM];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=1e18;
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			to[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<to[i].size();j++){
			for(int k=j+1;k<to[i].size();k++){
				int x=to[i][j].ls,y=to[i][k].ls,cost=to[i][j].rs+to[i][k].rs;
				dis[x][y]=dis[y][x]=min(dis[x][y],cost);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i!=k){
				for(int j=1;j<=n;j++){
					if(j!=i&&j!=k) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto u:to[x]){
			for(auto v:to[y]){
				ans=min(ans,w[x]+w[y]+u.rs+v.rs+dis[u.ls][v.ls]);
			}
		} 
		cout<<ans<<'\n';
	}
	return 0;
}
