#include<bits/stdc++.h>
using namespace std;
const int N=50010;
int c,n,m,d,p,dt[N],a[N][N],t[N][N],minn=1e9;
bool b[N][N];
void dfs(int x,int y,int tt){
	if(x==y){
		if(tt<minn)minn=tt+dt[y];
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i][x]){
			b[i][x]=1;
			for(int j=1;j<=m;j++){
				if(a[i][j] && !b[i][j]){
					b[i][j]=1;
					dfs(j,y,tt+t[i][x]+t[i][j]);
					b[i][j]=0;
				}
			}
			b[i][x]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>dt[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int z;
			cin>>z;
			a[i][z]=1;
			cin>>t[i][z];
		}
	}
	while(p--){
		int s,e;
		cin>>s>>e;
		dfs(s,e,dt[s]);
		cout<<minn<<endl;
		minn=1e9;
	}
	return 0;
} 
