#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n,a[200001],ans=0;
void dfs(int x,int i,int t){
	if(x==0){
		ans=max(ans,t);
		return;
	}
	if(i>n){
		return;
	}
	dfs(x-1,i+1,t&a[i]);
	dfs(x,i+1,t);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[n]>(1<<20)){
		ans=0;
	}
	else if(n>2000&&m!=n-1){
		sort(a+1,a+n+1);
		ans=a[n-m+1];
	}
	else{
		dfs(m,1,(1<<30)-1);
	}
	cout<<ans;
	return 0;
}
