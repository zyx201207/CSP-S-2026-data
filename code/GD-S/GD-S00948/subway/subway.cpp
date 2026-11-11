#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],x,y,z,f[N][N];
vector<pair<int,int> > g[M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>y>>z;
			g[y].push_back({i,z});
		}
	}
	for(int i=1;i<=m;i++) for(int j=0;j<g[i].size();j++) for(int k=j+1;k<g[i].size();k++){
		auto w1=g[i][j],w2=g[i][k];
		int val=w1.second+w2.second;
		f[w1.first][w2.first]=min(f[w1.first][w2.first],val);
		f[w2.first][w1.first]=min(f[w2.first][w1.first],val);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++){
		if(i==k) continue;
		for(int j=1;j<=n;j++){
			if(j==k||i==j) continue;
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int ans=1e18;
		cin>>x>>y;
		for(int i=0;i<g[x].size();i++) for(int j=0;j<g[y].size();j++) ans=min(ans,w[x]+w[y]+f[g[x][i].first][g[y][j].first]+g[x][i].second+g[y][j].second);
		cout<<ans<<endl;
	}
	return 0;
} 
