#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1005],a[105][305],k[105],vis[105];
int x,y,ans=1e6;
void dfs(int g,int x,int ti){
	ti+=a[g][x];
	if(x==y){
		ti+=w[y];
		ans=min(ans,ti);
		return ;
	}
	if(ti>=ans){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i][x]!=0){
			for(int j=1;j<=k[i];j++){
				if(vis[j]!=0){
					vis[j]=1;
					dfs(i,j,ti+a[i][j]);
					vis[j]=0;
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int k,tk;
			cin>>k>>tk;
			a[i][k]=tk;
		}
	}
	for(int i=1;i<=q;i++){
		ans=1e6;
		cin>>x>>y;
		int g;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x)g=i;
			}
		}
		for(int i=1;i<=n;i++)vis[i]=0;
		vis[x]=1;
		dfs(g,x,w[x]);
		cout<<ans-a[g][x];
	}
	return 0;
}
