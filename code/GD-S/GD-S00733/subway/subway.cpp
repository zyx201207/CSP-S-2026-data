#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,M=5e5+10;
ll c,n,m,d,q,w[M],edge[N][N];
int a[M][N];//a[i][j]:第i个点到第j条路线 ,n条路线，m个站点 
vector<int>s[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,x;i<=n;i++){
		cin>>x;
		while(x--){
			int u,v;
			cin>>u>>v;
			a[u][i]=v;
			s[u].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)edge[i][j]=LLONG_MAX/2;
//	memset(edge,0x3f3f3f3f,sizeof edge);
	for(int i=1;i<=m;i++)
	for(int u:s[i])
	for(int v:s[i])
	if(u!=v){
		ll t=a[i][u]+a[i][v];
		edge[u][v]=min(edge[u][v],t);
//		cout<<u<<' '<<v<<' '<<edge[u][v]<<'\n';
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j&&j!=k&&i!=k&&edge[i][k]!=LLONG_MAX/2&&edge[k][j]!=LLONG_MAX/2){
		edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
//		cout<<i<<' '<<j<<' '<<k<<' '<<edge[i][j]<<'\n';
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=LLONG_MAX/2; 
		for(int x:s[u])
			for(int y:s[v]){
				if(x==y)ans=min(ans,w[u]+w[v]+a[u][x]+a[v][y]);
				else if(edge[x][y]!=LLONG_MAX/2)ans=min(ans,w[u]+w[v]+a[u][x]+a[v][y]+edge[x][y]);
//				cout<<x<<' '<<y<<' '<<a[u][x]<<' '<<a[v][y]<<'\n';
			}
		cout<<ans<<'\n';
	}
	return 0;
}

