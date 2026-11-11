#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],vis[200005],ans;
void dfs(long long x,long long st){
	if(st>m){
		ans=max(ans,x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		dfs(x&a[i],st+1);
		vis[i]=0;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(a[i],1);
	}
	cout<<ans;
	return 0;
}
