#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;
const int N=6e5+999;
const int INF=1e18+99999,rinf=5e17+99999;
int C,n,m,d,q;
int w[N];
vector<pair<int,int> >lu[N];
vector<pair<int,int> >e[N];
int dis[502][502];
void shuru(){
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			lu[x].pb(mp(i,y));
		} 
		for(int j=0;j<=n+1;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto a:lu[i]){
			int x=a.first,xz=a.second;
			for(auto b:lu[i]){
				int y=b.first,yz=b.second;
				if(x==y)continue;
//				e[x].pb(mp(y,xz+yz));
//				e[y].pb(mp(x,xz+yz));
				dis[x][y]=min(dis[x][y],xz+yz);
				dis[y][x]=min(dis[y][x],xz+yz);
			}
		}
	}
	return ;
}
//priority_queue<pair<int,int> >
//void djtsl()
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	shuru();
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(dis[i][k]>rinf)continue;
			for(int j=i+1;j<=n;j++){
				if(dis[k][j]>rinf)continue;
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
				dis[j][i]=min(dis[k][i]+dis[j][k],dis[j][i]);
			}
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		int zans=INF;
		for(auto a:lu[u]){
			for(auto b:lu[v]){
				int x=a.first,xz=a.second,y=b.first,yz=b.second;
				zans=min(zans,dis[x][y]+xz+yz+w[u]+w[v]);
			}
		}
		cout<<zans<<"\n";
	}
	return 0;
} 
