#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],a[510][25],t[510][25],dij[1010][1010],dis[1010][1010];
void add(int x,int y,int q){
	dis[x][y]=q;
	dij[x][y]=q;
}
void makdij(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(k!=i&&k!=j)
					dij[i][j]=min(dij[i][j],dij[i][k]+dis[k][j]);
			}
		}
	}
}
void solv1(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
		for(int j=1;j<=m;j++){
			dij[i][j]=1000000000;
			dis[i][j]=1000000000;
		}
	}
	for(int i=1;i<=n;i++){
		int nn;
		cin>>nn;
		if(nn==2){
			int z1,z2,z3,z4;
			cin>>z1>>z2>>z3>>z4;
			add(z1,z3,z2+z4);
			add(z3,z1,z2+z4);
		}else{
			int z1,z2;
			cin>>z1>>z2;
		}
	}
	makdij();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dij[x][y];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c>=7&&c<=11){
		solv1();
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int nn;
		cin>>nn;
		for(int j=1;j<=nn;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	return 0;
}
/*9 5 5 3 1 1 2 3 4 5 2 1 1 4 3 2 1 1 5 7 2 5 7 2 2 2 2 2 3 4 2 5 7 3 4 1 3*/
