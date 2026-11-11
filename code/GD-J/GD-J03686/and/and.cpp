#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll>dp,a;
ll n,k,ans;
void dfs(ll t,ll ii,ll sum){
	if(t==k)ans=max(ans,sum);
	for(ll i=ii;i<n;i++)dfs(t+1,i+1,sum&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	a.assign(n+5,0);
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<n-k+1;i++){
		dfs(1,i+1,a[i]);
	}
	cout<<ans;
	return 0;
}

