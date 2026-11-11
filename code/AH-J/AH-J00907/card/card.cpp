#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int dp[2000005];
bool used[2000005];
int maxx=-1;
void dfs(int pos,int k){
	if(pos>m){
		maxx=max(maxx,dp[pos]);
		return;
	}
	for(int v=k;v<=n;v++){
		dp[pos]=a[v];
		dfs(pos+1,v+1);		
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=pow(2,30)-1;
	}
	dfs(1,1);
	cout<<maxx;
	return 0;
}