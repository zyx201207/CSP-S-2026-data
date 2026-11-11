#include<bits/stdc++.h>
using namespace std;
int dis[100][100];
int p[100];
bool vis[100];
void dfs(int t,int m) {
	if(m>t) {
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) {
			p[m]=i;
			vis[i]=1;
			dfs(t,m+1);
			vis[i]=0;
		}
	}
}
int cnt=0;

int main() {
	int c,t;
	cin>>c>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n-1;i++) {
			int u,v;
			cin>>u>>v;
			dis[u][v]=dis[v][u]=1;
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				for(int k=1;k<=n;k++) {
					dis[u][v]=min(dis[u][k]+dis[k][u]);
				}
			}
		}
	}
	return 0;
}
/*
	唉...为什么呢
	太令人失望了...
	subway...
	我在做梦吗?
	怎么会这样子啊...
	AFO On 2026/10/31  
*/
