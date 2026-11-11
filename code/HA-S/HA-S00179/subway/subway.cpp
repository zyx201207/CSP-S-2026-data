#include<bits/stdc++.h>
#define ll long long
#define N 501
#define M 500001
#define INF 4e18
using namespace std;
ll c,n,m,d,q,w[M],k[N],x,y,dis[N][N],ans;
vector<ll> e[M];
map<pair<ll,ll>,ll> mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=INF;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			e[x].push_back(i);
			mp[{x,i}]=y;
		}
	}
	for(int i=1;i<=m;i++)
	for(int j=0;j<e[i].size();j++)
	for(int k=j+1;k<e[i].size();k++) dis[e[i][j]][e[i][k]]=dis[e[i][k]][e[i][j]]=min(dis[e[i][j]][e[i][k]],mp[{i,e[i][j]}]+mp[{i,e[i][k]}]);
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		cin>>x>>y;
		ans=INF;
		for(int i=0;i<e[x].size();i++)
		for(int j=0;j<e[y].size();j++) ans=min(ans,mp[{x,e[x][i]}]+mp[{y,e[y][j]}]+dis[e[x][i]][e[y][j]]);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
} 
