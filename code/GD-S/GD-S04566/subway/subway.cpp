#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
ll c,n,m,d,q,vis[N][N],e[N][N],w[M],p[N],ans;
vector<pair<int,int>>v[M];
void dijkstra(int x){
	for(int i=0;i<=n;i++)p[i]=0,vis[x][i]=1e18;
	vis[x][x]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(p[j]==0&&vis[x][j]<=vis[x][u])u=j;
		}
		p[u]=1;
		for(int j=1;j<=n;j++)vis[x][j]=min(vis[x][j],vis[x][u]+e[u][j]);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,x,a,b;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a>>b;
			v[a].push_back({i,b});
		}
		for(int j=1;j<=n;j++)e[i][j]=1e18;
		e[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(pair<int,int>j:v[i]){
			for(pair<int,int>k:v[i]){
				ll x=j.first,y=k.first,z=j.second+k.second;
				e[x][y]=min(e[x][y],z),e[y][x]=min(e[y][x],z);
			}
		}
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y,ans=1e18;
		for(pair<int,int>j:v[x]){
			for(pair<int,int>k:v[y]){
				ans=min(ans,vis[j.first][k.first]+j.second+k.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
