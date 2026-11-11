#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[505][505],t[505],T[505][505],k,
x,y,ans,con[505][505];
int connect(int a,int b){
	for(int i=1;i<=n;i++){
		if(con[i][a]&&con[i][b]){
			return con[i][a]+con[i][b];
		}
	}
	return 0;
} 
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>T[i][j];
			con[i][a[i][j]]=T[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=t[x]+t[y];
		ans+=connect(x,y);
	}
}
