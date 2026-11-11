#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+10;

int c,n,m,d,q;
ll w[M],t[210][M],a[210][M];
int k[M];
vector<int> b[M];
vector<int> g[M];
ll ans=1e18;
bool vis[M];

void dfs(int u,int end,ll tt){
	if(u==end){
		ans=min(ans,tt);
		return;
	}
	for(int i=0;i<b[u].size();i++){//去几号线 
		tt+=t[i][u];
		for(int j=0;j<g[u].size();j++){//去几号站 
			int v=g[u][j];
			if(t[i][v]==0)continue;
			if(!vis[v]){
				vis[v]=1;
				dfs(v,end,tt+t[i][v]);
				vis[v]=0;
			}
		}
	}
}

int main(){
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
			b[a[i][j]].push_back(i);
			if(j>1){
				g[a[i][j]].push_back(a[i][j-1]);
				g[a[i][j-1]].push_back(a[i][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<g[i].size();j++){
//			cout<<g[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dfs(x,y,0);
		cout<<w[x]+ans+w[y]<<endl;
		ans=1e18;
	}
} 
