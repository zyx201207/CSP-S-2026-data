#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
#define N 510
#define M 500010
using namespace std;
const ll inf=1000000000000;
int n,m,D,q;
int mp;
ll dis[N][N],a[M];
vector<pair<int,ll> >G[M];
void sol(){
	cin>>n>>m>>D>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(i!=j)?inf:0;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k,u,w;
		cin>>k;
		while(k--){
			cin>>u>>w;
			G[u].push_back(make_pair(i,w));
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:G[i])
			for(auto v:G[i])
				dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
	while(q--){
		int u,v;
		ll ans;
		cin>>u>>v;
		ans=inf;
		for(auto i:G[u])
			for(auto j:G[v])
				ans=min(ans,i.second+j.second+dis[i.first][j.first]);
		cout<<ans+a[u]+a[v]<<'\n';
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	int cid;
	cin>>cid;
	sol();
	return 0;
}
