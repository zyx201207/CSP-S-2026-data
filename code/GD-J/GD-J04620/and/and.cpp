#include<bits/stdc++.h>
using namespace std;
int a[200005],maxn=-1e6;
int n,m;
bool vis[200005];
void dfs(int dep,int ans){
	if(dep>m){
		maxn=max(ans,maxn);
		cout<<maxn<<' ';
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(dep+1,ans&a[i]);
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
	dfs(1,1);
	cout<<maxn;
	return 0;
}
