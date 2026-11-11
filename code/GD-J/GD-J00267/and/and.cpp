#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int dp[N];
int maxl=INT_MIN;
void dfs(int i,int x,int ans){
//  cout<<ans<<" "<<x<<"\n";
	if(x>=m){
		maxl=max(maxl,ans);
		return ;
	}
	if(i>n)return;
	dfs(i+1,x,ans);
	dfs(i+1,x+1,(int)(ans&a[i]));
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n<=20){
		dfs(1,0,(1>>20)-1);
		cout<<maxl;	
	}
	else {
		dp[0]=(1>>20)-1;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				dp[j]=max(dp[j-1]&a[i],dp[j]);
			}
		}
	//	for(int i=1;i<=m;i++)cout<<dp[i]<<" ";
		cout<<dp[m];
	} 
	return 0;
} 
/*
5 3
31 3 1 15 7
*/
