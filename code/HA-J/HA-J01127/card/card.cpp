#include<bits/stdc++.h>
using namespace std;
int n,m,a[25000000],dp[25000000],w[25000000],ans[25000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		dp[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<=n;j++){
			if(dp[a[i]]==0){
				dp[a[i]]=1;
				w[a[i]]=i;
			} 
			else{
				for(int e=i;i>=w[a[i]];e--){
					a[i]=0;
					dp[a[i]]=0;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(dp(a[i])==1) ans[a[i]]+=1;
		}
		for(int i=0;i<n;i++){
			dp[i]=0;
		}
	}
	for(int=0;i<n;i++){
		printf("%d",ans[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
