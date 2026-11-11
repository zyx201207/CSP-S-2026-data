#include<bits/stdc++.h>
using namespace std;
const int N=500100;
int a[N];
int dp[N];
int n,m,mp;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	mp=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=i;k++){
			if(a[k]==a[i]){
			    break;
			}
			if(!mp){
				a[k]++;
				mp--;
			}	
		}
		for(int t=1;t<=i;t++){
			if(a[t]==a[i]){
				dp[i]++;
			}
		}
		for(int j=1;j<=i;j++){
			dp[i]=max(dp[j],dp[i]);
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
