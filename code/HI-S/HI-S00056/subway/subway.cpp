#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],a[505][505],t[505][505],k[505],f[505];
void dfs(int l,int r,int ti){
	
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		dfs(x,y,0);
	}
	return 0;
}
