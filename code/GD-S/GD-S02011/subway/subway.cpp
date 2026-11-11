#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,q,w[N],f[550][550],x,y,dis[550][550];
vector<pair<int,int>> ve[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			ve[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)f[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<ve[i].size();j++){
			for(int k=0;k<ve[i].size();k++){
				auto x=ve[i][j],y=ve[i][k];
				if(x.second+y.second<f[x.first][y.first]){
					f[x.first][y.first]=f[y.first][x.first]=x.second+y.second;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(f[i][k]+f[k][j]<f[i][j])f[i][j]=f[i][k]+f[k][j];
			}
		}
	}
	while(q--){
		int ans=1e18;
		cin>>x>>y;
		for(int i=0;i<ve[x].size();i++){
			for(int j=0;j<ve[y].size();j++){
				ans=min(ans,ve[x][i].second+ve[y][j].second+f[ve[x][i].first][ve[y][j].first]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
