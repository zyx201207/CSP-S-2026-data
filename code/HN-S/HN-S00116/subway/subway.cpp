#include <bits/stdc++.h>
#define int long long 
using namespace std;
vector<pair<int,int>>g[100100];
vector<int>a[510];
vector<int>l[510];
vector<pair<int,int>>zh[500100];
int dis[510][510];
int f[500100];
int k[1010];
int c,n,m,d,o;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>o;
	for(int i=1;i<=m;i++)cin>>f[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v,t;
			cin>>v>>t;
			zh[v].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int j=0;j<zh[i].size();j++){
			for(int k=0;k<zh[i].size();k++){
				if(j==k)continue;
				int u1=zh[i][j].first;
				int u2=zh[i][k].first;
				int t1=zh[i][j].second;
				int t2=zh[i][k].second;
				dis[u1][u2]=dis[u2][u1]=t1+t2;
			}
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++){
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
		
	while(o--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<zh[x].size();i++)
		for(int j=0;j<zh[y].size();j++){
				int u1=zh[x][i].first;
				int u2=zh[y][j].first;
				int t1=zh[x][i].second;
				int t2=zh[y][j].second;
				if(u1==u2)ans=min(ans,f[x]+f[y]+t1+t2);
				else ans=min(ans,f[x]+f[y]+t1+t2+dis[u1][u2]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//fc subway.out subway6.ans
