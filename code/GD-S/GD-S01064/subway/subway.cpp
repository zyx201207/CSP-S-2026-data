#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
constexpr int N=503,M=5e5+5;
int c,n,m,d,q;
int w[M],k[N];
ll minc[N][N],dis[N][N];
vector<int>a[N],vis[M];
vector<ll>t[N];
map<pii,int>mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			vis[a[i][j]].push_back(i);
			mp[{i,a[i][j]}]=j;
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int u:vis[i])
			for(int v:vis[i])
				if(u!=v)
					dis[u][v]=min(dis[u][v],t[u][mp[{u,i}]]+t[v][mp[{v,i}]]);
				else
					dis[u][v]=0ll;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
	while(q--){
		int u,v;
		cin>>u>>v;
		long long zch=w[u]+w[v],ans=1e18;
		for(int ls:vis[u])
			for(int le:vis[v])
				ans=min(ans,zch+t[ls][mp[{ls,u}]]+t[le][mp[{le,v}]]+dis[ls][le]);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
