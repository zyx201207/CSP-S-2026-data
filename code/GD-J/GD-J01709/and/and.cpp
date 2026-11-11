#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],dp[200001];
int main(){
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	const int maxint=((1<<30)-1)+(1<<30);
	dp[0]=maxint;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[j-1]==maxint){
				dp[j]=a[i];
				continue;
			}
			dp[j]=max(dp[j-1]&a[i],dp[j-1]);
		}
	}
	cout<<dp[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
