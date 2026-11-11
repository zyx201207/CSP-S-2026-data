#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long dp[200005];
long long n,m,ans=0;
void dfs(long long x,long long y,long long s){
	if(x==m){
		ans=max(ans,s);
	}
	if(y>n)return;
	if(x==0){
		dfs(x+1,y+1,a[y]);
		dfs(x,y+1,s);
	}else{
		dfs(x+1,y+1,s&a[y]);
		dfs(x,y+1,s);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,1);
	cout<<ans;
	return 0;
} 
