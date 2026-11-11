#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=500005;
struct node{
	int id,x;
};
int C,n,m,d,Q,w[M],kk[N],st,ed,ans,t[M],dis[N][N],siz,u,v;
vector<node>e[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>kk[i];
		for(int j=1,x,y;j<=kk[i];j++){
			cin>>x>>y;
			e[x].push_back({i,y});
		}
		for(int j=i+1;j<=n;j++){
			dis[i][j]=1e18;
			dis[j][i]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		siz=e[i].size();
		if(siz>=2){
			for(int j=0;j<siz;j++){
				for(int h=j+1;h<siz;h++){
					u=e[i][j].id,v=e[i][h].id;
					dis[u][v]=min(dis[u][v],e[i][j].x+e[i][h].x);
					dis[v][u]=min(dis[v][u],e[i][j].x+e[i][h].x);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	while(Q--){
		cin>>st>>ed;
		ans=1e18;
		for(int i=0;i<e[st].size();i++){
			for(int j=0;j<e[ed].size();j++){
				ans=min(ans,dis[e[st][i].id][e[ed][j].id]+e[st][i].x+e[ed][j].x);
			}
		}
		ans+=w[st]+w[ed];
		cout<<ans<<endl;
	}
	return 0;
}
