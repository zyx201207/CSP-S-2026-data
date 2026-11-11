#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
struct edge{
	int to,val;
};
vector<edge> T[500010];
int va[510][510];
int w[500010];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) va[i][j]=1e18;
	}
	for(int i=1;i<=n;i++) va[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int K;
		cin>>K;
		for(int j=1;j<=K;j++){
			int u,t;
			cin>>u>>t;
			for(int k=0;k<T[u].size();k++){
				va[i][T[u][k].to]=min(va[i][T[u][k].to],t+T[u][k].val);
				va[T[u][k].to][i]=min(va[T[u][k].to][i],t+T[u][k].val);
			}
			T[u].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) va[i][j]=min(va[i][j],va[i][k]+va[k][j]);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=1e18;
		for(int i=0;i<T[u].size();i++){
			for(int j=0;j<T[v].size();j++){
				ans=min(ans,va[T[u][i].to][T[v][j].to]+T[u][i].val+T[v][j].val);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
