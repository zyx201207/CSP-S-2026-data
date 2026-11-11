#include<bits/stdc++.h>
using namespace std;
int a[200005];
int flag[200005];
int dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	int maxn=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(flag[j]==0){
				if(i-1==0) dp[i-1]=a[j];
				if((dp[i-1]&a[j])>dp[i]){
					dp[i]=(dp[i-1]&a[j]);
					maxn=j;
				}
			}
		}
		flag[maxn]=1;
	}
	cout<<dp[m];
	return 0;
}
