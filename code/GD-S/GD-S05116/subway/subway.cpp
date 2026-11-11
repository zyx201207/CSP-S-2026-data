#include<bits/stdc++.h>
using namespace std;
const long long N = 5e2+5,M = 5e3+5,INF = 5e7+7;
long long c,n,m,d,q;
long long dista[M][M];//站厅a->站厅b的步行距离
long long dis[M];//站厅a->k线的步行距离
long long arr[M];//缓冲站厅数组
long long wt[N];//站口->站厅
//long long read(){
//	long long r = 0,w = 1;
//	char ch = getchar();
//	while(ch < '0' || ch > '9'){
//		if(ch == '-')	w = -1;
//		ch = getchar();
//	}
//	while(ch >= '0' && ch <= '9'){
//		r = r * 10 + ch - '0';
//		ch = getchar();
//	}
//	return r * w;
//}
void floyed(){
//	for(long long i = 1;i<=m;i++)
//		for(long long j = 1;j<=m;j++)
//			for(long long lin;lin <= n;lin++)
//				dista[i][j] = min(dista[i][j],dis[i][lin]+dis[j][lin]);
	for(long long k = 1;k<=m;k++)
		for(long long i = 1;i<=m;i++)
			for(long long j = 1;j<=m;j++)
				dista[i][j] = min(dista[i][j],dista[i][k]+dista[k][j]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
//	c = read();	n = read();	m = read();	lld = read();	q = read();
//	printf("ok\n");
	for(long long i = 1;i<=m;i++)	scanf("%lld",&wt[i]);//wt[i] = read();
	for(int i = 1;i<=m;i++)
		for(int j = 1;j<=m;j++)
			dista[i][j] = INF;
//	memset(dis,INF,sizeof(dis));
//	memset(dista,INF,sizeof(dista));
	for(long long k = 1,f;k<=n;k++){
//		f = read();
		scanf("%lld",&f);
		for(long long i = 1;i<=f;i++){
//			arr[i] = read();
			scanf("%lld",&arr[i]);
//			dis[i] = read();
			scanf("%lld",&dis[i]);
		}
		for(long long i = 1;i<=f;i++)
			for(long long j = 1;j<=f;j++)
				dista[arr[i]][arr[j]] = dis[i]+dis[j];
	}
	floyed();
	long long a,b;
	while(q--){
//		a = read();	b = read();
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",wt[a]+dista[a][b]+wt[b]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
