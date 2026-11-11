#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long sum[200005];
int vis[200005];
int Max=0;
void dfs(int s,int ans){
	if(s>m){
		Max=max(Max,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		} 
		vis[i]=1;
		dfs(s+1,ans&a[i]);
		vis[i]=0;
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		vis[i]=1;
		dfs(2,a[i]);
	}
	cout<<Max;
	return 0;
} 
