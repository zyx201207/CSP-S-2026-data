#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1005],tie[405][205],ki,xl,qz,f[405][405][405],x,y;
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ki;
		for(int j=0;j<ki;j++){
			cin>>xl>>qz;
			tie[xl][i]=qz;
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(!tie[i][k]||!tie[j][k]){
					continue;
				}
				if(f[0][i][j]==0){
					f[0][i][j]=tie[i][k]+tie[j][k];
					f[0][j][i]=tie[i][k]+tie[j][k];
				}else {
					f[0][i][j]=min(f[0][i][j],tie[i][k]+tie[j][k]);
					f[0][j][i]=min(f[0][j][i],tie[i][k]+tie[j][k]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		f[0][i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				f[i][j][k]=min(f[i-1][j][k],f[i-1][j][i]+f[i-1][i][k]);
			}
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		cout<<f[m][x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
