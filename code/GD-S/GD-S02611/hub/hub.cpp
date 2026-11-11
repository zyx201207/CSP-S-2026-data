#include<bits/stdc++.h>
using namespace std;
int m,n,w[501000],c,d,q,t,a,k[501000],x,y;
int lj[5500][5500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(lj,60,sizeof(lj));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			lj[n+a][i]=t;
			lj[i][n+a]=t;
		}
	}
	for(int l=1;l<=n+m;l++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				if(lj[i][l]+lj[l][j]<lj[i][j]){
					lj[i][j]=lj[i][l]+lj[l][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<lj[n+x][n+y]+w[x]+w[y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
