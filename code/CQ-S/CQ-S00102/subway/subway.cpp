#include <bits/stdc++.h>
#define ll long long
#define fr a[k][i].x
#define se a[k][j].x
using namespace std;
/*
easy题，把地铁线路抽象成点，算出两两最短路就over了。
d<=20,md^2轻松跑。 
*/
const int N=505,M=500005,D=22;
struct node{
	int x,y;
}a[M][D];
int c,w[500005],n,m,d,q,l[M];
ll dis[N][N],an;
const ll inf=0x3f3f3f3f3f3f3f3fll;
//a:每个站厅有哪些线路经过，t：每个站厅到对应线路时间。 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=inf;
	for(int i=1;i<=n;i++){
		int k,x,t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&x);
			++l[x];
			a[x][l[x]].x=i;
			scanf("%d",&a[x][l[x]].y);
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=l[k];i++){
			for(int j=i+1;j<=l[k];j++){
				dis[fr][se]=min(dis[fr][se],1ll*(a[k][i].y+a[k][j].y));
				dis[se][fr]=dis[fr][se];
			}
		}
	}	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				(dis[i][k]+dis[k][j]<dis[i][j])&&(dis[i][j]=dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=1;j<i;j++)dis[i][j]=dis[j][i];
	}
	while(q--){
		int x,y;an=inf;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=l[x];i++){
			for(int j=1;j<=l[y];j++)an=min(an,a[x][i].y+a[y][j].y+dis[a[x][i].x][a[y][j].x]);
		}
		printf("%lld\n",an+w[x]+w[y]);
	}
	return 0;
}
