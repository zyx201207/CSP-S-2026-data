#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500010],cnt;
int tot[500010];
int dis[510][510];
struct node{
	int ti,id;
}a[500010][21];
int nmin(int x,int y){
	if(x<=y)return x;
	return y;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y,t;
			cin>>y>>t;
			a[y][++tot[y]].ti=t;
			a[y][tot[y]].id=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=tot[i];j++){
			for(int k=j+1;k<=tot[i];k++){
				int x=a[i][j].id,y=a[i][k].id,z=a[i][j].ti+a[i][k].ti;
				dis[x][y]=nmin(dis[x][y],z);
				dis[y][x]=nmin(dis[y][x],z);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=nmin(dis[i][j],dis[i][k]+dis[j][k]);
				dis[j][i]=nmin(dis[i][j],dis[i][k]+dis[j][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=1e18; 
		for(int j=1;j<=tot[x];j++){
			for(int k=1;k<=tot[y];k++){
				int u=a[x][j].id,v=a[y][k].id;
				ans=nmin(ans,w[x]+w[y]+a[x][j].ti+a[y][k].ti+dis[u][v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
