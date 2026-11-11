#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001],dp[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(!dp[a[j]]){
				dp[a[j]]=j;
			}else{
				for(int l=j-1;l>dp[a[j]];l--){
					dp[a[l]]=0;
				}
				dp[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(dp[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
