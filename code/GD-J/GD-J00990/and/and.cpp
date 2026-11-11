#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll n, m, a[200005];
bool vis[200005];
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]&(a[i]+1)){
			return 0;
		}
	}
	return 1;
}
ll all(){
	ll ans=-1;
	for(int i=1;i<=n;i++){
		ans&=a[i];
	}
	return ans;
}
ll dfs(ll I){
	ll maxv=0;
	if(I>m)return -1;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		maxv=max(maxv, dfs(I+1)&a[i]);
		vis[i]=0;
	}
	return maxv;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		cout<<all();
		return 0;
	}
	if(check()){
		cout<<a[n-m+1];
		return 0;
	}
	cout<<dfs(1);
	return 0;
} 
