#include<iostream>
#include<stdio.h>
#define MAXN 504
#define LL long long
using namespace std;

int c,m,n,d,q;
LL w[5004];
LL k[500004];
LL t[500004];
LL cost[5004][5004];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cost[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)cost[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		for(int j=1;j<=num;j++){
			scanf("%lld%lld",&k[j],&t[j]);
		}
		for(int j=1;j<=num;j++){
			for(int l=1;l<=num;l++){
				
				cost[k[j]][k[l]]=min(cost[k[j]][k[l]],t[j]+t[l]);
				cost[k[l]][k[j]]=min(cost[k[l]][k[j]],t[j]+t[l]);
//				printf("%lld %d %d %lld %lld\n",cost[k[j]][k[l]],k[j],k[l],t[j],t[l]);
			}
		}
	}
	//mÎªµØÌúÕ¾Êý£¡£¡£¡£¡£¡ 
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				cost[i][j]=min(cost[i][j],cost[i][l]+cost[l][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
////			printf("%20lld ",cost[i][j]);
//			
//		}
////		printf("\n");
//	}
	for(int i=1;i<=q;i++){
		int start,to;
		scanf("%d%d",&start,&to);
		printf("%lld\n",cost[start][to]+w[start]+w[to]);
	}
	
	return 0;
}
