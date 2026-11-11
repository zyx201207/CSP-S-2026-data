#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200001],daan;
void dfs(ll t,ll x,ll p,ll z){
	if(t==m){
		daan=max(daan,x);
		return;
	}
	if(p>=n){
		return;
	}
	if(p!=z){
		dfs(t,x,p+1,z);
		x&=a[p];
		dfs(t+1,x,p+1,z);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		dfs(1,a[i],1,i);
	}
	cout<<daan;
	return 0;
}
