#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],dp[10001][10001],f[200001],last=0;
bool vis[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
//		dp[i][1]=max(dp[i-1][1],a[i]); 
		if(a[i]>f[1]){
			f[1]=a[i];
			vis[i]=true;
			vis[last]=false;
			last=i;
		}
	}
	last=0;
//	for(int i=1;i<=n;i++){
//		for(int j=2;j<=m;j++){
//			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if((f[j-1]&a[i])>f[j]&&vis[i]==false){
				f[j]=f[j-1]&a[i];
				vis[i]=true;
				vis[last]=false;
				last=i;
			}
		}
	}
//	printf("%d",dp[n][m]);
	printf("%d",f[m]);
	return 0;
}
