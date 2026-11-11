#include<bits/stdc++.h>
using namespace std;

	int a[200010];
	int t[300010];
	bool dp[200010][3010];
	int cnt[300010];
	int n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,0,sizeof(dp));
	memset(t,0,sizeof(t));
	cin>>n>>m;
	for(int i=1;i<=m;i++)dp[0][i]=0;
	for(int i=1;i<=n;i++)
		cin>>a[n-i+1];
	for(int i=1;i<=n;i++){
		if(t[a[i]]==0){
			t[a[i]]=i;
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[i-1][j];
				if(dp[i][j]==1)cnt[j]++;
			}
			dp[i][a[i]]=1;
			cnt[a[i]]++;
		}else{
			int x=t[a[i]];
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[x][j];
				if(dp[i][j]==1)cnt[j]++;
			}
			t[a[i]]=i;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//			cout<<dp[j]<<" ";
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
//T4
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
