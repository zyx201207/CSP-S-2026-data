#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],t[200010],maxn=-1;
ll solve(ll x){
	ll sum=t[1];
	for(ll i=2;i<x;i++)sum=sum&t[i];
	return sum;
}
void dfs(ll cur,ll k){
	if(cur==m+1){
		maxn=max(maxn,solve(cur));
		return ;
	}
	for(ll i=k;i<=n;i++){
		t[cur]=a[i];
		dfs(cur+1,i+1);
		t[cur]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	dfs(1,1);
	cout<<maxn;
	return 0;
}
// 15min code + 30min check EXP:50pts
