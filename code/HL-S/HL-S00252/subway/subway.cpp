#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+5;
int c,n,m,d,q;
ll w[M];
vector<pair<int,ll> > s[505];
vector<pair<int,int> > way[M]; //记录站台在那些线路中
ll f[505][505]; //i站台换乘到j站台的最小cost 
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) 
		scanf("%d",&w[i]) ;
	for(int i=1;i<=n;i++) {
		int l; scanf("%d",&l);
		for(int j=0;j<l;j++) {
			int a; ll t; scanf("%d%lld",&a,&t);
			s[i].push_back(make_pair(a,t));
			way[a].push_back(make_pair(i,j));
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=(i==j)?0ll:LLONG_MAX/2;
	//先求可以直接换乘的 
	for(int i=1;i<=n;i++) { //枚举当前线路 
		for(int k=0;k<(int)s[i].size();k++) { //枚举直接可达的站台 
			int u=s[i][k].first;
			ll w=s[i][k].second; //在线路i走到该站站厅所需的时间 
			for(int j=0;j<(int)way[u].size();j++) { //枚举可以直接换乘的线路 
				int v=way[u][j].first;
				//if(v==i) continue;
				int pos=way[u][j].second;
				ll d=s[v][pos].second; //从站台到线路v的时间 
				if(v==i) continue;
				//printf("%d->%d(%d+%d)\n",i,v,w,d);
				f[i][v]=min(f[i][v],w+d);
				//f[v][i]=min(f[v][i],w+d);
			}
		}
	}
	/*for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}*/
	//类floyd
	for(int k=1;k<=n;k++) 
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]); 
	
	while(q--) {
		int u,v; scanf("%d%d",&u,&v);
		ll del=w[u]+w[v];
		ll res=LLONG_MAX;
		for(int i=0;i<(int)way[u].size();i++)
			for(int j=0;j<(int)way[v].size();j++) {
				pair<int,int> x=way[u][i],y=way[v][j];
				res=min(res,s[x.first][x.second].second+f[x.first][y.first]+s[y.first][y.second].second);
			}
		printf("%lld\n",del+res);
	}
	return 0;
}

