#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,d;
int w[1010],f[1010][1010],a[550][2010],t[550][2010],k[10010],ma[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[m];
	}
	memset(ma,0x3f3f,sizeof(ma));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int y=j+1;y<=k[i];y++){
				ma[a[i][j]][a[i][y]]=min(w[i]+t[i][a[i][j]],ma[a[i][j]][a[i][y]]);
				ma[a[i][y]][a[i][j]]=min(w[i]+t[i][a[i][y]],ma[a[i][y]][a[i][j]]);
			}
		}
	}
	
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1;i<=m;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int y=1;y<=m;y++){
				f[i][j]=min(f[i][j],f[i][y]+f[y][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<min(f[x][y],ma[x][y])<<'\n';
	}
	
	
	return 0;
}
