#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
//#define int ll
#define inf 1e18
const int N=5e2+5;
const int M=5e5+5;
const int D=25;
int c,n,m,dmax,q;
int w[M];
int k[N];
int up[M][D],tot[M],d[N][M];
ll f[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dmax>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int nwa,nwt;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>nwa>>nwt;
			d[i][nwa]=nwt;
			up[nwa][++tot[nwa]]=i;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=tot[i];j++){
//			cerr<<i<<"->"<<j<<':'<<d[i][up[i][j]]<<' ';
//		}
//		cerr<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				f[i][j]=inf;
			}
		}
	}
	int fst,snd;
	ll sum;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=tot[i];j++){
			for(int k=j+1;k<=tot[i];k++){
				fst=up[i][j],snd=up[i][k];
				sum=d[fst][i]+d[snd][i];
//				cerr<<fst<<'~'<<snd<<'='<<sum<<endl;
				f[snd][fst]=f[fst][snd]=min(f[fst][snd],sum);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cerr<<f[i][j]<<' ';
//		}
//		cerr<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			if(f[i][k]==inf)continue;
			for(int j=1;j<=n;j++){
				if(i==j||k==j)continue;
				if(f[k][j]==inf)continue;
				f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	int fst,snd;
	ll down,dis,ong;
	ll ans;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=inf;
		for(int j=1;j<=tot[x];j++){
			for(int k=1;k<=tot[y];k++){
				fst=up[x][j];
				snd=up[y][k];
				down=w[x]+w[y];
				dis=f[fst][snd];
				ong=d[fst][x]+d[snd][y];
				if(dis==inf)continue;
				ans=min(ans,down+dis+ong);
			}
		}
		cout<<ans<<endl;
	}
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
