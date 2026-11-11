#include<bits/stdc++.h>
using namespace std;
int a[100000];
int ans;
int n,m;
void dfs(int u,int sum,int k){
	if(u==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=k+1;i<=n;i++){
		dfs(u+1,sum&a[i],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dfs(1,a[i],0);
	cout<<ans;
	return 0;
}
