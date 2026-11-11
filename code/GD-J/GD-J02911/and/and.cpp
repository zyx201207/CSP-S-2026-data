#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
ll ans=0;
void dfs(ll idx,ll x,ll k){
	if(k==m){
		ans=max(ans,x);
		return;
	}
	if(idx>n)return;
	if(x==-1){
		dfs(idx+1,a[idx],k+1);
		dfs(idx+1,x,k);
	}
	else{
		if(x<=ans)return;
		dfs(idx+1,x&a[idx],k+1);
		dfs(idx+1,x,k);
	}
}
void read(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
}
void print(){
	read();
	dfs(1,-1,0);
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	print();
	return 0;
} 
