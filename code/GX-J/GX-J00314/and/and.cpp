#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
ll a[200005];
void dfs(ll j,ll k,ll v){
	if(k==m){
		ans=max(ans,v);
		return;
	}
	for(int i=j+1;i<=n;i++){
		dfs(i,k+1,v&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}
