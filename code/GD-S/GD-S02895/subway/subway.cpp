#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,m,n,d,q;
ll w[500005];
ll g[5005][5005];
ll dis[5005][5005];
ll i,j,k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++){
		cin>>w[i];
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			g[i][j]=10000000005;
			dis[i][j]=1000000005;
		}
	}
	for(i=1;i<=n;i++){
		ll n1;
		cin>>n1;
		for(j=1;j<=n1;j++){
			ll x,y;
			cin>>x>>y;
			g[x][i]=g[i][x]=y;
		}
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(i==j)continue;
				dis[i][j]=g[i][k]+g[j][k];
			}
		}
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(k==j)break;
				if(i==j||k==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}

