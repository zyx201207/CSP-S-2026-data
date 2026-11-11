#include<iostream>
using namespace std;
int c,n,m,d,q,k;
int w[500001],dp[5001][5001],l[5001][21];
void floyd(){
	for(int i=1;i<=m;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int z=1;z<=m;z++){
					dp[j][i]=min(dp[j][i],dp[j][z]+dp[z][z]+dp[z][i]);
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%i%i%i%i%i",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%i",w+i);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=(int)1e8;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%i",&k);
		for(int i=1,in1,in2,mem=0;i<=k;i++){
			scanf("%i%i",&in1,&in2);
//			cout<<in1<<in2;
			l[in1][++l[in1][0]]=in2;
			mem=in1;
		}
	}
	floyd();
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			printf("%i ",dp[i][j]);
//		}
//		printf("\n");
//	}
	for(int i=1,in1,in2;i<=q;i++){
		scanf("%i%i",&in1,&in2);
		printf("%i\n",dp[in1][in2]);
	}
	return 0;
}

