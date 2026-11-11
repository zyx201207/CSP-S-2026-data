#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=5e5+5;
long long c,n,m,d,q,w[M],k[N],a[M][25],p[M];
long long f[N][N],t[M][25];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	clock_t st=clock();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			f[i][j]=1e18+50;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[x][++p[x]]=i;
			t[x][p[x]]=y;
			for(int z=p[x]-1;z>=1;z--){
				int u=a[x][z];
				f[i][u]=min(f[i][u],t[x][p[x]]+t[x][z]);
				f[u][i]=min(f[i][u],t[x][p[x]]+t[x][z]);
			}
		}
	}
	for(int k=1;k<=n;k++){//floyd
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=1e18+5;
		for(int i=1;i<=p[x];i++){
			int u=a[x][i];
			for(int j=1;j<=p[y];j++){
				int v=a[y][j];
				ans=min(ans,f[u][v]+t[x][i]+t[y][j]);
			}
		}cout<<ans+w[x]+w[y]<<endl;
	}
//	clock_t et=clock();
//	double tt=double(et-st)/CLOCKS_PER_SEC;
//	cout<<tt<<" s";
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
 
*/
