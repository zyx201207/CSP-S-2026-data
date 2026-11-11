#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M];
struct st{
	int ln,st;
};
vector<st> ss;
struct edge{
	int v,w;
};
vector<edge> e[2*M];
void adde(int a,int b,int w){
	e[a].push_back({b,w});
	e[b].push_back({a,w});
}
//sp[line][station]->pos in vec ss
int sp[N][M];
int psum;
int dis[2*M];
bool vis[2*M];
void dij(int u){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[u]=0;
	for(int i=1;i<psum;i++){
		int t=0,dt=0x3f3f3f3f;
		for(int j=0;j<psum;j++)
			if(!vis[j]&&dis[j]<dt) t=j,dt=dis[t];
		vis[t]=true;
		for(int j=0;j<e[t].size();j++){
			int v=e[t][j].v;
			if(!vis[v])
				dis[v]=min(dis[v],dis[t]+e[t][j].w);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int k,a,tt;
	memset(sp,-1,sizeof sp);
	for(int i=1;i<=m;i++){
		ss.push_back({0,i});
		sp[0][i]=ss.size()-1;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		bool f=true;
		int pre=-1;
		for(int j=1;j<=k;j++){
			cin>>a>>tt;
			ss.push_back({i,a});
			if(!f){
				adde(pre,ss.size()-1,0);
				pre=ss.size()-1;
			}else{
				f=false;
				pre=ss.size()-1;
			}
			sp[i][a]=ss.size()-1;
			adde(sp[0][a],sp[i][a],tt);
		}
	}
	psum=ss.size();
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(sp[0][x]);
		int ans=dis[sp[0][y]]+w[x]+w[y];
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
