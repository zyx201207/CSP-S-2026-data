#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001]={};
int vis[500001][500001][4]={};
int num[500001]={};
int res=0;
int bfs(int x,int y,int z,int t){
	if(vis[x][y][0]==0&&vis[x][y][1]==0){
		return 0;
	}
	else if(vis[x][y][3]==1){
		return 0;
	}
	else if(x==z){
		return t;
	}
	vis[x][y][3]=1;
	for(int i=0;i<=1;i++){
		if(vis[x][y][i]==0){
			return 0;
		}
		for(int j=1;j<=m;j++){
			int wen=bfs(vis[x][j][i],j,z,t+vis[x][y][2]);
			res=max(res,wen);
			vis[x][y][3]=0;
		}
		return res;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int x,y;
	for(int i=1;i<=n;i++){
		int o;
		cin>>o;
		cin>>x;
		cin>>vis[x][i][2];
		vis[x][i][0]=0;
		for(int j=2;j<=o;j++){
			cin>>y;
			vis[x][i][1]=y;
			vis[y][i][0]=x;
			cin>>vis[y][i][2];
			x=y;
		}
		vis[y][i][1]=0;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int t=bfs(x,1,y,w[x])+w[y];
		cout<<t<<endl;
	}
	return 0;
} 
