#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1001]={0},a[1001]={0},t[1001]={0};
int g[1001][1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int l=1;l<=j-1;l++){
				g[a[j]][a[l]]=min(g[a[j]][a[l]],t[l]+t[j]);
				g[a[l]][a[j]]=min(g[a[l]][a[j]],t[j]+t[l]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<g[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
