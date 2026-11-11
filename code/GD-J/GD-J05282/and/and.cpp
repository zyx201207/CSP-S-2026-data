#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m,a[200002],sum=-1e9;
void dfs(ll x,ll ans,ll s){
	if(ans==m){
		sum=max(sum,s);
		return;
	}
	if(x>n)return;
	dfs(x+1,ans+1,s&a[x]);
	dfs(x+1,ans,s);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,8191);
	cout<<sum;
	return 0;
}
