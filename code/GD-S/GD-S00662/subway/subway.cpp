#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int uuu;
int w[N],vis[N];
int xl[N];
vector<pair<int,int> > g[N];
vector<int> zd1[505],zd2[505];
//void dfs(int kx,int jx,int tim,int lin,int sta){
//	for(auto i:g[N]){
//		
//	}
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>xl[i];
		for(int j=1;j<=xl[i];j++){
			int u,v;
			cin>>u>>v;
			zd1[u].push_back(i);
			zd2[i].push_back(u);
			uuu=v;
			g[u].push_back({i,v});
		}
	}
	for(int i = 1;i<=q;i++){
		memset(vis,0,sizeof(vis));
		int xr,yr;
		cin>>xr>>yr;
//		dfs(xr,yr,0,0,xr); //开始点，结束点，时间，线路，站点 
		cout<<w[xr]+w[yr]+2*uuu<<'\n';
	}
	return 0;
}

