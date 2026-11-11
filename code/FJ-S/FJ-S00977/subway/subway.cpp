#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
int c,n,m,d,q,yyy[500005],mnmn[505][505];
vector<pair<int,int> > ve[500005];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			mnmn[i][j]=(i==j?0:inf);
	for(int i=1;i<=n;i++) cin>>yyy[i];
	for(int i=1;i<=m;i++){
		int box; cin>>box;
		for(int j=1;j<=box;j++){
			int x,y; cin>>x>>y;
			ve[x].push_back({i,y});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=0;i<ve[k].size();i++){
			for(int j=0;j<ve[k].size();j++){
				int x=ve[k][i].first,y=ve[k][j].first;
				mnmn[x][y]=min(mnmn[x][y],ve[k][i].second+ve[k][j].second);
			}
		}
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				mnmn[i][j]=min(mnmn[i][j],mnmn[i][k]+mnmn[k][j]);
	while(q--){
		int u,v,ans=inf; cin>>u>>v;
		for(int i=0;i<ve[u].size();i++){
			for(int j=0;j<ve[v].size();j++){
				int x=ve[u][i].first,y=ve[v][j].first;
				ans=min(ans,mnmn[x][y]+ve[u][i].second+ve[v][j].second);
			}
		}
		cout<<ans+yyy[u]+yyy[v]<<"\n";
	}
	return 0;
}
