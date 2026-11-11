#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=510,M=5e5+10;
struct node{
	int nex, val;
	bool operator>(const node dist)const{
		return val>dist.val;
	}
};
vector<node>pt[M],g[N];
int w[M],G[N][N],dis[N],dp[N][N];
void dij(int s){
	priority_queue<node,vector<node>,greater<node> > pq;
	dis[s]=0;
	pq.push((node){s,0});
	while(!pq.empty()){
		node u=pq.top();
		pq.pop();
		if(dis[u.nex]<u.val) continue;
		for(int i=0;i<g[u.nex].size();i++){
			int nu=g[u.nex][i].nex,nv=g[u.nex][i].val;
			if(dis[nu]>dis[u.nex]+nv){
				dis[nu]=dis[u.nex]+nv;
				pq.push((node){nu,dis[nu]}); 
			}
			//cout<<u.nex<<" "<<nu<<" "<<dis[nu]<<" "<<dis[u.nex]+nv<<endl;
		}
//		for(int i=0;i<=n+1;i++) cout<<dis[i]<<" ";
//		cout<<endl;
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			pt[x].push_back((node){i,y});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) G[i][j]=1e15;
	for(int i=1;i<=m;i++){
		int fs=pt[i][0].nex,v=pt[i][0].val;
		for(int j=1;j<pt[i].size();j++){
			int u=pt[i][j].nex;
			G[fs][u]=min(G[fs][u],v+pt[i][j].val);
			G[u][fs]=min(G[fs][u],G[u][fs]);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<G[i][j]<<" ";
//		cout<<endl;
//	}
	if(c>0&&c<=8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(G[i][j]!=1e15){
					g[i].push_back((node){j,G[i][j]});
					g[j].push_back((node){i,G[i][j]});	
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			g[0].clear();
			for(int j=0;j<pt[x].size();j++){
				int u=pt[x][j].nex;
			//	cout<<u<<endl;
				g[0].push_back((node){u,w[x]+pt[x][j].val});
			}
			for(int j=0;j<pt[y].size();j++){
				int u=pt[y][j].nex;
				g[u].push_back((node){n+1,w[y]+pt[y][j].val});
			}
//			for(int i=0;i<=n+1;i++){
////			for(int j=0;j<g[i].size();j++) cout<<i<<" "<<g[i][j].nex<<" "<<g[i][j].val<<endl;
////		}
			for(int j=1;j<=n+1;j++) dis[j]=1e18;
			dij(0);
			for(int j=1;j<=n;j++){
				if(g[j][g[j].size()-1].nex==n+1){
					g[j][g[j].size()-1].nex=n+2;
				}
			}
			cout<<dis[n+1]<<endl;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dp[i][j]=1e15;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(G[i][j]!=1e15){
					dp[i][j]=G[i][j];
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int x,y,minn=1e18;
			cin>>x>>y;
			for(int j=0;j<pt[x].size();j++){
				for(int k=0;k<pt[y].size();k++){
					minn=min(minn,dp[pt[x][j].nex][pt[y][k].nex]);
				}
			}
			cout<<w[x]+w[y]+minn+2*pt[x][0].val<<endl;
		}
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
