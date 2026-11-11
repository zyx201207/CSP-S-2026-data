#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,w[500050],x,y,z;
long long f[2550][2550];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>y>>z;
			f[i][y+n]=z;
			f[y+n][i]=z;
		}
	}
	
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<f[x+n][y+n]+w[x]+w[y]<<"\n";
	}
	return 0;
}
