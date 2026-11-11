#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=5e2+7,maxm=5e5+7;
const ll inf=1e16;
int c,n,m,lim,q;
int w[maxm],d[maxm];
ll dis[maxn][maxn];
struct node{
	int to,len;
}e[maxm][22];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&lim,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1,k,x,y;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x,&y);
			e[x][++d[x]]=(node){i,y};
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=d[i];j++){
			int x=e[i][j].to;
			for(int k=1;k<j;k++){
				int y=e[i][k].to;
				dis[x][y]=dis[y][x]=min(dis[x][y],(ll)e[i][j].len+e[i][k].len);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(j==i||j==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int t=1,x,y;t<=q;t++){
		scanf("%d%d",&x,&y);
		ll res=inf;
		for(int i=1;i<=d[x];i++) for(int j=1;j<=d[y];j++) res=min(res,dis[e[x][i].to][e[y][j].to]+(ll)e[x][i].len+(ll)e[y][j].len);
		printf("%lld\n",res+w[x]+w[y]);
	}
	return 0;
}
