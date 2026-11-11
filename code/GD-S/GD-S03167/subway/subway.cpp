#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+10;
const long long inf=1e18;
long long c,n,m,d,q;
long long w[M],g[N][N],ans;
struct node{
	long long u;
	long long t;
};
vector<node>r[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,u,t;j<=k;j++){
			cin>>u>>t;
			r[u].push_back(node{i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=inf;
		}
		g[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<r[i].size();x++){
			long long u=r[i][x].u;
			long long t=r[i][x].t;
			for(int y=x+1;y<r[i].size();y++){
				long long v=r[i][y].u;
				long long tl=r[i][y].t;
				g[u][v]=min(g[u][v],t+tl);
				g[v][u]=min(g[v][u],t+tl);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)	continue;
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=inf;
		for(int i=0;i<r[x].size();i++){
			long long u=r[x][i].u;
			long long t=r[x][i].t;
			for(int j=0;j<r[y].size();j++){
				long long v=r[y][j].u;
				long long tl=r[y][j].t;
				ans=min(ans,w[x]+w[y]+t+tl+g[u][v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
fc subway.out ex.txt
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
35
16

0 2 4 2 1
1 2 3 4
3 1 4 2 3 4 2
3 1 3 3 9 4 1
1 4
9

0 2 4 2 3
1 1 1 1
3 1 1 2 1 3 1
3 2 10 3 2 4 1
1 4
1 3
2 4
7 4 7
*/
