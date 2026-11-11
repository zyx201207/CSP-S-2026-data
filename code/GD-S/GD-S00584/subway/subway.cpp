#include <bits/stdc++.h>
using namespace std;
unsigned int e[5050][5050],q[10010],c,n,m,d,q,w[50050],k[510],a[510][5050],t[510][5050],x[10010],y[10010];
long long dfs(long long x,long long y){
	d[i]=w[x]+w[y];
		for(int j=1;j<=n;j++){
			for(int k=1;k<=y[i];k++){
			if(!e[x][k]) e[x][k]=dfs(x[i],k);
			if(!e[y][k]) e[y][k]=dfs(y[i],k);
			d[i]=min(d[i],e[x[i]][k]+e[y[i]][k]);
		}return d[i];
	}
}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>y[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][k]>>t[i][k];
	}for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		d[i]=w[x[i]]+w[y[i]];
		for(int j=1;j<=n;j++){
			for(int k=1;k<=y[i];k++){
			if(!e[x[i]][k]) e[x[i]][k]=dfs(x[i],k);
			if(!e[y[i]][k]) e[y[i]][k]=dfs(y[i],k);
			d[i]=m(d[i],e[x[i]][k]+e[y[i]][k]);
		}cou
		}
		t<<d[i]<<'\n';
	}return 0; 
}
