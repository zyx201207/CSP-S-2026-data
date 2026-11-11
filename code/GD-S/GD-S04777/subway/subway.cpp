#include<bits/stdc++.h>
#define int long long
using namespace std;
bool st;
int c,n,m,d,q;
int w[500005];
struct node{
	int a,t;
};
vector<node>g[501],g2[500001];
int dis[501][501];
bool en;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)dis[i][j]=1e15;
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a,t;
			cin>>a>>t;
			g[i].push_back({a,t});
			g2[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;++i){
		for(node v:g[i]){
			for(node v2:g2[v.a]){
				dis[i][v2.a]=min(dis[i][v2.a],v2.t+v.t);
			}
		
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			if(dis[i][k]==1e15)continue;
			for(int j=1;j<=n;++j){
				if(i==j||i==k||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i)dis[i][i]=0;
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(node v:g2[x]){
			for(node v2:g2[y]){
				ans=min(ans,dis[v.a][v2.a]+v.t+v2.t+w[x]+w[y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
