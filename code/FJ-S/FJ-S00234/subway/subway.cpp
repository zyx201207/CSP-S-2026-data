#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl;
int w[500010];
int k[510];
int a[510][500010];
int b[510][500010];
int t[510][500010];	
vector<int>city[500010];
vector<int>edge[510];
ll dis[510][510];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j],city[a[i][j]].push_back(i),b[i][a[i][j]]=j;
	} 
	memset(dis,127,sizeof(dis));
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int len=city[i].size();
		for(int j=0;j<len;j++)for(int k=j+1;k<len;k++){
			edge[city[i][j]].push_back(city[i][k]);
			edge[city[i][k]].push_back(city[i][j]);
			dis[city[i][j]][city[i][k]]=min(dis[city[i][j]][city[i][k]],1ll*t[city[i][j]][b[city[i][j]][i]]+1ll*t[city[i][k]][b[city[i][k]][i]]);
			dis[city[i][k]][city[i][j]]=min(dis[city[i][k]][city[i][j]],1ll*t[city[i][j]][b[city[i][j]][i]]+1ll*t[city[i][k]][b[city[i][k]][i]]);
			//dbg(city[i][j])
			//dbg(city[i][k])
			//dbg(dis[city[i][j]][city[i][k]])
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
	/*for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		dbg(i)
		dbg(j)
		dbg(dis[i][j]) 
	}*/
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=5e18;
		for(auto i:city[x])for(auto j:city[y])ans=min(ans,dis[i][j]+t[i][b[i][x]]+t[j][b[j][y]]);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}

