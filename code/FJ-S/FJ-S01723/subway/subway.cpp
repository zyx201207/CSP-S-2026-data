#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>a[500005];
int p[500005],n,m,c,d,q;
int dis[505][505];
void add(int i,int x,int t){
	for(int j=0;j<(int)a[x].size();j++){
		int y=a[x][j].first,z=a[x][j].second;
		dis[i][y]=min(dis[i][y],t+z),
		dis[y][i]=min(dis[y][i],t+z);
	}
	a[x].push_back({i,t});
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int i=1;i<=500;i++)dis[i][i]=0ll;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>p[i];
	for(int i=1,k,x,t;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>x>>t,add(i,x,t);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<i;j++)
				if(j!=k)dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=0;i<(int)a[x].size();i++)
			for(int j=0;j<(int)a[y].size();j++){
				int u=a[x][i].first,v=a[y][j].first,w=a[x][i].second,z=a[y][j].second;
				ans=min(ans,w+dis[u][v]+z);
			}
		cout<<ans+p[x]+p[y]<<"\n";
	}
}