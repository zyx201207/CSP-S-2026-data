#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[250005],dis[20005][20005],a[500005],t[500005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		for(int j=1;j<=m;j++){
			dis[i][j]=0x3fffffff;
			if(i==j){
				dis[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(l==j){
					continue;
				}
				dis[a[j]][a[l]] =min(dis[a[j]][a[l]],t[j]+t[l]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}
	return 0;
}
