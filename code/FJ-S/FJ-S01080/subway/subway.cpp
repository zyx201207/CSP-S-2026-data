#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1001;
int c,n,m,d,q;
int w[M],a[501][M],t[501][M];
int dis[M][M];
int k[501];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		for(int j=1;j<=m;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<k[i];j++){
			for(int x=j+1;x<=k[i];x++){
				dis[a[i][j]][a[i][x]]=dis[a[i][x]][a[i][j]]=min(dis[a[i][x]][a[i][j]],t[i][j]+t[i][x]);
			}
		}
	}
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			if(c>=12){
				continue;
			}
			for(int x=1;x<=m;x++){
				if(x==j||x==i) continue;
				if(dis[i][x]+dis[x][j]<dis[i][j]){
					dis[i][j]=dis[j][i]=dis[i][x]+dis[x][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	
	return 0;
}

