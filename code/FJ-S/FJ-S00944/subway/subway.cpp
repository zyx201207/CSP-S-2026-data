#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],dis[505][505],a[500005][25],b[500005][25],L[500005],INF=1e18;
int main(){
	freopen("subway7.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			a[x][++L[x]]=i;
			b[x][L[x]]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)dis[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=L[i];j++){
			for(int k=1;k<=L[i];k++){
				dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],b[i][j]+b[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);	
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=INF;
		for(int i=1;i<=L[x];i++){
			for(int j=1;j<=L[y];j++){
				ans=min(ans,b[x][i]+b[y][j]+dis[a[x][i]][a[y][j]]);
			}
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}

