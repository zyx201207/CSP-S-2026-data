#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,q,w[500005],f[505][505];
vector<pair<int,int>>v[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		int k;
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)v[i].size();j++){
			for(int k=0;k<(int)v[i].size();k++){
				f[v[i][j].first][v[i][k].first]=min(f[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int j=0;j<(int)v[x].size();j++){
			for(int k=0;k<(int)v[y].size();k++){
				ans=min(ans,f[v[x][j].first][v[y][k].first]+v[x][j].second+v[y][k].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	// cerr<<clock()<<"\n";
	return 0;
}//rp++