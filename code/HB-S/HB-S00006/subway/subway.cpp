#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+3,N=505,INF=1e18;
int c,n,m,d,q;
int w[M],g[N][N];
vector<vector<pair<int,int>>>s(M);
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			for(pair<int,int>p:s[a]){
				int to=p.first,dis=p.second;
				g[to][i]=min(g[to][i],t+dis);
				if(g[to][i]==0LL)g[to][i]=t+dis;
				g[i][to]=min(g[i][to],t+dis);
				if(g[i][to]==0LL)g[i][to]=t+dis;
			}
			s[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int k=1;k<=n;k++){
				if(i==k||j==k)continue;
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				if(g[i][j]==0LL)g[i][j]=g[i][k]+g[k][j];
			}
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(pair<int,int>p1:s[x]){
			for(pair<int,int>p2:s[y]){
				ans=min(ans,g[p1.first][p2.first]+p1.second+p2.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
