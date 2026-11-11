#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
int w[500005];
int dis[2005][2005];
void floyd(){
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=2000;i++){
		for(int j=1;j<=2000;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=2000;i++)dis[i][i]=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y,z;
			cin>>y>>z;
			dis[i+m][y]=z;
			dis[y][i+m]=z;
		}
	}
	floyd();
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<dis[a][b]+w[a]+w[b]<<"\n";
	}
	return 0;
}
