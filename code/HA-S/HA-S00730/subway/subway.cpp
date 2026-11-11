#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,w;
ll a[500005],dis[10001][10001],k[500005],enter[500005];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>w;
	for(int i=1;i<=m;i++){
		cin>>k[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=0x3FFFFFFF;
		}
	}
	for(int i=1;i<=n;i++){
		int k1;
		cin>>k1;
		for(int j=1;j<=k1;j++){
			int v,wei;
			cin>>v>>wei;
			if(i==v) enter[i]=wei;
			dis[i][v]=wei;
			dis[v][i]=wei;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]+dis[k][k]){
					dis[i][j]=dis[i][k]+dis[k][j]+dis[k][k];
				}
			}
		}
	}
	for(int i=1;i<=w;i++){
		ll x,y;
		cin>>x>>y;
		cout<<dis[x][y]+k[y]+k[x]+enter[x]<<"\n";
	}
	return 0;
}
