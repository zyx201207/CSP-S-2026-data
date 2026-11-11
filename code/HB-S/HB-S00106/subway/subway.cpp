#include <bits/stdc++.h>
using namespace std;
const int MN=1e5+2;
const int M=5e5+2;
int c,n,m,d,q,w[125255],a[505][M],t[505][M],k,x,y,ans=999999;
bool vis[505][M];
void dfs(int x,int y,int tim){
	if(tim>ans) return;
	if(x==y){
		ans=min(ans,tim);
		return; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(x==i){
				if(vis[i][j]) continue;
				vis[i][j]=true;
				dfs(a[i][j],y,tim+t[i][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		memset(vis,false,sizeof(vis));
		cin>>x>>y;
		dfs(x,y,0);
		cout<<w[x]+w[y]+ans<<'\n';
		ans=99999;
	}
	return 0;
}
