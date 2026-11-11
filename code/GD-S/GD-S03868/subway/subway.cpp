#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
int c,n,m,d,q,t[N][M];
int w[M];
vector<int>dt[M];
ll dis[N][N];
int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int k,a,i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			a=read(),t[i][a]=read();
			dt[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=1e16;
		}
	}
	for(int i=1;i<=m;i++){
		for(int a=0;a<dt[i].size();a++){
			for(int b=0;b<a;b++){
				int u=dt[i][a],v=dt[i][b];
				dis[u][v]=min(dis[u][v],(ll)t[u][i]+t[v][i]);
				dis[v][u]=min(dis[v][u],(ll)t[u][i]+t[v][i]);
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
	for(int x,y,i=1;i<=q;i++){
		x=read(),y=read();
		ll ans=1e16;
		for(int j=0;j<dt[x].size();j++){
			for(int k=0;k<dt[y].size();k++){
				int u=dt[x][j],v=dt[y][k];
				ans=min(ans,(ll)t[u][x]+t[v][y]+dis[u][v]+w[x]+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
