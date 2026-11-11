#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c,m,d,q;int s,t;int o;
int w[20050];
int dt[1010][20020];
int g[20020][20020];
int ans[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
		g[i][j]=INT_MAX/2;
	}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int y;cin>>y;
		for(int j=1;j<=y;j++){
			int z,v;cin>>z>>v;
			dt[i][z]=v;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=j+1;k<=m;k++){
				if(dt[i][j]&&dt[i][k]){
					g[j][k]=dt[i][j]+dt[i][k];
					g[k][j]=g[j][k];
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=j+1;k<=m;k++){
				if(g[i][j]&&g[i][k]){
					g[j][k]=min(g[i][j]+g[i][k],g[j][k]);
					g[k][j]=g[j][k];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		int pp=w[s]+w[t];
		ans[i]=pp+g[s][t];	
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;	
	}
	
	return 0;
} 
