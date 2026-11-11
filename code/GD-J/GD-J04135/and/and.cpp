#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=LLONG_MIN;
void dfs(long long l,long long u,long long h){
	if(l>n){
		if(u==m){
			ans=max(ans,h);
		}
		return ;
	}
	if(u==0){
		dfs(l+1,u+1,a[l]);
		dfs(l+1,u,h);
	}
	else {
		dfs(l+1,u+1,h & a[l]);
		dfs(l+1,u,h);
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
