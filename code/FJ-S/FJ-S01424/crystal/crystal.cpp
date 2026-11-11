#include<bits/stdc++.h>
using namespace std;
int n,Max=0;
long long m;
long long num[500005];
long long dp[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>num[i];
	sort(num+1,num+n+1);
	for(int i=1;i<n;i++){
		memset(dp,0,sizeof(dp));
		int ans=1;
		num[i]=num[i+1]-num[i];
		for(int j=2;j<=i+1;j++){
			dp[j]=num[i-j+2]+dp[j-1]*2-dp[j-2];
			if(dp[j]<=m) ans++;
			else break;	
			//cout<<dp[j]<<" ";
		}
		//cout<<endl;
		Max=max(ans,Max);
	}
	cout<<Max<<endl;
	return 0;
}
