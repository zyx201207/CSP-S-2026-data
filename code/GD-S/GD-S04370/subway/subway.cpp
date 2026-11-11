#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q;
long long w[N];
long long f[1005][1005],a[1005][1005],t[1005][1005],k[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(m<=1000){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=1e18;
			}
			f[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int d1=1;d1<=k[i];d1++){
				for(int d2=1;d2<=k[i];d2++){
					f[a[i][d1]][a[i][d2]]=w[a[i][d1]]+t[i][d1]+t[i][d2]+w[a[i][d2]];
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(f[i][k]==1e18||f[k][j]==1e8) continue;
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]-2*w[k]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<f[x][y]<<endl;
		}
		return 0;
	}
	return 0;
} 
