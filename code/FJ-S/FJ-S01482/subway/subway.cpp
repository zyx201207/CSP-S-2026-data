#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,d,q,m,n,k[505],w[500005],a[500005][505],t[500005][505],ans; 
vector<int> g[500005];
bool flag[500005];
int dfs(int xz,int zd,int bs){
	if(xz==zd)return min(ans,bs);
	flag[xz]=1;
	for(int i=0;i<g[xz].size();i++){
		if(flag[g[xz][i]])continue;
		dfs(i,zd,bs+a[i][g[xz][i]]);
	}
	flag[xz]=0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j==1)continue;
			g[a[i][j]].push_back(a[i][j-1]);
			g[a[i][j-1]].push_back(a[i][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=0;
		cout<<dfs(x,y,0)+w[x]+w[y];
	}
	return 0;
}
