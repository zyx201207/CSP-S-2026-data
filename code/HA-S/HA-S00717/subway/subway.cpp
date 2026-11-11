#include<bits/stdc++.h>
using namespace std;
bool o[501][500001];
int k[501],n,minx;
int f[3]={0,1,-1};
int w[500001],a[501][500001],t[501][500001],b[100001][3];
void dfs(int x,int y,int m,int time){
	if(a[x][y]==m){
		if(time<minx) minx=time;
		return;
	}for(int i=1;i<=n;i++)
		for(int j=1;j<=k[i];j++)
			if(a[i][j]==a[x][y]&&i!=x&&o[i][j]==0){
				o[i][j]=1;
				dfs(i,j,m,time+t[x][y]+t[i][j]);
				o[i][j]=0;
			}
	for(int i=1;i<=2;i++)
		if(a[x][y+f[i]]<=k[i]&&a[x][y+f[i]]>0&&o[x][y+f[i]]==0){
			o[x][y+f[i]]=1;
			dfs(x,y+f[i],m,time+t[x][y+f[i]]);
			o[x][y+f[i]]=0;
		}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}for(int i=1;i<=q;i++){
		cin>>b[i][1]>>b[i][2];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k[i];j++)
				if(a[i][j]==b[i][1]){
					minx=10086;
					dfs(i,j,b[i][2],w[b[i][1]]+w[b[i][2]]+t[i][j]);
					cout<<minx<<endl;
					break;
				}
	}return 0;
}
