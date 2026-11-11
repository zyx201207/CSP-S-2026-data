//10 points
#include <bits/stdc++.h>
using namespace std;
const int N=2005;
long long dp[N][20];
long long a[N];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(dp,128,sizeof dp);
	scanf("%d",&n,&m);
	long long maxx=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i][0]=max(maxx,a[i]);
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=i;j++){
			if(dp[i][cnt]&a[j]<dp[i][cnt+1]){
				dp[i][cnt+1]=dp[i][cnt]&a[j];
				cnt++;
			}
			if(dp[i-1][cnt]&a[j]<dp[i][cnt+1]){
				dp[i][cnt+1]=dp[i-1][cnt]&a[j];
				cnt++;
			}
		}
	}
	printf("%d",dp[n][m]);
	return 0;
}