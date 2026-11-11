#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[1010][1010],b[1010][1010],t[1010][1010],vis[10101010],k[101010],k2[101010],ww[101010],x,y;
int dfs(int x){
	for(int j=1;j<=k[x];j++){
		if(a[x][j]==y)return t[y][x];
	}
	int mn=10010010;
	for(int i=1;i<=k[x];i++){
		if(a[x][i]&&!vis[a[x][i]]){
			for(int j=1;j<=k2[a[x][i]];j++){
				vis[a[x][i]]=1;
				mn=min(mn,t[a[x][i]][x]+t[a[x][i]][b[a[x][i]][j]]+dfs(b[a[x][i]][j]));
				vis[a[x][i]]=0;
			}
			
		}
	}
	return mn;
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ww[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			b[a[i][j]][++k2[a[i][j]]]=i;
			cin>>t[a[i][j]][i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		vis[x]=1;
		int mn=1000000;
		for(int j=1;j<=k2[x];j++){
			mn=min(mn,dfs(b[x][j])+t[x][b[x][j]]);
		}
		vis[x]=0;
		cout<<mn+ww[x]+ww[y]<<endl;
	}
	return 0;
} 
