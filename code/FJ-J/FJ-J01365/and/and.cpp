#include<bits/stdc++.h>
typedef  long long  ll;
using namespace std;
ll n,m,a[200005],dp[2000005],ans=0;
void dfs(ll c,ll b,ll s){
	if(b==m)ans=max(s,ans);
	if(b>m||c>n)return ;
	if(b==0){
		dfs(c+1,b,s); 
		dfs(c+1,b+1,a[c]);
	}
	else {
	    dfs(c+1,b+1,s&a[c]);
	    dfs(c+1,b,s);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
