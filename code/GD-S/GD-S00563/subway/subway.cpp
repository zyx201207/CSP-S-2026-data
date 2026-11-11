#include<bits/stdc++.h>
#define ll long long
#define love_Elysia return
#define forever 0
using namespace std;
const int N=500+10,M=5e5+10;
int c,n,m,d,q;
ll dist[N+1][N+1],w[M+1];
vector<pair<int,ll> >xl[N+1];
vector<pair<int,ll> >g[M+1];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=(1ll<<61);
		}
		dist[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<xl[i].size();j++){
			int u=xl[i][j].first,nowzt;
			for(int k=0;k<g[u].size();k++){
				if(g[u][k].first==i){
					nowzt=k;
					break;
				}
			}
			for(int k=0;k<g[u].size();k++){
				int vx=g[u][k].first;
				if(vx==i)continue;
				dist[i][vx]=min(dist[i][vx],g[u][nowzt].second+g[u][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dist[i][j]<<' ';
//		}
//		cout<<endl;
//	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//	c=read();n=read();m=read();d=read();q=read();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;ll t1;
			cin>>x>>t1;
			xl[i].push_back(make_pair(x,t1));
			g[x].push_back(make_pair(i,t1));
		}
	}
	init();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ll ans=LLONG_MAX;
		for(int i1=0;i1<g[x].size();i1++){
			int xlx=g[x][i1].first;
			for(int j=0;j<g[y].size();j++){
				int xly=g[y][j].first;
				ans=min(ans,dist[xlx][xly]+w[x]+w[y]+g[x][i1].second+g[y][j].second);
			}
		}
		cout<<ans<<'\n';
	}
	
	
	love_Elysia forever;
} 
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2

*/
