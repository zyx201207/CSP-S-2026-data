#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int dp[5010][3010];
int last[5010],flag[5010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		memset(flag,0,sizeof(flag));
		if(last[a[i]]!=0){
			for(int j=i+1;j<last[a[i]];j++){
				dp[i][a[j]]=dp[last[a[i]+1]][a[j]]+1;
				flag[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(!flag[j]&&(last[i]!=0||j==a[i]))
				dp[i][j]=dp[i+1][j]+1;
		}	
		last[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<dp[1][i]<<" ";
	}
	return 0;
}
