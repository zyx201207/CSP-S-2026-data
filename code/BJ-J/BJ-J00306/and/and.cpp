#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200050];
bool vis[200050];
void dfs(int x,int g){
	if(g==m){
		//cout<<x<<'\n';
		ans=max(x,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x&a[i],g+1);
			vis[i]=0;
		}
	}
}
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(2147483647,0);
	cout<<ans;
	return 0;
}