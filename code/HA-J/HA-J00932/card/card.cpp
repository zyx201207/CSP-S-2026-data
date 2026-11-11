#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int you[500005];
int wei[500005];
int dp[500005];
int zuo[500005];
int zhi[500005];
int ans[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(zhi[a[i]]!=0)zuo[i]=zhi[a[i]];
		zhi[a[i]]=i;
		dp[i]=1;
		ans[a[i]]=1;
	}
	for(int i = n;i>=1;i--){
		if(wei[a[i]]!=0)you[i]=wei[a[i]];
		wei[a[i]]=i;
	}
	
	for(int i = 2;i<=n;i++){
		
		dp[i]+=dp[zuo[i]];
		if(you[i-1]==0)dp[i]+=dp[i-1];
		ans[a[i]]=max(ans[a[i]],dp[i]);
		
	}
	for(int i = 1;i<m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<ans[m];
	
	
	
	
	return 0;
} 
