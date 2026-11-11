#include<bits/stdc++.h>
using namespace std;
int c,m,n,ad,q,b[510];
long long d[510][510];
void Floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>ad>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			d[i][j]=1e18;
		}
		d[i][i]=0; 
	}
	for(int i=1;i<=n;i++){
		int k,a[510],t[510];
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int l=1;l<j;l++){
				d[a[l]][a[j]]=t[j]+t[l];
			}
		}
	}
	Floyd();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<d[x][y]+b[x]+b[y]<<'\n';
	}
}
