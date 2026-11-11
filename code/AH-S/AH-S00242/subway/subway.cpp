#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int ce,n,m,d,q,zt=1;
long long int w[N],t[1010][500],a[1010][500];
long long int dp[1010][1010]={INT_MAX};
int k[500];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&ce,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[500]);
		if(k[i]!=2)zt=0;
		for(int j=1;j<=k[i];j++){
			scanf("%lld %lld",&a[i][j],&t[i][j]);
		}
	}
	if(zt){
		for(int l=1;l<=q;l++){
			int b,c;
			scanf("%d %d",&b,&c);
			for(int i=1;i<=n;i++){
				int x=a[i][1],y=a[i][2];
				for(int j=1;j<=m;j++)dp[j][y]=min(dp[j][y],dp[j][x]);
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(a[i][2]==a[j][1])dp[j][1]=dp[j][2]=min(dp[j][1],dp[i][2]+t[i][2]+t[j][1]);
				}
			}
			printf("%lld\n",dp[b][c]);
		}
	}
	return 0;
}
