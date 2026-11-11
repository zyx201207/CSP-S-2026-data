#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans=-1;
void dfs(ll x,ll sum,ll ok){
	if(x==m){
		ans=max(sum,ans);
		return;
	}
	for(ll i=ok+1;i<=n;i++){
		if(x==0&&sum==0&&ok==0) dfs(x+1,a[i],i);
		else dfs(x+1,a[i]&sum,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
