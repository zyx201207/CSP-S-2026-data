#include <bits/stdc++.h>
using namespace std;
long long dp[200003];
long long zc[200003]; 
int zj[200003];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,wz=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&zc[i]);
		if(zc[i]>dp[1]){
			dp[1]=zc[i];
			wz=i;
		}
	}
	zj[wz]=1;
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(zj[j]==0){
				if(dp[i]<(dp[i-1]&zc[j])){
					dp[i]=(dp[i-1]&zc[j]);
					wz=j;
				}
			}
		}
		zj[wz]=1;
	}
	printf("%lld",dp[m]);
}
