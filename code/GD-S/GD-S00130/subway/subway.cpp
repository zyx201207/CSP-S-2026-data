#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=510,N=5e5+10,inf=0x3f3f3f3f3f3f3f3f;

ll c,n,m,d,q,k,u,v;
ll dis[maxn][maxn],w[N];
vector<pair<ll,ll> >pos[N];//第i个节点能连接的站台编号以及其权值 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	double st=clock();
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>v;
			pos[u].push_back({i,v});
		}
	}memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<pos[i].size();j++){
			for(k=j+1;k<pos[i].size();k++){
				ll u=pos[i][j].first,v=pos[i][k].first;
				ll w=pos[i][k].second+pos[i][j].second;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	while(q--){
		cin>>u>>v;
		ll res=inf;
		for(auto i:pos[u]){
			for(auto j:pos[v]){
				ll x=i.first,y=j.first;
				res=min(res,dis[x][y]+i.second+j.second);
			}
		}
		cout<<res+w[u]+w[v]<<endl;
//		cout<<res<<endl;
	}//cout<<(double)clock()-st;
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
