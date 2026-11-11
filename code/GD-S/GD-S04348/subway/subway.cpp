#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=(1LL<<50);
const int N=5e5+7;
const int M=505;
struct edge{
	int id,dis;
};
vector<edge>road[N];
vector<edge>a[M];
int dis[M][M];
int w[N];
int c,n,m,d,q;
int calc(int u,int v){
	int res=inf;
	for(auto st:road[u]){
		for(auto ed:road[v]){
			res=min(res,st.dis+dis[st.id][ed.id]+ed.dis);
		}
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,len;i<=n;i++){
		cin>>len;
		for(int j=1,id,t;j<=len;j++){
			cin>>id>>t;
			a[i].push_back({id,t});
			road[id].push_back({i,t});
		}
		for(int j=1;j<=n;j++) dis[i][j]=inf;
	}
	for(int u=1;u<=n;u++){
		dis[u][u]=0;
		for(auto st:a[u]){
			int id=st.id,use=st.dis;
			for(auto tag:road[id]){
				int v=tag.id;
				dis[u][v]=min(dis[u][v],use+tag.dis);
				dis[v][u]=min(dis[v][u],use+tag.dis);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(i==j||k==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=min(dis[j][i],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		cout<<calc(u,v)+w[u]+w[v]<<"\n";
	}
	return 0;
}
