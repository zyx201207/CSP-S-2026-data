#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x;
}
#define N 600010
int C,n,m,d,q;
int cost[N];
struct HW{
	int v,w;
};
vector<HW>e[N];
int dis[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)cost[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int u=read(),w=read();
			e[u].push_back((HW){i,w});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=LLONG_MAX;
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			int v1=e[i][j].v;
			for(int k=0;k<j;k++){
				int v2=e[i][k].v;
				dis[v2][v1]=dis[v1][v2]=min(dis[v1][v2],e[i][j].w+e[i][k].w);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dis[i][k]==LLONG_MAX||dis[k][j]==LLONG_MAX)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}cout<<endl;
//	}
	while(q--){
		int u=read(),v=read();
		int ans=LLONG_MAX;
		for(int i=0;i<e[u].size();i++){
			int s1=e[u][i].v;
			for(int j=0;j<e[v].size();j++){
				int s2=e[v][j].v;
				ans=min(ans,e[u][i].w+e[v][j].w+dis[s1][s2]);
			}
		}
		cout<<ans+cost[u]+cost[v]<<endl;
	}
	return 0;
}

