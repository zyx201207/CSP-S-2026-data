#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p; 
int w[505],a[150000][500005][3],vis[505];
int dfs(int x,int y,int o,int sum){
	if(x==y)return sum;
	int mn=505;
	vis[x]=1;
	if(o==0){
		for(int i=1;i<=p;i++){
			if(a[i][x][1]==1){
				for(int j=1;j<=n;j++){
					if(vis[i]==0)mn=min(mn,dfs(i,y,i,sum));
				}
			}
		}
	}else{
		for(int i=1;i<=p;i++){
			if(a[i][x][1]==1){
				for(int j=1;j<=n;j++){
					if(vis[i]==0&&i==o){
						mn=min(mn,dfs(i,y,i,sum));
					}else if(vis[i]==0){
						mn=min(mn,dfs(i,y,i,sum+a[i][j][2]+a[o][x][2]));
					}
				}
			}
		}
	}
	vis[x]=0;
	return mn+sum;
}
int main(){
	//*
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//*/
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y;
			cin>>y>>a[i][j][2];
			a[i][y][1]=1;
		}
	}
	while(p--){
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;
		int sum=0;
		sum=sum+w[x]+w[y];
		vis[x]=1;
		cout<<sum+dfs(x,y,0,0)<<endl;
		vis[x]=0;
	}
	//*
	fclose(stdin);
	fclose(stdout);
	//*/
	return 0;
} 
