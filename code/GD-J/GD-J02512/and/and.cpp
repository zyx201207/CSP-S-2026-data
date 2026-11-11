#include<bits/stdc++.h>
using namespace std;
int a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i]=a[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=n;j>=i;j--){
			int t=dp[i-1]&a[j];
			for(int k=i;k<j;k++){
				t=max(t,dp[k]&a[j]);
			}
			dp[j]=t;
		}
	}//m=2e5,n=2e5,O(mn^2)=8e15>>1e8 
	int ans=dp[m];
	for(int i=m+1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}//9/20 TLE
