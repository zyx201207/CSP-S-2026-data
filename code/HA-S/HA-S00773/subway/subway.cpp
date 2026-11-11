#include<bits/stdc++.h>
using namespace std;
const int N=501010,S=510;
int c,n,m,d,q;
struct node{
	long long x,y;
}qy[N];
vector <node> e[N];
long long exw[N],dis[S][S];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)  cin>>exw[i];
	for(int i=1;i<=n;i++){
		long long tk,ta,tt;
		cin>>tk;
		for(int j=1;j<=tk;j++){
			cin>>ta>>tt;
			e[m+i].push_back({ta,tt});
			e[ta].push_back({m+i,tt});
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		qy[i]={u,v};
	}
	memset(dis,0x3f,sizeof(dis));
//	cout<<dis[0][0]<<endl;
	for(int i=1;i<=n;i++)  dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int sz=e[i].size();
		for(int j=0;j<sz;j++){
			for(int k=0;k<sz;k++){
				if(j==k)  continue;
				long long u=e[i][j].x-m,v=e[i][k].x-m,w=e[i][j].y+e[i][k].y;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u=qy[i].x,v=qy[i].y;
		long long ans=dis[0][0];
		for(auto f:e[u]){
			for(auto t:e[v]){
				long long x=f.x-m,y=t.x-m,w=f.y+t.y;
				ans=min(ans,dis[x][y]+w+exw[u]+exw[v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 

/*
-O2 -std=c++14 -static
-static-libgcc

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

fc subway.out subway7.ans /n

*/
