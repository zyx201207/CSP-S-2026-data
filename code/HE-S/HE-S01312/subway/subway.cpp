#include<bits/stdc++.h>
using namespace std;
int x,n,m,z,q,e[20001],a[501][20001],c[501][20001],d[20001][20001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>x>>n>>m>>z>>q;
	for(int i=1;i<=m;i++){
		cin>>e[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int p;
			cin>>p;
			cin>>a[i][p];
			c[i][p]=1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			d[i][j]=99999999;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			int o=-1;
			for(int k=1;k<=n;k++){
				if(c[k][i]==1&&c[k][j]==1){
					o=k;
					break;
				}
			}
			if(o!=-1&&i!=j){
				d[i][j]=a[o][i]+a[o][j];
				d[j][i]=a[o][i]+a[o][j];
			}else {
				for(int k=1;k<=n;k++){
					if(k!=i&&k!=j){
						d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
						d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int v,f;
		cin>>v>>f;
		cout<<d[v][f]+e[v]+e[f]<<endl;
	}
	return 0;
} 
