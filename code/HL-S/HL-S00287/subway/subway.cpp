#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
long long f[5005][5005],w[500005],k[505],a[505][100005],C[505][100005],x,y;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i = 1;i<=m;i++) {
		cin>>w[i];
	}
	memset(f,0x3f3f3f3f3f3f3f3f,sizeof(f));
	for(int i = 1;i<=n;i++) {
		cin>>k[i];
		for(int j = 1;j<=k[i];j++) {
			cin>>a[i][j]>>C[i][j];
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=k[i];j++) {
			if(j!=1) {
				f[a[i][j]][a[i][j-1]] = min(f[a[i][j]][a[i][j-1]],C[i][j-1]+C[i][j]);
				f[a[i][j-1]][a[i][j]] = min(fa[i][j-1]][a[i][j]],C[i][j]+C[i][j]);
			}
		}
	}
	for(int k = 1;k<=m;k++) {
		for(int i = 1;i<=m;i++) {
			for(int j = 1;j<=m;j++) {
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i = 1;i<=p;i++) {
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
