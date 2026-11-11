#include<bits/stdc++.h>
using namespace std;
long long a[500005],dp[500005];
int n;
unsigned long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[j]=max(dp[j],dp[j-a[i]]+1);
		}
	} 
	cout<<dp[n];
	return 0;
} 
