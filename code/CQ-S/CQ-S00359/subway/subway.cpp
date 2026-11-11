#include <bits/stdc++.h>
using namespace std;
#define int long long 
int read(){
	int x=0,f=1; char h=getchar();
	while(!isdigit(h)){if(h=='-') f=-f; h=getchar();}
	while(isdigit(h)){x=(x<<3)+(x<<1)+(h^48); h=getchar();}
	return x*f;
}
const int N=500+10;
const int M=5e5+10;
const int INF=1e18;
int c,n,m,d,Q,dis[N][N],val[M];
struct Edge{int a,t;};
vector<Edge> e[M];
signed main(){
//	freopen("D:/csps-new/down/subway/subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	for(int i=1;i<=m;i++) val[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int a=read(),t=read();
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=dis[j][i]=INF;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int u=0;u<(int)e[i].size();u++){
			for(int v=u+1;v<(int)e[i].size();v++){
				int x=e[i][u].a,t1=e[i][u].t;
				int y=e[i][v].a,t2=e[i][v].t;
				dis[x][y]=dis[y][x]=min(dis[x][y],t1+t2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	while(Q--){
		int u=read(),v=read();
		int ans=INF;
		for(auto &edge1:e[u]){
			for(auto &edge2:e[v]){
				int x=edge1.a,t1=edge1.t;
				int y=edge2.a,t2=edge2.t;
				if(dis[x][y]!=INF) ans=min(ans,dis[x][y]+t1+t2+val[u]+val[v]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
我把T2做出来了！！！！！ 
*/
