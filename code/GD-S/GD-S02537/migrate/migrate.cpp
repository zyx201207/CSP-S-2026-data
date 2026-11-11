#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],dp[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	for(int TTT=1;TTT<=T;TTT++){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int mini=INT_MAX;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=m)mini=min(mini,dp[j]);
			}
			int sum=0;
			for(int j=i-1;j>=1;j--){
				if(dp[j]==mini){
					sum++;
				}
			}
			if(sum==2){
				ans++;
			}
			dp[i]=mini+1;
		}
		printf("%d\n",ans);
	} 
	
}
