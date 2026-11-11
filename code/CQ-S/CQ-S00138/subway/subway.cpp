#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],g[505][505];
vector<pair<int,int>>p[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		g[i][i]=0;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			p[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<p[i].size();j++){
			for(int k=j+1;k<p[i].size();k++){
				auto x=p[i][j],y=p[i][k];
				g[x.first][y.first]=min(g[x.first][y.first],x.second+y.second);
				g[y.first][x.first]=min(g[y.first][x.first],y.second+x.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(auto i:p[x]){
			for(auto j:p[y]){
				ans=min(ans,g[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
