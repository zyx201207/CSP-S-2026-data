#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m,c,d,q;
int w[N],k[N];
int a[505][N],t[N][25];
vector<int> dt[N];
int dis[1005][1005];
int s,e;
void aa(int x){
	for(int j=0;j<dt[x].size();j++){
		int y=dt[x][j];
		for(int i=1;i<=k[y];i++){
			int v=a[y][i];
			if(v==x) continue;
			if(dis[v][x]==0x7fffff){
				dis[x][v]=min(dis[x][v],t[x][y]+t[v][y]);
				dis[v][x]=dis[x][v];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d",&a[i][j]);
			scanf("%d",&t[a[i][j]][i]);
			dt[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=0x7fffff;
		}
	}
	for(int i=1;i<=m;i++){
		aa(i);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int b=1;b<=m;b++){
				if(b==i||b==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][b]+dis[b][j]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&s,&e);
		printf("%d\n",w[s]+dis[s][e]+w[e]);
	}
	return 0;
}
