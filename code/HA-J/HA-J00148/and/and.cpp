#include<bits/stdc++.h>
using namespace std;
//dp[n][m];
//dp[n][m]=max(dp[n-1][m],(dp[n-1][m-1]&a[m]));
//µ¹ÍÆ
//dp[m]=max(dp[m],dp[m-1]&a[n]); 
int n,m;
int a[200005];
int dp[200005],answer;
void dfs(int um,int m,int n,int ands,int na[200005],int ai,int a[200005]){
	if(um==m){
		answer=max(answer,ands);
		return;
	}
	if(ai>n){
		return;
	}
	dfs(um,m,n,ands,na,ai+1,a);
	na[++um]=a[ai];
	int yand=ands;
	ands&=a[ai];
	dfs(um,m,n,ands,na,ai+1,a);
	na[um--]=0;
	ands=yand;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(0,m,n,2147483647,dp,1,a);
		cout<<answer<<"\n";
	}
	else{
		if(m==n){
			int andi;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				andi&=a[i];
			}
			cout<<andi;
			return 0;
		}
		for(int i=0;i<=m;i++){
			dp[i]=2147483647;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=min(i,m);j>=1;j--){
				if(dp[j]==2147483647){
					dp[j]=dp[j-1]&a[i];
				}
				else{
					dp[j]=max(dp[j],dp[j-1]&a[i]);
				}
			}
		}
		cout<<dp[m]<<"\n";
	}
	
	return 0;
}
