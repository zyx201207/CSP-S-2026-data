#include <iostream>
#include <cstring>
#include <vector>
//#include <memset>
using namespace std;
#define int long long
// no long long, no ac
int c,n,m,d,q;
int w[500000];
vector<pair<int,int>> g[500000];
int tot;
void add(int u,int v,int w){
	g[u].push_back({v,w});
}
int f[500][500];
signed main(){
	freopen("subway.in","rb",stdin);
	freopen("subway.out","wb",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;++i)cin>>w[i];
	for(int i=0;i<n;++i){
		int k;cin>>k;
		while(k--){
			int a,t;cin>>a>>t,--a;
			add(a,i,t);
		}
	}

	memset(f,0x3f,sizeof(f));
	for(int i=0;i<m;++i)
	for(int a=0;a<g[i].size();++a)
	for(int b=a+1;b<g[i].size();++b){
		int u=g[i][a].first,v=g[i][b].first;
		f[u][v]=f[v][u]=min(f[u][v],g[i][a].second+g[i][b].second);
	}
	for(int i=0;i<n;++i)f[i][i]=0;
	for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=i+1;j<n;++j)
		f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);

	while(q--){
		int u,v;cin>>u>>v,--u,--v;
		int ans=0x7fffffffffffffff;
		for(int a=0;a<g[u].size();++a)
		for(int b=0;b<g[v].size();++b){
			pair<int,int> fs=g[u][a],fe=g[v][b];
			ans=min(ans,f[fs.first][fe.first]+fs.second+fe.second);
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
