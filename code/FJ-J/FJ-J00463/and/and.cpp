#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,maxn=-0x3f3f3f3f,a[N],vis[N];
void dfs(int k,int res){
	if(k==m+1){
		maxn=max(maxn,res);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(k+1,res&a[i]);
			vis[i]=0;
		}
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
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		dfs(2,a[i]);
	}
	cout<<maxn;
	return 0;
}
