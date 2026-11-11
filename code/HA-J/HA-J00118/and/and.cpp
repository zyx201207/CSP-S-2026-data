#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+7;
ll n,m,a[N],vis[N],dp[N];
ll ans,mx;
void dfs(int k,ll sum){
	if(k==m){
		ans=max(ans,sum);
		return;
	} 
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			if(k==0) dfs(k+1,a[i]);
			else dfs(k+1,sum&a[i]);
			vis[i]=0;
		}
	}
}
void f2(){
	for(int i=1;i<=n;++i)
		dp[i]=max(dp[i-1],dp[i-1]&a[i]);
	ans=dp[n];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<=20) dfs(0,0);
	else if(m==1) ans=mx;
	else f2();
	cout<<ans;
	return 0;
}
