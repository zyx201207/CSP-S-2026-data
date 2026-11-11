#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005]; 
int ans,vis[200005];

void dfs(int x,int y){
	if(y==m){
		ans=max(x,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		if(x==0)dfs(a[i],y+1);
		else dfs(x & a[i],y+1);
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
	dfs(0,0);
	cout<<ans;
	return 0;
} 
