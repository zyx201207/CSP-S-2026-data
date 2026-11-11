//#include<bits\stdc++.h>
//LeLeLe
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5,M=2e6+5;
int c,n,m,d,q;
int dis[N][N],w[N],g[N][N];
int idx,ver[M<<1],nxt[M<<1],hd[N],val[M<<1];
bool vis[N];
void add(int x,int y,int z){
	ver[++idx]=y;
	nxt[idx]=hd[x];
	hd[x]=idx;
	val[idx]=z;
}
struct node{
	int v,u;
	bool operator<(const node &x)const{
		return v>x.v;
	}
};
priority_queue<node>qe;
void dijk(int s){
	qe.push({0,s});
	dis[s][s]=0;
	//vis[s]=1;
	while(qe.size()){
		int u=qe.top().u;vis[u]=0;
		qe.pop();
		for(int i=hd[u];i;i=nxt[i]){
			int y=ver[i];
			if(vis[y])continue;
			if(dis[s][y]>dis[s][u]+val[i])dis[s][y]=dis[s][u]+val[i],qe.push({dis[s][y],y}),vis[y]=1;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("D:\\down\\subway\\subway1.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}int k,a,t,x,y;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			g[i][a]=t;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			add(i,j,g[i][j]+g[j][i]);
			add(j,i,g[i][j]+g[j][i]);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		dijk(i);
	}
	while(q--){
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
