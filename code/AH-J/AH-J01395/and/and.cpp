#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 200005
#define INF 4294967295
ll a[MAXN],dp[MAXN],vis[MAXN]; 
int n,m;  
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);  
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];   
	}   
//	dfs(1,INF);
	for(int i=1;i<=n;i++){
		for(int j=min(i,m);j>=1;j--){ 
		    if(j==0)continue;
		    if(j==1){
		    	dp[1]=max(dp[1],a[i]);
			}else{
				if(i>j)dp[j]=dp[j];
			    dp[j]=max(dp[j],dp[j-1]&a[i]);
			}
			
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<dp[i]<<" ";
//	}
//	cout<<"\n";
	cout<<dp[m]<<"\n"; 
//    cout<<ans<<"\n";
	return 0; 
} 
/*
5 3
31 3 1 15 7
*/
