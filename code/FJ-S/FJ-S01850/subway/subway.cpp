#include<bits/stdc++.h>
using namespace std;
#define int long long
#define file(S) freopen(S".in","r",stdin),freopen(S".out","w",stdout);
const int N=510;
const int M=5e5+10;
int c,n,m,d,q;
int dis[N][N];
int w[M];
map<pair<int,int>,int> mp;
int bel[M][30];
void Luo_Saisei() {
	cin>>c>>n>>m>>d>>q;
	mp.clear();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		vector<int> v(k+1);
		for(int j=1; j<=k; j++) cin>>v[j],cin>>mp[{v[j],i}],bel[v[j]][++bel[v[j]][0]]=i; //链上标记
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=bel[i][0]; j++) {
			int u=bel[i][j];
			for(int k=1; k<=bel[i][0]; k++) {
				int v=bel[i][k];
				if(u==v) continue;
				dis[u][v]=min(dis[u][v],mp[{i,u}]+mp[{i,v}]);
				dis[u][v]=min(dis[u][v],mp[{i,v}]+mp[{i,u}]);
			}
		}
	}
//	cout<<dis[1][2]<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(i==j||j==k||i==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int Ans=1e18;
		for(int i=1;i<=bel[x][0];i++)
		{
			for(int j=1;j<=bel[y][0];j++)
			{
				int u=bel[x][i];
				int v=bel[y][j];
				Ans=min(Ans,w[x]+mp[{x,u}]+mp[{y,v}]+w[y]+dis[u][v]);
			}
		}
		cout<<Ans<<'\n';
	}
	return ;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	file("subway");
	int T=1;
//	cin>>T;
	while(T--) Luo_Saisei();
}
// 预处理每条链之间的dis 跑一下 floyd n^3 然后就做完了
//16:22 我好菜啊 
