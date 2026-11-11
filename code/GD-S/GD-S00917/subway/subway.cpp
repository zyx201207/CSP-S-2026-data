#include<stdio.h>
const int N=505, M=5e5+15;//N为线路数，M为站点数
const long long ma=9e18+5; 
int n, m, q, w[N];//n为地铁线路的数量，m为站点数，w[i]为从第 i站的地铁口走到站厅需要的时间  
int r, x, y, i, j, k, u[N][N];
long long ans=ma;
struct xian{//m表示这条线一共有m个站 
	int a[N], t[N], z[N], m;//a[j] 表示该线路经过的第j个地铁站 
}d[N];//t[j] 表示从第 j个地铁站的站厅走到该线路的站台需要的时间。
void dfs(int k, int x, int hua, int ff){//现在是在第 k条线的第 x站，花费为 hua 
	if(x>d[k].m||x<1) return ;
	if(d[k].a[x]==y){
		if(hua+w[y]+d[k].t[x]<ans) ans=hua+w[y]+d[k].t[x];
		return ;
	} 
//	printf("k=%d d[k].a[x]=%d hua=%d\n", k, d[k].a[x], hua);
	if(ff) dfs(k, x+1, hua, ff);
	else dfs(k, x-1, hua, ff);
	for(i=1; i<=n; i++){
		for(j=1; j<=d[i].m; j++){
			if(!u[i][x]&&!u[x][i]&&k!=i&&d[i].a[j]==d[k].a[x]){
				u[i][x]=u[x][i]=1;
				dfs(i, j, hua+d[i].t[j]+d[k].t[x], 1);//换乘 
				dfs(i, j, hua+d[i].t[j]+d[k].t[x], 0);
				u[i][x]=u[x][i]=0;
			}
		}
	}
//	dfs(k, x-1, hua);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%*d %d %d %*d %d", &n, &m, &q);
	for(i=1; i<=m; i++) scanf("%d", &w[i]);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i].m);
		for(j=1;j<=d[i].m;j++){
			scanf("%d %d", &d[i].a[j], &d[i].t[j]);
		}
	}
	for(k=1; k<=q; k++){
		scanf("%d %d", &x, &y);
		ans=ma;
		for(i=1; i<=n; i++){
			for(j=i; j<=n; j++) u[i][j]=0;
		} 
		for(i=1; i<=n; i++){
			for(j=1; j<=d[i].m; j++){
				if(d[i].a[j]==x){
					for(int z=1; z<=n; z++) u[i][z]=u[z][i]=1;
					dfs(i, j, w[x]+d[i].t[j], 1);
					dfs(i, j, w[x]+d[i].t[j], 0);
					for(int z=1; z<=n; z++) u[i][z]=u[z][i]=0;
				} 
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
